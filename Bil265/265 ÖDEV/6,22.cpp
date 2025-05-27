#include <iostream>
#include <list>

template <typename T>
void reverseOutput(const std::list<T>& aList) {
    typename std::list<T>::const_reverse_iterator it;
    for (it = aList.rbegin(); it != aList.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void r_reverseOutput(typename std::list<T>::iterator first, typename std::list<T>::iterator last) {
    if (first == last) return;
    --last;
    std::cout << *last << " ";
    r_reverseOutput<T>(first, last);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::list<int> intList(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Reverse output using reverse iterator: ";
    reverseOutput(intList);

    std::cout << "Reverse output using recursion: ";
    r_reverseOutput<int>(intList.begin(), intList.end());
    std::cout << std::endl;

    return 0;
}

