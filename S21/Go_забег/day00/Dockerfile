FROM golang:1.20-buster

WORKDIR /app

COPY . /app

RUN apt-get update && \
    apt-get install -y make && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

CMD ["bash", "-c", "make"]
