#include "net.h"

#include <sys/socket.h>
#include <unistd.h>

#include <cstdio>

namespace server {
Socket::Socket() : fd_(::socket(AF_INET, SOCK_STREAM, 0)) {
  if (this->fd_ < 0) {
    perror("socket create error");
  }
}

Socket::~Socket() { ::close(this->fd_); }

}  // namespace server