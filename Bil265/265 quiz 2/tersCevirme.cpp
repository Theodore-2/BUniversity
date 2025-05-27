#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[] = {3, 5, 8, 1, 3, 8};
    int arrSize = sizeof(arr) / sizeof(int);
    vector<int> v(arr, arr + arrSize);

    while (!v.empty()) {
        cout << v.back() << " ";
        v.pop_back();
    }

    return 0;
}

