// -*- C++ -*-
//
// Queue.inl
//
// Implementation of Queue inline methods.

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

template <typename T>
Queue<T>::Queue(void) : count_(0) {
    array_.resize(0);
}

template <typename T>
Queue<T>::Queue(const Queue<T>& queue) : count_(queue.count_), array_(queue.array_) { }

template <typename T>
Queue<T>::~Queue(void) { }

template <typename T>
const Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
    if (this != &rhs) {
        array_ = rhs.array_;
        count_ = rhs.count_;
    }
    return *this;
}

template <typename T>
void Queue<T>::enqueue(T element) {
    array_.resize(count_ + 1);
    array_[count_] = element;
    ++count_;
}

template <typename T>
void Queue<T>::dequeue(void) {
    if (is_empty())
        throw empty_exception("Queue is empty");
    // Shift each element one position to the left.
    for (size_t i = 0; i < count_ - 1; ++i)
        array_[i] = array_[i + 1];
    --count_;
    array_.resize(count_);
}

template <typename T>
bool Queue<T>::is_empty(void) const {
    return count_ == 0;
}

template <typename T>
size_t Queue<T>::size(void) const {
    return count_;
}

template <typename T>
void Queue<T>::clear(void) {
    count_ = 0;
    array_.resize(0);
}
