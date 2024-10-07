#ifndef FLAT_MAP_H
#define FLAT_MAP_H

#include <string>
#include <stdexcept>
#include "vector.h"

typedef std::string Key;
struct Value {
    unsigned age;
    unsigned weight;
};

class FlatMap {
public:
    //Default constructor./
    FlatMap();

    // Destructor.
    ~FlatMap();

    //Copy constructor b The FlatMap to copy from.
    FlatMap(const FlatMap& b);

    // Move constructor param b The FlatMap to move from.
    FlatMap(FlatMap&& b) noexcept;

    //param b The FlatMap to swap with.
    void swap(FlatMap& b);

    //Copy assignment operator param b The FlatMap to assign from. return A reference to this FlatMap.
    FlatMap& operator=(const FlatMap& b);

    //Move assignment operator param b The FlatMap to move from.return A reference to this FlatMap.
    FlatMap& operator=(FlatMap&& b) noexcept;

    //Clears the FlatMap.
    void clear();

    //Erases an element by key. param k The key to erase. return True if the key was found and erased, false otherwise.
    bool erase(const Key& k);

    //Inserts a new key-value pair. param k The key to insert. param v The value to insert. return True if the insertion was successful, false if the key already exists.
    bool insert(const Key& k, const Value& v);

    //Checks if a key exists. param k The key to check. return True if the key exists, false otherwise.
    bool contains(const Key& k) const;

    // brief Accesses the value associated with a key. If the key does not exist, a default-constructed Value is inserted. param k The key to access. return A reference to the associated Value.
     
    Value& operator[](const Key& k);

    //brief Accesses the value associated with a key. Throws an exception if the key does not exist. param k The key to access. return A reference to the associated Value.
    Value& at(const Key& k);

    //Accesses the value associated with a key (const version). Throws an exception if the key does not exist.param k The key to access. return A const reference to the associated Value.
    const Value& at(const Key& k) const;

    // brief Returns the size of the FlatMap. return The number of elements in the FlatMap.
    size_t size() const;

    //brief Checks if the FlatMap is empty. return True if the FlatMap is empty, false otherwise.
    bool empty() const;

    //Equality operator. param a The first FlatMap to compare. param b The second FlatMap to compare. return True if the FlatMaps are equal, false otherwise.
    friend bool operator==(const FlatMap& a, const FlatMap& b);

    //Inequality operator. param a The first FlatMap to compare. param b The second FlatMap to compare. return True if the FlatMaps are not equal, false otherwise.
    friend bool operator!=(const FlatMap& a, const FlatMap& b);

private:
    Vector<std::pair<Key, Value>> data;
};

#endif // FLAT_MAP_H
