#include <vector>


class Stack {

private:
    std::vector<int> stack_array;
    int capacity;

public:

    Stack(int capacity) {
        this->capacity = capacity;
        this->stack_array.reserve(this->capacity);
    }

    int  size();
    bool isEmpty();
    int  top();
    bool resize();
    bool push(int value);
    bool pop();
    void printStack();

};
