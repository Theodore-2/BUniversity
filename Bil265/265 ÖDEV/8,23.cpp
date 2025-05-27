#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    queue<int> q;
    stack<int> s;

    for (size_t i = 0; i < v.size(); ++i) {
        q.push(v[i]);
        s.push(v[i]);
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    cout << "Queue after doubling size: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

