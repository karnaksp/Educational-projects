import grpc
import spaceship_pb2
import spaceship_pb2_grpc
import json
from models import Spaceship
from pydantic import ValidationError


def run(coordinate1, coordinate2):
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = spaceship_pb2_grpc.GetSpaceshipsStub(channel)
        request = spaceship_pb2.Coordinates(
            coordinate1=coordinate1, coordinate2=coordinate2
        )
        response = stub.Report(request)
        for spaceship in response:
            try:
                ship = Spaceship(
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
                print(ship.model_dump_json())
            except ValidationError as e:
                print(f"Validation error: {e}")


if __name__ == "__main__":
    import sys

    coordinate1 = sys.argv[1]
    coordinate2 = sys.argv[2]
    run(coordinate1, coordinate2)
