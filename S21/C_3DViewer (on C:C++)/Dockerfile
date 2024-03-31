FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y qtcreator qtbase5-dev qt5-qmake && \
    apt-get install -y check libsubunit-dev && \
    apt-get install -y valgrind lcov gcc g++

WORKDIR /app

COPY ./src /app
COPY ./misc /app/misc/

RUN make VERBOSE=1

CMD ["cp", "/app/frontend/3DViewer-v1.0/s21_3Dviewer_v1", "/output/"]
