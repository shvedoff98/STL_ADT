// Stack implementation using Vector template
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class stack
{
    private:
        std::vector <T> elems;

    public:
        void push ( T const& ) ;
        bool empty() const ;
        void pop () ;
        T top() const ;
        inline void display() const ;
        inline size_t size() const ;
        inline void erase_all();
};

template <typename T>
void stack<T>::push(T const& elem)
{
    elems.push_back(elem);
}

template <typename T>
void stack<T>::pop()
{
    if ( elems.empty() )
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back(); // remove last element
}

template <typename T>
bool stack<T>::empty() const
{
    return elems.empty();
}

template <typename T>
T stack<T>::top() const
{
    if ( elems.empty() )
    {
        throw std::out_of_range("stack<>::top(): empty stack");
    }
    return elems.back(); // return copy of last element
}

template <typename T>
inline void stack<T>::display() const
{

    if ( elems.empty() )
    {
        throw std::out_of_range ("stack<>::display() empty stack");
    }

    for ( auto const& elem : elems )
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

template <typename T>
inline size_t stack<T>::size() const
{
    return elems.size();
}

template <typename T>
inline void stack<T>::erase_all()
{
    elems = {};
}

#endif

