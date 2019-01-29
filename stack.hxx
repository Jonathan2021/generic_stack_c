#pragma once

#include <iostream>
#include <optional>

template <typename T>
Stack<T>::Stack(unsigned max_size)
: max(max_size)
, top(-1)
,array(new T[max_size])
{
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] this->array;
}

template <typename T>
bool Stack<T>::empty() const
{
    return (top >= 0);
}

template <typename T>
unsigned Stack<T>::size() const
{
    if (top < 0)
        return 0;
    return top + 1;
}

template <typename T>
std::optional<T&> Stack<T>::peek()
{
    if (this->top < 0)
        return std::nullopt;
    else
        return std::optional<T&>{this->array[this->top]};
}

template <typename T>
std::optional<const T&> Stack<T>::peek() const
{
    if (this->top < 0)
        return std::nullopt;
    else
        return std::optional<T&>{this->array[this->top]};
}

template <typename T>
bool Stack<T>::push(const T& elt)
{
    if (this->top < (int)this->max - 1)
    {
        this->array[++top] = elt;
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::pop()
{
    top--;
}

template <typename U>
std::ostream& operator<<(std::ostream& ost, const Stack<U>& s)
{
    for (int i = 0; i < s.top; ++i)
    {
        ost << s.array[i] << "";
    }
    if (s.top >= 0)
        ost << s.array[s.top];
    return ost;
}
