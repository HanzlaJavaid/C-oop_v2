#ifndef _FIXED_ARRAY_H_
#define _FIXED_ARRAY_H_

#include "Array.h"
#include "MyException.h"

template <typename T, size_t N>
class Fixed_Array : public Array<T>
{
public:
    // Make base class operator[] visible.
    using Array<T>::operator[];

    Fixed_Array(void);
    Fixed_Array(const Fixed_Array<T, N> & arr);
    
    // Allow copying from a Fixed_Array with a different size.
    template <size_t M>
    Fixed_Array(const Fixed_Array<T, M> & arr);
    
    // Constructor to fill the array.
    Fixed_Array(T fill);
    ~Fixed_Array(void);

    const Fixed_Array & operator = (const Fixed_Array<T, N> & rhs);
    template <size_t M>
    const Fixed_Array & operator = (const Fixed_Array<T, M> & rhs);

    // Overridden resize: fixed size cannot change.
    void resize(size_t new_size);
};

#include "Fixed_Array.cpp"
#endif // _FIXED_ARRAY_H_
