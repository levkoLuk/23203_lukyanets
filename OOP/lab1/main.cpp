#include <algorithm>
#include <string>
#include <stdexcept>
#include <vector>

typedef std::string Key;
struct Value {
  unsigned age;
  unsigned weight;
};

class FlatMap {
public:
  // Default constructor
  FlatMap() = default;

  // Destructor
  ~FlatMap() = default;

  // Copy constructor
  FlatMap(const FlatMap& b) = default;

  // Move constructor
  FlatMap(FlatMap&& b) = default;

  // Swap method
  void swap(FlatMap& b) {
    std::swap(data_, b.data_);
  }

  // Copy assignment operator
  FlatMap& operator=(const FlatMap& b) {
    if (this != &b) {
      data_ = b.data_;
    }
    return *this;
  }

  // Move assignment operator
  FlatMap& operator=(FlatMap&& b) {
    if (this != &b) {
      data_ = std::move(b.data_);
    }
    return *this;
  }

  // Clear the container
  void clear() {
    data_.clear();
  }

  // Erase an element by key
  bool erase(const Key& k) {
    auto it = std::lower_bound(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
    if (it != data_.end() && it->first == k) {
      data_.erase(it);
      return true;
    }
    return false;
  }

  // Insert a new element
  bool insert(const Key& k, const Value& v) {
    auto it = std::lower_bound(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
    if (it != data_.end() && it->first == k) {
      return false; // Key already exists
    }
    data_.insert(it, {k, v});
    return true;
  }

  // Check if a key exists
  bool contains(const Key& k) const {
    return std::binary_search(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
  }

  // Non-safe operator[] to get or insert a value
  Value& operator[](const Key& k) {
    auto it = std::lower_bound(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
    if (it != data_.end() && it->first == k) {
      return it->second;
    }
    data_.insert(it, {k, Value{}});
    return data_.back().second;
  }

  // Safe at() method to get a value, throws if key does not exist
  Value& at(const Key& k) {
    auto it = std::lower_bound(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
    if (it != data_.end() && it->first == k) {
      return it->second;
    }
    throw std::out_of_range("Key not found");
  }

  const Value& at(const Key& k) const {
    auto it = std::lower_bound(data_.begin(), data_.end(), k, [](const auto& pair, const Key& key) {
      return pair.first < key;
    });
    if (it != data_.end() && it->first == k) {
      return it->second;
    }
    throw std::out_of_range("Key not found");
  }

  // Size of the container
  size_t size() const {
    return data_.size();
  }

  // Check if the container is empty
  bool empty() const {
    return data_.empty();
  }

  friend bool operator==(const FlatMap& a, const FlatMap& b) {
    return a.data_ == b.data_;
  }

  friend bool operator!=(const FlatMap& a, const FlatMap& b) {
    return !(a == b);
  }

private:
  std::vector<std::pair<Key, Value>> data_;
};
