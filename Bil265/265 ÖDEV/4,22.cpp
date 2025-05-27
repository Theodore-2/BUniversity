#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& v, int first, int last) {
    if (first >= last) return;

    insertionSort(v, first, last - 1);

    T key = v[last];
    int j = last - 1;
    while (j >= first && v[j] > key) {
        v[j + 1] = v[j];
        --j;
    }
    v[j + 1] = key;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    insertionSort(vec, 0, vec.size() - 1);

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

