// Array.h
#ifndef ARRAY_H
#define ARRAY_H

#include "Array_Base.h"

template <typename T>
class Array : public Array_Base<T> {
public:
    Array() : Array_Base<T>() { }

    Array(size_t size) : Array_Base<T>(size) { }

    Array(size_t size, T fill) : Array_Base<T>(size) {
        for (size_t i = 0; i < this->size_; ++i)
            this->data_[i] = fill;
    }

    Array(const Array & other) : Array_Base<T>(other) { }

    ~Array() { }

    // Allow dynamic resizing.
    void resize(size_t new_size) {
        T* new_data = new T[new_size];
        size_t copy_size = (new_size < this->size_) ? new_size : this->size_;
        for (size_t i = 0; i < copy_size; ++i)
            new_data[i] = this->data_[i];
        delete [] this->data_;
        this->data_ = new_data;
        this->size_ = new_size;
    }

    // Optionally, implement shrink() or other dynamic-specific methods.
};

#endif // ARRAY_H
