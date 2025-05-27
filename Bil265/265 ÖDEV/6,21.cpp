#include <iostream>
#include <list>

template <typename T>
void rmOrderedDuplicates(std::list<T>& aList) {
    typename std::list<T>::iterator iter = aList.begin();

    while (iter != aList.end()) {
        typename std::list<T>::iterator next = iter;
        ++next;
        if (next != aList.end() && *iter == *next) {
            aList.erase(next);
        } else {
            ++iter;
        }
    }
}

int main() {
    int arr[] = {2, 2, 7, 8, 8, 15, 20};
    std::list<int> intList(arr, arr + sizeof(arr) / sizeof(arr[0]));

    rmOrderedDuplicates(intList);

    std::cout << "List after removing duplicates: ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

