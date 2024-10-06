#ifndef FLAT_MAP_H
#define FLAT_MAP_H

#include "vector.cpp"
#include <string>
#include <stdexcept>

typedef std::string Key;
struct Value {
    unsigned age;
    unsigned weight;
};

struct Pair {
    Key key;
    Value value;
};

class FlatMap {
public:
    // Constructor
    FlatMap();

    // Destructor
    ~FlatMap();

    // Copy Constructor
    FlatMap(const FlatMap& b);

    // Move Constructor
    FlatMap(FlatMap&& b);

    // Swap method
    void swap(FlatMap& b);

    // Copy Assignment Operator
    FlatMap& operator=(const FlatMap& b);

    // Move Assignment Operator
    FlatMap& operator=(FlatMap&& b);

    // Clear the container
    void clear();

    // Erase an element by key
    bool erase(const Key& k);

    // Insert a key-value pair
    bool insert(const Key& k, const Value& v);

    // Check if a key exists
    bool contains(const Key& k) const;

    // Non-const access to value by key (creates default value if key does not exist)
    Value& operator[](const Key& k);

    // Const access to value by key (throws exception if key does not exist)
    Value& at(const Key& k);
    const Value& at(const Key& k) const;

    size_t size() const;

    bool empty() const;

    friend bool operator==(const FlatMap& a, const FlatMap& b);

    friend bool operator!=(const FlatMap& a, const FlatMap& b);

private:
    Vector<Pair> data;

    // Helper function to find an element by key
    size_t findIndex(const Key& k) const {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].key == k) {
                return i;
            }
        }
        return data.size(); // Return size if key not found
    }

    // Helper function to find an element by key (non-const)
    size_t findIndex(const Key& k) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i].key == k) {
                return i;
            }
        }
        return data.size(); // Return size if key not found
    }
};

#endif // FLAT_MAP_H
