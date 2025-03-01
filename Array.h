// -*- C++ -*-
// $Id: Array.h 819 2011-01-17 15:24:45Z hillj $
//
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
public:
    typedef T type;

    Array(void) : data_(nullptr), cur_size_(0), max_size_(0) { }
    
    Array(size_t length) : cur_size_(length), max_size_(length) {
        data_ = new T[length];
    }
    
    Array(size_t length, T fill) : cur_size_(length), max_size_(length) {
        data_ = new T[length];
        for (size_t i = 0; i < length; ++i)
            data_[i] = fill;
    }
    
    Array(const Array & arr) : cur_size_(arr.cur_size_), max_size_(arr.max_size_) {
        data_ = new T[max_size_];
        for (size_t i = 0; i < cur_size_; ++i)
            data_[i] = arr.data_[i];
    }
    
    ~Array(void) {
        delete[] data_;
    }
    
    const Array & operator=(const Array & rhs) {
        if (this != &rhs) {
            delete[] data_;
            cur_size_ = rhs.cur_size_;
            max_size_ = rhs.max_size_;
            data_ = new T[max_size_];
            for (size_t i = 0; i < cur_size_; ++i)
                data_[i] = rhs.data_[i];
        }
        return *this;
    }
    
    size_t size(void) const { return cur_size_; }
    size_t max_size(void) const { return max_size_; }
    
    T & operator[](size_t index) {
        if (index >= cur_size_)
            throw std::out_of_range("Index out of bounds");
        return data_[index];
    }
    
    const T & operator[](size_t index) const {
        if (index >= cur_size_)
            throw std::out_of_range("Index out of bounds");
        return data_[index];
    }
    
    void resize(size_t new_size) {
        T* new_data = new T[new_size];
        size_t copy_size = (new_size < cur_size_) ? new_size : cur_size_;
        for (size_t i = 0; i < copy_size; ++i)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        cur_size_ = new_size;
        max_size_ = new_size;
    }
    
private:
    T* data_;
    size_t cur_size_;
    size_t max_size_;
};

#endif // _ARRAY_H_
