#include <iostream>
#include <vector>

template <typename T>
void removeDup(std::vector<T>& v) {
    if (v.empty()) return;

    size_t j = 1;
    for (size_t i = 1; i < v.size(); ++i) {
        bool isDuplicate = false;
        for (size_t k = 0; k < j; ++k) {
            if (v[i] == v[k]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            v[j] = v[i];
            ++j;
        }
    }
    v.resize(j);
}

int main() {
    int arr[] = {1, 7, 2, 7, 9, 1, 2, 8, 9}; 
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));  

    removeDup(vec);

    for (size_t i = 0; i < vec.size(); ++i) {  
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

