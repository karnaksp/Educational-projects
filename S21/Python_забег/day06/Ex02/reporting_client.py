import grpc
import argparse
import spaceship_pb2
import spaceship_pb2_grpc
import logging
import sys
from sqlalchemy import create_engine, select, func
from sqlalchemy.orm import sessionmaker
from models import SpaceshipORM, OfficerORM, spaceship_officers  # ORM models
from models_dantic import Spaceship  # Pydantic model
from pydantic import ValidationError

logging.basicConfig(
    filename="spaceship_errors.log",
    level=logging.ERROR,
    format="%(asctime)s - %(levelname)s - %(message)s",
)

DATABASE_URL = "postgresql://spaceship_user:12345678@postgres:5432/spaceship_db"

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)


def convert_to_orm(ship_model: Spaceship, session):
    """
    Converts a Spaceship Pydantic model to an ORM model and saves it to the database.
    """
    existing_ship = session.execute(
        select(SpaceshipORM).where(SpaceshipORM.name == ship_model.name)
    ).scalar_one_or_none()
    if existing_ship:
        existing_officer_ids = {officer.id for officer in existing_ship.officers}
        new_officer_ids = set()
        for officer_data in ship_model.officers:
            officer = session.execute(
                select(OfficerORM).where(
                    OfficerORM.first_name == officer_data.first_name,
                    OfficerORM.last_name == officer_data.last_name,
                    OfficerORM.rank == officer_data.rank,
                )
            ).scalar_one_or_none()
            if officer:
                new_officer_ids.add(officer.id)
        if existing_officer_ids == new_officer_ids:
            print(f"Spaceship with name {ship_model.name} already exists.")
            return

    new_spaceship = SpaceshipORM(
        alignment=ship_model.alignment,
        name=ship_model.name,
        class_=ship_model.class_,
        length=ship_model.length,
        crew_size=ship_model.crew_size,
        armed=ship_model.armed,
        hostile=ship_model.hostile,
        speed=None,
    )
    for officer_data in ship_model.officers:
        officer = session.execute(
            select(OfficerORM).where(
                OfficerORM.first_name == officer_data.first_name,
                OfficerORM.last_name == officer_data.last_name,
                OfficerORM.rank == officer_data.rank,
            )
        ).scalar_one_or_none()

        if not officer:
            officer = OfficerORM(
                first_name=officer_data.first_name,
                last_name=officer_data.last_name,
                rank=officer_data.rank,
            )
            session.add(officer)

        new_spaceship.officers.append(officer)
    session.add(new_spaceship)
    session.commit()
    print(f"Added spaceship: {new_spaceship.name}")


def run(coordinate):
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = spaceship_pb2_grpc.GetSpaceshipsStub(channel)
        request = spaceship_pb2.Coordinates(coordinate=coordinate)
        have_spaceship = False
        session = SessionLocal()
        try:
            while not have_spaceship:
                response = stub.Report(request)
                for spaceship in response:
                    try:
                        ship_model = Spaceship(
                            alignment=(
                                "Ally"
                                if spaceship.alignment == spaceship_pb2.ALLY
                                else "Enemy"
                            ),
                            name=spaceship.name,
                            class_=spaceship_pb2.Class.Name(spaceship.class_),
                            length=spaceship.length,
                            crew_size=spaceship.crew_size,
                            armed=spaceship.armed,
                            hostile=spaceship.hostile,
                            officers=[
                                {
                                    "first_name": officer.first_name,
                                    "last_name": officer.last_name,
                                    "rank": officer.rank,
                                }
                                for officer in spaceship.officers
                            ],
                        )
                        convert_to_orm(ship_model, session)
                        have_spaceship = True
                    except ValidationError as e:
                        logging.error(f"Validation error: {e}")
                        continue
        finally:
            session.close()


def list_traitors():
    session = SessionLocal()
    try:
        traitors = (
            session.query(OfficerORM)
            .join(spaceship_officers)
            .group_by(OfficerORM.id)
            .having(func.count(spaceship_officers.c.spaceship_id) > 1)
            .all()
        )
        print("List of traitors!!!\n")
        for traitor in traitors:
            print(f"{traitor.first_name} {traitor.last_name}: {traitor.rank}")
        print("\n")
    finally:
        session.close()


def print_usage():
    print("Usage:")
    print("  python script.py scan <coordinate1> [<coordinate2> ...]")
    print("  python script.py list_traitors")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Spaceship reporting client.")
    parser.add_argument(
        "command", choices=["scan", "list_traitors"], help="Command to execute"
    )
    parser.add_argument(
        "coordinates", nargs="*", help="Coordinates for the scan command"
    )

    args = parser.parse_args()

    if args.command == "scan":
        if not args.coordinates:
            print("Error: Coordinates are required for the 'scan' command.")
            print_usage()
            sys.exit(1)
        run(args.coordinates[0])

    elif args.command == "list_traitors":
        if args.coordinates:
            print(
                "Error: The 'list_traitors' command does not take any additional arguments."
            )
            print_usage()
            sys.exit(1)
        list_traitors()
