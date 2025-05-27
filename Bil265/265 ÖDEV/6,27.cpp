#include <iostream>
#include <list>
#include <string>

using namespace std;

template <typename T>
typename list<T>::iterator maxLoc(list<T>& aList) {
    if (aList.empty()) return aList.end();

    typename list<T>::iterator maxIt = aList.begin();
    for (typename list<T>::iterator it = aList.begin(); it != aList.end(); ++it) {
        if (*it > *maxIt) {
            maxIt = it;
        }
    }
    return maxIt;
}

int main() {
    string strArr[] = {"insert", "erase", "template", "list"};
    int strSize = sizeof(strArr) / sizeof(string);

    list<string> strList(strArr, strArr + strSize);

    while (!strList.empty()) {
        list<string>::iterator maxIt = maxLoc(strList);
        if (maxIt != strList.end()) {
            cout << "Largest value: " << *maxIt << endl;
            strList.erase(maxIt);
        }
    }

    return 0;
}

