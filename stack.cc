#include <iostream>
#include <exception>
#include "stack.hh"

int main(void)
{
    Stack<int> s(5);
    std::cout << "Empty? " << std::boolalpha << s.empty() << " Normal size is " << s.size() << '\n';
    s.push(-24);
    std::cout << "Empty? " << std::boolalpha << s.empty() << " Normal size is " << s.size() << '\n';
    std::cout << "Top of Stack is: " << *s.peek() << '\n';
    s.push(42);
    std::cout << s << '\n';
    s.pop();
    std::cout << s << '\n';
    return 0;
}

