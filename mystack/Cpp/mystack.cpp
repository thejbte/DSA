#include "mystack.hpp"
#include <iostream>

int  Stack::size() {
    return stack_array.size();
}

bool Stack::isEmpty() {
    return size() <= 0;
}

int  Stack::top() {
    return this->stack_array.back();
}

bool Stack::resize() {

    capacity *= 2;  // Double the capacity
    stack_array.reserve(capacity); // reserve space without initializing elem
    std::cout << "Stack resized to " << capacity << "\n";

    return true;
}

bool Stack::push(int value) {

    if(size() == this->capacity) {
        resize();
    }

    this->stack_array.push_back(value);
    return true;
}

bool Stack::pop() {
    if (!isEmpty()) {
        this->stack_array.pop_back();
        return true;
    } else {
        std::cout << "Error: Stack is Empty\n";
        return false;
    }

}

void Stack::printStack() {
    for (int i:this->stack_array) {
        std::cout << " " << i;
    }

    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        std::cout << std::endl;
    }
}
