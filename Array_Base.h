// Array_Base.h
#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array_Base {
public:
    Array_Base() : data_(nullptr), size_(0) { }

    Array_Base(size_t size) : size_(size) {
        data_ = new T[size_];
    }

    Array_Base(const Array_Base & other) : size_(other.size_) {
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            data_[i] = other.data_[i];
    }

    virtual ~Array_Base() {
        delete [] data_;
    }

    // Accessor methods.
    T & operator[](size_t index) {
        if (index >= size_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T & operator[](size_t index) const {
        if (index >= size_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }

    size_t size(void) const { return size_; }

    // Other common methods can be added here, e.g., fill, find, etc.

protected:
    T* data_;
    size_t size_;
};

#endif // ARRAY_BASE_H
