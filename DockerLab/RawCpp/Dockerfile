FROM ubuntu:24.04

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget \
    curl \
    ca-certificates \
    python3 \
    file

RUN bash -c "$(wget https://gef.blah.cat/sh -O -)"

WORKDIR /bin

COPY ./bin .