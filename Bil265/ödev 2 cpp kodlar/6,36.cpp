#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class intEntry {
public:
    intEntry(int v, int c = 1) : value(v), count(c) {}

    int getValue() const {
        return value;
    }

    int getCount() const {
        return count;
    }

    void increment() {
        ++count;
    }

    friend bool operator<(const intEntry& lhs, const intEntry& rhs) {
        return lhs.value < rhs.value;
    }

    friend bool operator==(const intEntry& lhs, const intEntry& rhs) {
        return lhs.value == rhs.value;
    }

    friend ostream& operator<<(ostream& ostr, const intEntry& obj) {
        for (int i = 0; i < obj.count; ++i) {
            ostr << obj.value << " ";
        }
        return ostr;
    }

private:
    int value;
    int count;
};

void insertInOrder(list<intEntry>& intList, int value) {
    for (list<intEntry>::iterator it = intList.begin(); it != intList.end(); ++it) {
        if (it->getValue() == value) {
            it->increment();
            return;
        }
    }
    intList.push_back(intEntry(value));
    intList.sort();
}

int main() {
    list<intEntry> intList;

    int values[] = {5, 3, 8, 3, 5, 5, 7, 8, 2, 3};
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        insertInOrder(intList, values[i]);
    }

    for (list<intEntry>::iterator it = intList.begin(); it != intList.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    return 0;
}

