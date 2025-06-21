#pragma once
#include <string>

#include "absl/status/status.h"

namespace db {

using absl::Status;

// define db engine interface for storage
class DbEngine {
 public:
  using KeyType = std::string;  // KeyType & Value Type must can be ser & deser
  using ValueType = std::string;
  DbEngine(DbEngine&&) = delete;
  DbEngine(DbEngine const&) = delete;
  DbEngine& operator=(DbEngine const&) = delete;
  DbEngine& operator=(DbEngine&&) = delete;
  virtual ~DbEngine() = default;

  virtual Status Set(KeyType const& key, ValueType const& value) = 0;
  virtual Status Get(KeyType const& key, ValueType& value) = 0;
  virtual Status Delete(KeyType const& key) = 0;
};

}  // namespace db