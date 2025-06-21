#pragma once
#include <cstddef>
#include <functional>
#include <thread>
#include <vector>

#include "locked_queue.hpp"
namespace server {
class ThreadPool {
 public:
  using Task = std::function<void()>;

  ThreadPool(std::size_t threadNum, std::size_t queueSize);
  ~ThreadPool();

  void Submit(Task&& task);

 private:
  void ThreadFunc();

  std::vector<std::thread> threads_;
  LockedQueue<Task> taskPool_;
  std::atomic<bool> exit_{false};
};
}  // namespace server