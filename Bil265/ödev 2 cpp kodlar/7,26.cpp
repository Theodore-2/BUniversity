#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
T second(const std::stack<T>& s) {
    if (s.size() < 2) {
        throw std::underflow_error("Stack has fewer than 2 elements");
    }

    std::stack<T> temp = s;
    temp.pop();
    return temp.top();
}

int main() {
    std::stack<int> s;
    int value;

    std::cout << "Enter 5 integer values: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> value;
        s.push(value);
    }

    try {
        std::cout << "First element on the stack: " << s.top() << std::endl;
        std::cout << "Second element on the stack: " << second(s) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Flushing the stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
