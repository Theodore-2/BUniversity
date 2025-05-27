#include <iostream>
#include <list>
#include <string>

template <typename T>
void inList(std::list<T>& aList, const T& item) {
    typename std::list<T>::iterator iter;
    iter = aList.begin();

    while (iter != aList.end()) {
        if (item == *iter)
            return;
        iter++;
    }
    aList.push_back(item);
}

int main() {
    std::list<int> intL;
    int values[] = {5, 2, 4, 5, 7, 2};

    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        inList(intL, values[i]);
    }

    std::cout << "Resulting list of integers: ";
    for (std::list<int>::iterator it = intL.begin(); it != intL.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<char> charL;
    std::string str = "mississippi";

    for (size_t i = 0; i < str.size(); ++i) {
        inList(charL, str[i]);
    }

    std::cout << "Resulting list of characters: ";
    for (std::list<char>::iterator it = charL.begin(); it != charL.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

