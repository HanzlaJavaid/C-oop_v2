// -*- C++ -*-
//
// Queue.inl
//
// Implementation of Queue inline methods.

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

// Note: Since Queue.h includes Queue.cpp for template definitions,
// this Queue.inl file might be redundant if it serves the same purpose.
// However, if it's used, its content should match Queue.cpp.

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
T Queue<T>::dequeue(void) { // MODIFIED: Return type changed from void to T
    if (is_empty()) {
        // Make sure empty_exception is accessible, it's defined in Queue.h
        // as a nested class.
        throw empty_exception("Queue is empty");
    }

    T dequeued_element = array_[0]; // Store the front element

    // Shift each remaining element one position to the left.
    for (size_t i = 0; i < count_ - 1; ++i) {
        array_[i] = array_[i + 1];
    }

    --count_; // Decrease the number of elements

    // Resize the underlying array to the new count.
    array_.resize(count_);

    return dequeued_element; // Return the stored element
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