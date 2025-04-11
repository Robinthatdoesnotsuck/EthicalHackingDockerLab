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
    file \
    language-pack-en

RUN bash -c "$(wget https://gef.blah.cat/sh -O -)"

WORKDIR /binary_analysis

RUN wget https://pwnable.tw/static/chall/start

RUN chmod u+x start

COPY ./bin .
COPY ./vuln_fd.c .