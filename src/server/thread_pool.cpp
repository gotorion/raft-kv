#include "thread_pool.h"

#include <utility>
namespace server {
ThreadPool::ThreadPool(std::size_t threadNum, std::size_t queueSize)
    : taskPool_(queueSize) {
  threads_.reserve(threadNum);
  for (std::size_t count = 0; count < threadNum; ++count) {
    std::thread thread([this]() { ThreadFunc(); });
    threads_.push_back(std::move(thread));
  }
}

ThreadPool::~ThreadPool() {}

void ThreadPool::Submit(Task&& task) {
  if (task) {
    taskPool_.PushBack(std::move(task));
  }
}

void ThreadPool::ThreadFunc() {
  while (!taskPool_.Empty()) {
    Task&& task = taskPool_.Pop();
    if (task) {
      task();
    } else {
      // do what?
    }
  }
}

}  // namespace server