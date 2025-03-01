// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include "Stack.h"

template <typename T>
Stack<T>::Stack(void) : count_(0) {
    array_.resize(0);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) : array_(s.array_), count_(s.count_) { }

template <typename T>
Stack<T>::~Stack(void) { }

template <typename T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {
    if (this != &rhs) {
        array_ = rhs.array_;
        count_ = rhs.count_;
    }
    return *this;
}

template <typename T>
void Stack<T>::push(T element) {
    array_.resize(count_ + 1);
    // Shift elements to the right
    for (size_t i = count_; i > 0; --i)
        array_[i] = array_[i - 1];
    array_[0] = element;
    ++count_;
}

template <typename T>
void Stack<T>::pop(void) {
    if (is_empty())
        throw empty_exception("Stack is empty");
    // Shift elements left
    for (size_t i = 0; i < count_ - 1; ++i)
        array_[i] = array_[i + 1];
    --count_;
    array_.resize(count_);
}

template <typename T>
T Stack<T>::top(void) const {
    if (is_empty())
        throw empty_exception("Stack is empty");
    return array_[0];
}

template <typename T>
bool Stack<T>::is_empty(void) const {
    return count_ == 0;
}

template <typename T>
size_t Stack<T>::size(void) const {
    return count_;
}

template <typename T>
void Stack<T>::clear(void) {
    count_ = 0;
    array_.resize(0);
}
