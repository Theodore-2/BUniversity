#include <iostream>
#include <stdexcept>

template <typename T>
class bstack {
public:
    bstack() : topIndex(-1) {}

    void push(const T& item) {
        if (full()) {
            throw std::overflow_error("Stack is full");
        }
        stack[++topIndex] = item;
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        --topIndex;
    }

    T top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return stack[topIndex];
    }

    int size() const {
        return topIndex + 1;
    }

    bool empty() const {
        return topIndex == -1;
    }

    bool full() const {
        return topIndex == MAXSTACKSIZE - 1;
    }

private:
    static const int MAXSTACKSIZE = 50;
    T stack[MAXSTACKSIZE];
    int topIndex;
};

int main() {
    try {
        bstack<int> myStack;

        myStack.push(10);
        myStack.push(20);
        myStack.push(30);

        std::cout << "Top element: " << myStack.top() << std::endl;

        myStack.pop();
        std::cout << "Top element after pop: " << myStack.top() << std::endl;

        std::cout << "Stack size: " << myStack.size() << std::endl;

        while (!myStack.empty()) {
            std::cout << "Popping: " << myStack.top() << std::endl;
            myStack.pop();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
