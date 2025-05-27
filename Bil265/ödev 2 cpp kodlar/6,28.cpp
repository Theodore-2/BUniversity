#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
typename list<T>::iterator maxIter(typename list<T>::iterator first, typename list<T>::iterator last) {
    if (first == last) return last;
    typename list<T>::iterator maxIt = first;
    for (typename list<T>::iterator it = first; it != last; ++it) {
        if (*it > *maxIt) {
            maxIt = it;
        }
    }
    return maxIt;
}

template <typename T>
void selectionSort(list<T>& aList) {
    for (typename list<T>::iterator passIter = aList.begin(); passIter != aList.end(); ++passIter) {
        typename list<T>::iterator maxIt = maxIter<T>(passIter, aList.end());
        if (maxIt != passIter) {
            iter_swap(passIter, maxIt);
        }
    }
}

void writeList(const list<int>& lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    list<int> intList;
    for (int i = 0; i < 10; ++i) {
        intList.push_back(rand() % 25);
    }

    cout << "Original list: ";
    writeList(intList);

    selectionSort(intList);

    cout << "Sorted list: ";
    writeList(intList);

    return 0;
}

