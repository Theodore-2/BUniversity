#include <iostream>
#include <list>

using namespace std;

void writeList(const list<int>& lst) {
   
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {5, 8, 4, 1, 7};
    int b[] = {12, 3, 15, 6, 23, 1, 2};

    size_t sizeA = sizeof(a) / sizeof(int);
    size_t sizeB = sizeof(b) / sizeof(int);

    list<int> list1(a, a + sizeA);
    list<int> list2(b, b + sizeB);

    list1.splice(list1.end(), list2);

    writeList(list1);

    return 0;
}

