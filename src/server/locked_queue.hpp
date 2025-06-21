#pragma once

#include <condition_variable>
#include <cstddef>
#include <queue>
#include <shared_mutex>
#include <type_traits>
#include <utility>

namespace server {
template <typename T>
class LockedQueue {
  static_assert(std::is_move_assignable_v<T> && std::is_move_constructible_v<T>,
                "T must be movable");

 public:
  explicit LockedQueue(std::size_t maxSize) : maxSize_(maxSize) {}
  ~LockedQueue() {}

  LockedQueue(LockedQueue const&) = delete;
  LockedQueue(LockedQueue&&) = delete;
  LockedQueue& operator=(LockedQueue const&) = delete;
  LockedQueue& operator=(LockedQueue&&) = delete;

  void PushBack(T&& elem) {
    std::unique_lock writeLock(rwMutex_);
    queue_.push(std::forward(elem));
    notEmptyCv_.notify_all();
  }

  T&& Pop() {
    std::unique_lock writeLock(rwMutex_);
    T elem = std::move(queue_.front());
    queue_.pop();
    notFullCv_.notify_all();
    return elem;
  }

  [[nodiscard]] bool Empty() const {
    std::shared_lock lock(rwMutex_);
    return queue_.empty();
  }

  [[nodiscard]] bool Full() const {
    std::shared_lock lock(rwMutex_);
    return queue_.size() == maxSize_;
  }

 private:
  std::size_t maxSize_{100};
  std::queue<T> queue_{};
  // for multi threaw
  std::shared_mutex rwMutex_;
  std::condition_variable notEmptyCv_;
  std::condition_variable notFullCv_;
};
}  // namespace server