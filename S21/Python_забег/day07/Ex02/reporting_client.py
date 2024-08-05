import grpc
import spaceship_pb2
import spaceship_pb2_grpc
import json
from models import Spaceship as SpaceshipModel
from pydantic import ValidationError
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from orm_models import Base, Spaceship, Officer

DATABASE_URL = "postgresql://user:password@localhost/spaceshipdb"

engine = create_engine(DATABASE_URL)
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
session = Session()


def run(coordinates):
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = spaceship_pb2_grpc.GetSpaceshipsStub(channel)
        request = spaceship_pb2.Coordinates(coordinates=coordinates)
        response = stub.Report(request)
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
                    officers=[
                        {
                            "first_name": officer.first_name,
                            "last_name": officer.last_name,
                            "rank": officer.rank,
                        }
                        for officer in spaceship.officers
                    ],
                )
                # Добавляем модель в базу данных
                db_spaceship = Spaceship(
                    alignment=ship_model.alignment,
                    name=ship_model.name,
                    class_=ship_model.class_,
                    length=ship_model.length,
                    crew_size=ship_model.crew_size,
                    armed=ship_model.armed,
                )
                session.add(db_spaceship)
                for officer in ship_model.officers:
                    db_officer = Officer(
                        first_name=officer["first_name"],
                        last_name=officer["last_name"],
                        rank=officer["rank"],
                        spaceship=db_spaceship,
                    )
                    session.add(db_officer)
                session.commit()
            except ValidationError as e:
                print(f"Pydantic validation error: {e}")
                session.rollback()
            except Exception as e:
                print(f"Database error: {e}")
                session.rollback()


def list_traitors():
    traitors = (
        session.query(Officer)
        .join(Spaceship)
        .filter(Spaceship.alignment == "Enemy", Officer.spaceship.has(alignment="Ally"))
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


if __name__ == "__main__":
    import sys

    command = sys.argv[1]
    if command == "scan":
        coordinates = sys.argv[2]
        run(coordinates)
    elif command == "list_traitors":
        list_traitors()
