#include "Stack_template.hpp"
#include <cmath>
#include <exception>
#include <thread>
#include <iostream>

int main(int argc, char* argv[])
{
    ::stack <double> my_stack;

    for (int i=1; i<=10; ++i) { my_stack.push(std::sqrt(i)); }

    if ( my_stack.empty() )
    {
        std::cout << "Stack is empty.\n ";
    }
    else
    {
        std::cout.precision(2);
        std::cout << "Stack is not empty:\n";
        my_stack.display();
    }

    std::cout << "Stack's size is: " << my_stack.size() << "\n";

    my_stack.erase_all();
    my_stack.display();
}


