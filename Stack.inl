// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

template <typename T>
inline
size_t Stack<T>::size(void) const {
    return count_;
}

template <typename T>
inline
T Stack<T>::top(void) const {
    if (is_empty())
        throw empty_exception("Stack is empty");
    return array_[0];
}

template <typename T>
inline
bool Stack<T>::is_empty(void) const {
    return count_ == 0;
}