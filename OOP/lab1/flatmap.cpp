#include "flatmap.h"
#include <algorithm>
#include <utility>

// Default constructor: Initializes an empty FlatMap object.
FlatMap::FlatMap() = default;

// Destructor: Releases any resources held by the FlatMap object.
FlatMap::~FlatMap() = default;

// Copy constructor: Creates a new FlatMap object by copying the contents of another FlatMap object.
FlatMap::FlatMap(const FlatMap& b) : data(b.data) {}

// Move constructor: Creates a new FlatMap object by moving the contents of another FlatMap object.
FlatMap::FlatMap(FlatMap&& b) noexcept : data(std::move(b.data)) {}

// Swap function: Exchanges the contents of this FlatMap object with another FlatMap object.
void FlatMap::swap(FlatMap& b) {
    // Swaps the underlying data containers.
    data.swap(b.data);
}

// Copy assignment operator: Assigns the contents of another FlatMap object to this object.
FlatMap& FlatMap::operator=(const FlatMap& b) {
    if (this != &b) {
        // Copies the data from the source FlatMap object.
        data = b.data;
    }
    return *this;
}

// Move assignment operator: Assigns the contents of another FlatMap object to this object, moving the data.
FlatMap& FlatMap::operator=(FlatMap&& b) noexcept {
    if (this != &b) {
        // Moves the data from the source FlatMap object.
        data = std::move(b.data);
    }
    return *this;
}

// Clear function: Removes all key-value pairs from the FlatMap.
void FlatMap::clear() {
    // Clears the underlying data container.
    data.clear();
}

// Erase function: Removes the key-value pair associated with the specified key.
bool FlatMap::erase(const Key& k) {
    // Iterates through the data to find the key.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            // Erases the key-value pair if found.
            data.erase(data.begin() + i);
            return true;
        }
    }
    return false; // Key not found
}

// Insert function: Inserts a new key-value pair into the FlatMap.
bool FlatMap::insert(const Key& k, const Value& v) {
    // Checks if the key already exists.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return false; // Key already exists
        }
    }
    // Inserts the new key-value pair.
    data.push_back({k, v});
    return true;
}

// Contains function: Checks if a key exists in the FlatMap.
bool FlatMap::contains(const Key& k) const {
    // Iterates through the data to find the key.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return true; // Key found
        }
    }
    return false; // Key not found
}

// Operator[]: Accesses the value associated with a key. If the key does not exist, a default-constructed Value is inserted.
Value& FlatMap::operator[](const Key& k) {
    // Iterates through the data to find the key.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second; // Key found, returns the associated value
        }
    }
    // Inserts a default-constructed Value if the key is not found.
    data.push_back({k, Value()});
    return data.back().second;
}

// At function (non-const): Accesses the value associated with a key. Throws an exception if the key does not exist.
Value& FlatMap::at(const Key& k) {
    // Iterates through the data to find the key.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second; // Key found, returns the associated value
        }
    }
    // Throws an exception if the key is not found.
    throw std::runtime_error("Key not found");
}

// At function (const): Accesses the value associated with a key. Throws an exception if the key does not exist.
const Value& FlatMap::at(const Key& k) const {
    // Iterates through the data to find the key.
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].first == k) {
            return data[i].second; // Key found, returns the associated value
        }
    }
    // Throws an exception if the key is not found.
    throw std::runtime_error("Key not found");
}

// Size function: Returns the number of elements in the FlatMap.
size_t FlatMap::size() const {
    // Returns the size of the underlying data container.
    return data.size();
}

// Empty function: Checks if the FlatMap is empty.
bool FlatMap::empty() const {
    // Returns whether the underlying data container is empty.
    return data.empty();
}

// Equality operator: Compares two FlatMap objects for equality.
bool operator==(const FlatMap& a, const FlatMap& b) {
    // Compares the underlying data containers.
    return a.data == b.data;
}

// Inequality operator: Compares two FlatMap objects for inequality.
bool operator!=(const FlatMap& a, const FlatMap& b) {
    // Returns the opposite of the equality comparison.
    return !(a == b);
}
