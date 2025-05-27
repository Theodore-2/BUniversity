#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

template <typename T>
void cut(queue<T>& q, int n, const T& item) {
    if (n < 1 || n > static_cast<int>(q.size()) + 1) {
        throw out_of_range("Invalid position");
    }

    queue<T> tempQueue;
    for (int i = 1; i < n; ++i) {
        tempQueue.push(q.front());
        q.pop();
    }

    tempQueue.push(item);

    while (!q.empty()) {
        tempQueue.push(q.front());
        q.pop();
    }

    q = tempQueue;
}

int main() {
    queue<int> q;
    q.push(8);
    q.push(5);
    q.push(17);
    q.push(3);
    q.push(7);

    int n = 4;
    int item = 9;

    try {
        cut(q, n, item);

        cout << "Queue after cut operation: ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

