FROM python:3.10-slim

WORKDIR /app

COPY . /app

RUN python3 -m pip install --upgrade pip

RUN apt-get update && \
    apt-get install -y make && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN make cat && \
    make install_dep && \
    make install_req

CMD ["bash", "-c", "make"]
