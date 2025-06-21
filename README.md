# raft-kv

This project is just a learning project for Raft consensus algorithm and KV store. I do not want to implement all the details, so I just use lots of libraries to help me implement the project. The project is not production ready, but it can be used for learning and testing purposes.

## Usage
### Use protobuf

```bash
sudo pacman -S protobuf
sudo pacman -S protobuf-c # cpp support
protoc -cpp_out=. message.proto
```

### Use cmake

```bash
cmake -B build -G Ninja
cmake --build build --parallel 16
```