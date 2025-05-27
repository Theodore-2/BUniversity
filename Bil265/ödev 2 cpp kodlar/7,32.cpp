#include <iostream>
#include <deque>
#include <stdexcept>

using namespace std;

enum stackNumber { one, two };

template <typename T>
class dualStack {
public:
    dualStack() : count1(0), count2(0) {}

    void push(const T& item, stackNumber n) {
        if (n == one) {
            dq.push_front(item);
            ++count1;
        } else if (n == two) {
            dq.push_back(item);
            ++count2;
        }
    }

    void pop(stackNumber n) {
        if (n == one && !empty(one)) {
            dq.pop_front();
            --count1;
        } else if (n == two && !empty(two)) {
            dq.pop_back();
            --count2;
        } else {
            throw underflow_error("Stack is empty");
        }
    }

    T top(stackNumber n) const {
        if (n == one && !empty(one)) {
            return dq.front();
        } else if (n == two && !empty(two)) {
            return dq.back();
        } else {
            throw underflow_error("Stack is empty");
        }
    }

    bool empty(stackNumber n) const {
        return (n == one) ? count1 == 0 : count2 == 0;
    }

    int size(stackNumber n) const {
        return (n == one) ? count1 : count2;
    }

private:
    deque<T> dq;
    int count1;
    int count2;
};

int main() {
    dualStack<int> ds;

    for (int i = 0; i < 20; ++i) {
        if (i % 2 == 0) {
            ds.push(i, one);
        } else {
            ds.push(i, two);
        }
    }

    cout << "Contents of Stack 1: ";
    while (!ds.empty(one)) {
        cout << ds.top(one) << " ";
        ds.pop(one);
    }
    cout << endl;

    cout << "Contents of Stack 2: ";
    while (!ds.empty(two)) {
        cout << ds.top(two) << " ";
        ds.pop(two);
    }
    cout << endl;

    return 0;
}

