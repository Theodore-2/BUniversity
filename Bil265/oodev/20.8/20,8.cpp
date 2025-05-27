#include <iostream>
using namespace std;


int recursiveLinearSearch(int arr[], int size, int target, int index = 0) {
    if (index >= size) { 
        return -1; 
    }

    if (arr[index] == target) {
        return index;
    }

    
    return recursiveLinearSearch(arr, size, target, index + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int result = recursiveLinearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

