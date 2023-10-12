FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y && apt-get install -y \
    g++ \
    cmake \
    make \
    libboost-system-dev

WORKDIR /app

COPY . /app

RUN cmake .
RUN make

EXPOSE 8080

CMD ["./task2"]
