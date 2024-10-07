#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;         // Pointer to the underlying array
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated memory

public:
    // Default constructor
    Vector() : size(0), capacity(2), data(new T[capacity]) {}

    // Constructor with initial size
    explicit Vector(size_t initialSize) : size(initialSize), capacity(initialSize * 2), data(new T[capacity]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = T();
        }
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size), capacity(other.capacity), data(new T[capacity]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Move constructor
    Vector(Vector&& other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = other.data;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Reserve additional memory
    void reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }

    // Resize the vector
    void resize(size_t newSize, const T& value = T()) {
        if (newSize > size) {
            if (newSize > capacity) {
                reserve(newSize * 2);
            }
            for (size_t i = size; i < newSize; ++i) {
                data[i] = value;
            }
        } else if (newSize < size) {
            size = newSize;
        }
        size = newSize;
    }

    // Push back an element
    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity * 2);
        }
        data[size++] = value;
    }

    // Pop back an element
    void pop_back() {
        if (!empty()) {
            --size;
        }
    }

    // Clear the vector
    void clear() {
        size = 0;
    }

    // Access an element (non-const version)
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::runtime_error("Index out of range");
        }
        return data[index];
    }

    // Access an element (const version)
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::runtime_error("Index out of range");
        }
        return data[index];
    }

    // Access an element safely
    T& at(size_t index) {
        if (index >= size) {
            throw std::runtime_error("Index out of range");
        }
        return data[index];
    }

    // Access an element safely (const version)
    const T& at(size_t index) const {
        if (index >= size) {
            throw std::runtime_error("Index out of range");
        }
        return data[index];
    }

    // Get the current size
    size_t getSize() const {
        return size;
    }

    // Check if the vector is empty
    bool empty() const {
        return size == 0;
    }

    // Get the current capacity
    size_t getCapacity() const {
        return capacity;
    }
};

#endif // VECTOR_H
