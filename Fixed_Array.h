// Fixed_Array.h
#ifndef FIXED_ARRAY_H
#define FIXED_ARRAY_H

#include "Array_Base.h"
#include "MyException.h"  // Assuming you have custom exceptions defined here

template <typename T, size_t N>
class Fixed_Array : public Array_Base<T> {
public:
    Fixed_Array() : Array_Base<T>(N) { }

    Fixed_Array(const Fixed_Array<T, N>& other) : Array_Base<T>(other) { }

    Fixed_Array(T fill) : Array_Base<T>(N) {
        for (size_t i = 0; i < N; ++i)
            this->data_[i] = fill;
    }

    ~Fixed_Array() { }

    // No resize method is provided.
    // You may optionally override any dynamic-specific methods to throw exceptions if needed.
};

#endif // FIXED_ARRAY_H
