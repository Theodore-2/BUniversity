#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
int count(const std::list<T>& aList, const T& item) {
    int count = 0;
    typename std::list<T>::const_iterator it;
    for (it = aList.begin(); it != aList.end(); ++it) {
        if (*it == item) {
            ++count;
        }
    }
    return count;
}

template <typename T>
int seqSearchCount(const std::list<T>& aList, const T& item) {
    int count = 0;
    typename std::list<T>::const_iterator it = aList.begin();
    while (it != aList.end()) {
        it = std::find(it, aList.end(), item);
        if (it != aList.end()) {
            ++count;
            ++it;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    std::list<int> intList(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Count using scanning: " << count(intList, 2) << std::endl;
    std::cout << "Count using repeated search: " << seqSearchCount(intList, 2) << std::endl;

    return 0;
}

