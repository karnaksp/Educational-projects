import grpc
import spaceship_pb2
import spaceship_pb2_grpc
import json
import logging
import sys
import os
from sqlalchemy import create_engine, select
from sqlalchemy.orm import sessionmaker
from models import SpaceshipORM, OfficerORM, Base  # ORM models

src_path = os.path.abspath(os.path.join(os.getcwd(), "..", "Ex01"))
sys.path.append(src_path)
from models import Spaceship as SpaceshipModel  # Pydantic model
from pydantic import ValidationError

logging.basicConfig(
    filename="spaceship_errors.log",
    level=logging.ERROR,
    format="%(asctime)s - %(levelname)s - %(message)s",
)

DATABASE_URL = "postgresql+psycopg2://spaceship_user:12345678@localhost/spaceship_db"
engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)


def convert_to_orm(ship_model: SpaceshipModel, session):
    """
    Converts a Spaceship Pydantic model to an ORM model and saves it to the database.
    """
    existing_ship = session.execute(
        select(SpaceshipORM).where(SpaceshipORM.name == ship_model.name)
    ).scalar_one_or_none()

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
    existing_ship = session.execute(
        select(SpaceshipORM).where(SpaceshipORM.name == ship_model.name)
    ).scalar_one_or_none()
    existing_officers = session.execute(
        select(SpaceshipORM).where(SpaceshipORM.officers == ship_model.officers)
    ).scalar_one_or_none()
    if not existing_ship and not existing_officers:
        for officer_data in ship_model.officers:
            officer = session.execute(
                select(OfficerORM).where(
                    OfficerORM.first_name == officer_data["first_name"],
                    OfficerORM.last_name == officer_data["last_name"],
                    OfficerORM.rank == officer_data["rank"],
                )
            ).scalar_one_or_none()

            if not officer:
                officer = OfficerORM(
                    first_name=officer_data["first_name"],
                    last_name=officer_data["last_name"],
                    rank=officer_data["rank"],
                )
                session.add(officer)
            new_spaceship.officers.append(officer)
            session.add(new_spaceship)
            print(f"Added spaceship: {new_spaceship}")
        session.commit()


def run(coordinate1, coordinate2):
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = spaceship_pb2_grpc.GetSpaceshipsStub(channel)
        request = spaceship_pb2.Coordinates(
            coordinate1=coordinate1, coordinate2=coordinate2
        )
        response = stub.Report(request)

        session = SessionLocal()
        for spaceship in response:
            try:
                ship_model = SpaceshipModel(
                    alignment=(
                        "Ally" if spaceship.alignment == spaceship_pb2.ALLY else "Enemy"
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
            .join(SpaceshipORM)
            .filter(
                SpaceshipORM.alignment == "Enemy",
                OfficerORM.spaceship.has(alignment="Ally"),
            )
            .all()
        )
        for traitor in traitors:
            print(
                json.dumps(
                    {
                        "first_name": traitor.first_name,
                        "last_name": traitor.last_name,
                        "rank": traitor.rank,
                    }
                )
            )
    finally:
        session.close()

if __name__ == "__main__":
    command = sys.argv[1]
    if command == "scan":
        coordinate1, coordinate2 = sys.argv[2], sys.argv[3]
        run(coordinate1, coordinate2)
    elif command == "list_traitors":
        list_traitors()
