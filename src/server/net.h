#pragma once
namespace server {
class Socket {
 public:
  Socket();
  explicit Socket(int sockFd);
  ~Socket();

 private:
  int fd_{-1};
};

class NetAddress {
 public:
};

class Connection {
 public:
  virtual ~Connection() = default;
};

}  // namespace server