#include <iostream>
#include <stdexcept>

#define INITIAL_VEC_CAPACITY 4

template <typename T>
class Vector {
public:
    // Конструктор по умолчанию
    Vector() : ptr(nullptr), currentAmount(0), allocatedAmount(0) {
        ptr = new T[INITIAL_VEC_CAPACITY];
        if (ptr == nullptr) {
            throw std::runtime_error("Memory allocation failed");
        }
        allocatedAmount = INITIAL_VEC_CAPACITY;
    }

    // Конструктор копирования
    Vector(const Vector& other) : ptr(nullptr), currentAmount(other.currentAmount), allocatedAmount(other.allocatedAmount) {
        ptr = new T[allocatedAmount];
        if (ptr == nullptr) {
            throw std::runtime_error("Memory allocation failed");
        }
        for (size_t i = 0; i < currentAmount; ++i) {
            ptr[i] = other.ptr[i];
        }
    }

    // Операция присваивания
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

    // Конструктор перемещения (опционально)
    Vector(Vector&& other) noexcept : ptr(other.ptr), currentAmount(other.currentAmount), allocatedAmount(other.allocatedAmount) {
        other.ptr = nullptr;
        other.currentAmount = 0;
        other.allocatedAmount = 0;
    }

    // Операция перемещения (опционально)
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

    // Деструктор
    ~Vector() {
        delete[] ptr;
    }

    // Операция доступа через квадратные скобки
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

    // Функция добавления элемента в конец вектора
    void push_back(const T& elem) {
        expandMemoryIfNeeded();
        ptr[currentAmount] = elem;
        ++currentAmount;
    }

    // Функция расширения памяти, если необходимо
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

    // Функция получения текущего размера вектора
    size_t size() const {
        return currentAmount;
    }

    // Функция получения текущей емкости вектора
    size_t capacity() const {
        return allocatedAmount;
    }

    // Функция вывода содержимого вектора
    void debugPrint() const {
        for (size_t i = 0; i < currentAmount; ++i) {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Функция получения последнего элемента вектора
    T back() const {
        if (currentAmount == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return ptr[currentAmount - 1];
    }

private:
    T* ptr;
    size_t currentAmount;
    size_t allocatedAmount;
};

int main() {
    Vector<int> v;
    while (true) {
        int newElem;
        std::cout << "Enter a new element: ";
        std::cin >> newElem;
        v.push_back(newElem);

        std::cout << "Vector size: " << v.size() << std::endl;
        std::cout << "Vector capacity: " << v.capacity() << std::endl;
        std::cout << "Vector back: " << v.back() << std::endl;
        v.debugPrint();
    }
    return 0;
}