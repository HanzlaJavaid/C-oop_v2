// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

// A minimal exception base class.
class MyException {
public:
    MyException(const char* msg) : msg_(msg) { }
    const char* what() const { return msg_; }
private:
    const char* msg_;
};

class IndexOutOfBoundsException : public MyException {
public:
    IndexOutOfBoundsException() : MyException("Index out of bounds") { }
    IndexOutOfBoundsException(const char* msg) : MyException(msg) { }
};

class EmptyStackException : public MyException {
public:
    EmptyStackException() : MyException("Stack is empty") { }
    EmptyStackException(const char* msg) : MyException(msg) { }
};

class EmptyQueueException : public MyException {
public:
    EmptyQueueException() : MyException("Queue is empty") { }
    EmptyQueueException(const char* msg) : MyException(msg) { }
};

class ResizeException : public MyException {
public:
    ResizeException() : MyException("Cannot resize Fixed_Array") { }
    ResizeException(const char* msg) : MyException(msg) { }
};

class SizeMismatchException : public MyException {
public:
    SizeMismatchException() : MyException("Size mismatch") { }
    SizeMismatchException(const char* msg) : MyException(msg) { }
};

#endif // MY_EXCEPTION_H
