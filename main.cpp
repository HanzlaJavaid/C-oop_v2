// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"
#include "MyException.h"

int main() {
    // --------- Testing Stack -----------
    std::cout << "=== Testing Stack ===\n";
    try {
        Stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        std::cout << "Stack top (should be 30): " << s.top() << "\n";
        std::cout << "Stack size (should be 3): " << s.size() << "\n";
        s.pop();
        std::cout << "After pop, stack top (should be 20): " << s.top() << "\n";
        std::cout << "Stack size (should be 2): " << s.size() << "\n";
        s.clear();
        std::cout << "After clear, stack is empty: " << (s.is_empty() ? "Yes" : "No") << "\n";
    } catch (const MyException &e) {
        std::cerr << "Stack test error: " << e.what() << "\n";
    }
    
    // --------- Testing Queue -----------
    std::cout << "\n=== Testing Queue ===\n";
    try {
        Queue<int> q;
        q.enqueue(100);
        q.enqueue(200);
        q.enqueue(300);
        std::cout << "Queue size (should be 3): " << q.size() << "\n";
        q.dequeue();
        std::cout << "After one dequeue, queue size (should be 2): " << q.size() << "\n";
    } catch (const MyException &e) {
        std::cerr << "Queue test error: " << e.what() << "\n";
    }
    
    // --------- Testing Fixed_Array -----------
    std::cout << "\n=== Testing Fixed_Array ===\n";
    try {
        Fixed_Array<int, 5> farr(42);
        for (size_t i = 0; i < 5; i++) {
            std::cout << "Fixed_Array element " << i << ": " << farr[i] << "\n";
        }
        try {
            farr.resize(10);
        } catch (const MyException &e) {
            std::cout << "Expected exception on resizing Fixed_Array: " << e.what() << "\n";
        }
    } catch (const MyException &e) {
        std::cerr << "Fixed_Array test error: " << e.what() << "\n";
    }
    
    return 0;
}
