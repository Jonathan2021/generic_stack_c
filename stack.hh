#pragma once

#include <iostream>

template <typename T>
class Stack
{
    public:
        Stack(unsigned max_size);
        ~Stack();
        bool empty() const;
        unsigned size() const;
        T* peek();
        const T* peek() const;
        bool push(const T& elt);
        void pop();
        template <typename U>
        friend std::ostream& operator<<(std::ostream& ostr, const Stack<U>& s);
    private:
        unsigned max;
        int top;
        T* array;
};

#include "stack.hxx"
