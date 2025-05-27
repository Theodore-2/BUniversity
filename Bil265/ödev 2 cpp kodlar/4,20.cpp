#include <iostream>
#include <vector>
#include <algorithm> 

template <typename T>
void exchangeSort(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (v[i] > v[j]) {
                std::swap(v[i], v[j]);
            }
        }
    }
}

int main() {
    int arr[] = {8, 3, 6, 2}; 
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0])); 

    exchangeSort(vec);

    for (size_t i = 0; i < vec.size(); ++i) { 
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

