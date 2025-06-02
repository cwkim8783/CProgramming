FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get install -y \
        gcc g++ gdb           \
        vim nano              \
        tzdata                \
    && apt-get clean && rm -rf /var/lib/apt/lists/*
