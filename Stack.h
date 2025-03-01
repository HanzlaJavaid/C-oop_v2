// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#ifndef _STACK_H_
#define _STACK_H_

#include "Array.h"
#include "MyException.h"

template <typename T>
class Stack
{
public:
    typedef T type;
    // Custom empty exception for Stack
    class empty_exception : public EmptyStackException {
    public:
        empty_exception() : EmptyStackException() { }
        empty_exception(const char* msg) : EmptyStackException(msg) { }
    };

    Stack(void);
    Stack(const Stack & s);
    ~Stack(void);
    const Stack & operator = (const Stack & rhs);

    void push(T element);
    void pop(void);
    T top(void) const;
    bool is_empty(void) const;
    size_t size(void) const;
    void clear(void);

private:
    Array<T> array_;
    size_t count_;
};

#include "Stack.cpp"
#endif // _STACK_H_
