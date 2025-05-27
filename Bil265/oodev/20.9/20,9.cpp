#include <iostream>
#include <algorithm>
using namespace std;


int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) { 
        return -1; 
    }

    int mid = left + (right - left) / 2; 

    if (arr[mid] == target) { 
        return mid;
    
	} else if (arr[mid] > target) { 
        return recursiveBinarySearch(arr, left, mid - 1, target);
    
	} else { 
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
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

    
    sort(arr, arr + n);

    int target;
    
	cout << "Enter the target element to search: ";
    cin >> target;

    int result = recursiveBinarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    
	} else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

