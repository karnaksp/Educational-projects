import grpc
import argparse
import sys
import spaceship_pb2
import spaceship_pb2_grpc
import logging
from models import Spaceship
from pydantic import ValidationError

logging.basicConfig(
    filename="spaceship_errors.log",
    level=logging.ERROR,
    format="%(asctime)s - %(levelname)s - %(message)s",
)


def run(coordinate):
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = spaceship_pb2_grpc.GetSpaceshipsStub(channel)
        request = spaceship_pb2.Coordinates(coordinate=coordinate)
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
                print(ship.model_dump_json())
            except ValidationError as e:
                logging.error(f"Validation error: {e}")
                continue


def print_usage():
    print("Usage:")
    print("  python script.py <coordinate1> [<coordinate2> ...]")


def validate_coordinates(coords) -> bool:
    if len(coords) < 2:
        return False
    try:
        for coord in coords:
            float(coord)
    except ValueError:
        return False
    return True


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Spaceship reporting client.")
    parser.add_argument(
        "coordinates",
        nargs="+",
        help="Coordinates as space-separated values. Example: 17 45 40.0409 -29 00 28.118",
    )

    args = parser.parse_args()

    if not validate_coordinates(args.coordinates):
        print_usage()
        sys.exit(1)

    run(args.coordinates[0])
