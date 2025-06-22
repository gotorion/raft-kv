FROM ubuntu:22.04
LABEL maintainer="Junhui Li"
# Install dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    cmake \
    ninja-build \
    libprotobuf-dev \
    libprotobuf-c-dev \
    protobuf-compiler \
    clangd \
    clang-format 
WORKDIR /app
# Clone the repository
COPY . /app
RUN git submodule update --init --recursive
# Build the project

RUN [ "protoc", "-I=src/proto", "--cpp_out=src/proto", "src/proto/message.proto" ]
RUN [ "rm", "-rf", "build" ]
RUN [ "cmake", "-B", "build", "-G", "Ninja" ]
RUN [ "cmake", "--build", "build" ]
