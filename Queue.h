// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include "MyException.h"

template <typename T>
class Queue {
public:
    typedef T type;
    // Custom empty exception for Queue.
    class empty_exception : public EmptyQueueException {
    public:
        empty_exception() : EmptyQueueException() { }
        empty_exception(const char* msg) : EmptyQueueException(msg) { }
    };

    Queue(void);
    Queue(const Queue<T>& queue);
    ~Queue(void);
    const Queue<T>& operator=(const Queue<T>& rhs);

    void enqueue(T element);
    void dequeue(void);
    bool is_empty(void) const;
    size_t size(void) const;
    void clear(void);

private:
    Array<T> array_;
    size_t count_;
};

#include "Queue.cpp"
#endif // _QUEUE_H_
