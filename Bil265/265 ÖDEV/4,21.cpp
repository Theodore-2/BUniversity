#include <iostream>
#include <vector>

template <typename T>
int binSearch(const std::vector<T>& v, int first, int last, const T& target) {
    if (first > last) return -1;
    int mid = first + (last - first) / 2;
    if (v[mid] == target) return mid;
    if (v[mid] < target) return binSearch(v, mid + 1, last, target);
    return binSearch(v, first, mid - 1, target);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    int target = 8;
    int result = binSearch(vec, 0, vec.size() - 1, target);
    std::cout << (result != -1 ? "Found at index: " : "Not found, return value: ") << result << std::endl;
    return 0;
}

