#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

#define INITIAL_VEC_CAPACITY 4

template <typename T>
class Vector {
public:
    Vector() : ptr(nullptr), currentAmount(0), allocatedAmount(0) {
        ptr = new T[INITIAL_VEC_CAPACITY];
        if (ptr == nullptr) {
            throw std::runtime_error("Memory allocation failed");
        }
        allocatedAmount = INITIAL_VEC_CAPACITY;
    }
    Vector(const Vector& other) : ptr(nullptr), currentAmount(other.currentAmount), allocatedAmount(other.allocatedAmount) {
        ptr = new T[allocatedAmount];
        if (ptr == nullptr) {
            throw std::runtime_error("Memory allocation failed");
        }
        for (size_t i = 0; i < currentAmount; ++i) {
            ptr[i] = other.ptr[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] ptr;
            currentAmount = other.currentAmount;
            allocatedAmount = other.allocatedAmount;
            ptr = new T[allocatedAmount];
            if (ptr == nullptr) {
                throw std::runtime_error("Memory allocation failed");
            }
            for (size_t i = 0; i < currentAmount; ++i) {
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }

    Vector(Vector&& other) noexcept : ptr(other.ptr), currentAmount(other.currentAmount), allocatedAmount(other.allocatedAmount) {
        other.ptr = nullptr;
        other.currentAmount = 0;
        other.allocatedAmount = 0;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] ptr;
            ptr = other.ptr;
            currentAmount = other.currentAmount;
            allocatedAmount = other.allocatedAmount;
            other.ptr = nullptr;
            other.currentAmount = 0;
            other.allocatedAmount = 0;
        }
        return *this;
    }

    ~Vector() {
        delete[] ptr;
    }

    T& operator[](size_t index) {
        if (index >= currentAmount) {
            throw std::out_of_range("Index out of range");
        }
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= currentAmount) {
            throw std::out_of_range("Index out of range");
        }
        return ptr[index];
    }

    void push_back(const T& elem) {
        expandMemoryIfNeeded();
        ptr[currentAmount] = elem;
        ++currentAmount;
    }

    void expandMemoryIfNeeded() {
        if (currentAmount == allocatedAmount) {
            const size_t newAmount = allocatedAmount * 2;
            T* tmpPtr = new T[newAmount];
            if (tmpPtr == nullptr) {
                throw std::runtime_error("Memory allocation failed");
            }
            for (size_t i = 0; i < currentAmount; ++i) {
                tmpPtr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = tmpPtr;
            allocatedAmount = newAmount;
        }
    }

    size_t size() const {
        return currentAmount;
    }

    size_t capacity() const {
        return allocatedAmount;
    }

    void debugPrint() const {
        for (size_t i = 0; i < currentAmount; ++i) {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
    }

    T back() const {
        if (currentAmount == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return ptr[currentAmount - 1];
    }

    void clear() {
        currentAmount = 0;
    }

    void erase(size_t index) {
        if (index >= currentAmount) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < currentAmount - 1; ++i) {
            ptr[i] = ptr[i + 1];
        }
        --currentAmount;
    }

    bool empty() const {
        return currentAmount == 0;
    }

    void swap(Vector& other) {
        std::swap(ptr, other.ptr);
        std::swap(currentAmount, other.currentAmount);
        std::swap(allocatedAmount, other.allocatedAmount);
    }

    friend bool operator==(const Vector& a, const Vector& b) {
        if (a.currentAmount != b.currentAmount) return false;
        for (size_t i = 0; i < a.currentAmount; ++i) {
            if (a.ptr[i] != b.ptr[i]) return false;
        }
        return true;
    }

    friend bool operator!=(const Vector& a, const Vector& b) {
        return !(a == b);
    }

private:
    T* ptr;
    size_t currentAmount;
    size_t allocatedAmount;
};

#endif // VECTOR_H
