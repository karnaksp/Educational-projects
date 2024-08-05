import grpc
from concurrent import futures
import random
import spaceship_pb2
import spaceship_pb2_grpc
import config


class SpaceshipServicer(spaceship_pb2_grpc.GetSpaceshipsServicer):
    def Report(self, request, context):
        for _ in range(random.randint(1, 10)):
            alignment = random.choice(config.ALIGNMENTS)
            alignment_enum = getattr(spaceship_pb2, alignment)
            name = random.choice(config.NAMES)
            class_name = random.choice(config.CLASSES)
            class_enum = getattr(spaceship_pb2, class_name)
            length = random.uniform(*config.LENGTH_RANGE)
            crew_size = random.randint(*config.CREW_SIZE_RANGE)
            armed = random.choice(config.ARMED_STATUS)
            if alignment == config.ALIGNMENTS[1]:
                count_range = config.OFFICER_COUNT_RANGE
            else:
                count_range = (1, config.OFFICER_COUNT_RANGE[1])
            officers = [
                spaceship_pb2.Officer(
                    first_name=officer["first_name"],
                    last_name=officer["last_name"],
                    rank=officer["rank"],
                )
                for officer in random.sample(
                    config.OFFICER_NAMES,
                    random.randint(*count_range),
                )
            ]
            spaceship = spaceship_pb2.Spaceship(
                alignment=alignment_enum,
                name=name,
                class_=class_enum,
                length=length,
                crew_size=crew_size,
                armed=armed,
                officers=officers,
            )
            yield spaceship


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    spaceship_pb2_grpc.add_GetSpaceshipsServicer_to_server(SpaceshipServicer(), server)
    server.add_insecure_port("[::]:50051")
    server.start()
    server.wait_for_termination()


if __name__ == "__main__":
    serve()
