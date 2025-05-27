#include <iostream>
#include <queue>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    priority_queue<int> pq;
    map<int, int> counts;

    srand(time(0));

    for (int i = 0; i < 15; ++i) {
        int num = rand() % 5;
        pq.push(num);
        counts[num]++;
    }

    cout << "Priority queue contents with counts: ";
    for (map<int, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        cout << it->first << "(" << it->second << ") ";
    }
    cout << endl;

    return 0;
}

