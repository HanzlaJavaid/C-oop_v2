// -*- C++ -*-
//
// Fixed_Array.inl
//
// Implementation of Fixed_Array inline methods.

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void) : Array<T>(N) { }

template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N>& arr) : Array<T>(arr) { }

template <typename T, size_t N>
template <size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M>& arr) : Array<T>(N) {
    if (M != N)
        throw SizeMismatchException("Size mismatch in Fixed_Array copy constructor");
    for (size_t i = 0; i < N; i++)
        (*this)[i] = arr[i];
}

template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill) : Array<T>(N, fill) { }

template <typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array(void) { }

template <typename T, size_t N>
const Fixed_Array<T, N>& Fixed_Array<T, N>::operator=(const Fixed_Array<T, N>& rhs) {
    if (this != &rhs) {
        for (size_t i = 0; i < N; i++)
            (*this)[i] = rhs[i];
    }
    return *this;
}

template <typename T, size_t N>
template <size_t M>
const Fixed_Array<T, N>& Fixed_Array<T, N>::operator=(const Fixed_Array<T, M>& rhs) {
    if (M != N)
        throw SizeMismatchException("Size mismatch in Fixed_Array assignment");
    for (size_t i = 0; i < N; i++)
        (*this)[i] = rhs[i];
    return *this;
}

template <typename T, size_t N>
void Fixed_Array<T, N>::resize(size_t new_size) {
    if (new_size != N)
        throw ResizeException("Cannot resize a Fixed_Array");
    // Otherwise, do nothing.
}
