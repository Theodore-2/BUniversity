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

template <typename T>
void n2top(std::stack<T>& s, int n) {
    if (n <= 0 || n > static_cast<int>(s.size())) {
        throw std::out_of_range("Invalid n value");
    }

    std::stack<T> tempStack;
    for (int i = 0; i < n - 1; ++i) {
        tempStack.push(s.top());
        s.pop();
    }

    T nthElement = s.top();
    s.pop();

    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }

    s.push(nthElement);
}

int main() {
    try {
        std::stack<int> s;
        s.push(8);
        s.push(5);
        s.push(17);
        s.push(4);
        s.push(3);

        std::cout << "Second element: " << second(s) << std::endl;

        int n = 4;
        n2top(s, n);

        std::cout << "Stack after moving nth element to top: ";
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
