#include "mystack.hpp"
#include <iostream>

//g++ main.c mystack.c -g -o main
//valgrind  --leak-check=full ./main


int main() {

    Stack st(5);
    st.printStack();

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    //to resize
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);


    st.printStack();
    std::cout << "top: " << st.top() << std::endl;

    st.pop();
    st.pop();
    st.pop();



    st.printStack();
    std::cout << "top: " << st.top() << std::endl;


    return 0;
}
