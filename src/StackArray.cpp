#include <iostream>
using namespace std;

#include "StackArray.hpp"

bool StackArray::push(int x) {
    if(top >= (MAX - 1)) {
        cout << "Stack overflow!";
        return false;
    } else {
        a[++top] = x;
        cout << "Pushed into stack \n";
        return true;
    }
}

int StackArray::pop() {
    if(top < 0) {
        cout << "Stack underflow!";
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int StackArray::peek() {
    if(top < 0) {
        cout << "Stack is empty";
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool StackArray::isEmpty() {
    return (top < 0);
}