#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;
template <typename T>

void print(list<T>& v) {
    typename list<T>::iterator myiter = v.begin(); // typename ile türü açýkça belirttik

    while (myiter != v.end()) {
        cout << *myiter << " ";
        myiter++;
    }
    cout << endl;
}


int main() {
    int arr[] = {0, 1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(int);

    // L adýnda Liste oluþturma
    list<int> L(arr, arr + arrSize);

    // Iterator tanýmlama
    list<int>::iterator My_iter = L.begin();
    cout << *My_iter << endl;


	list<int>::iterator My_iter2 = L.end();
	My_iter2--; //son elemaný yazdýrmak için kural
    cout << *My_iter2 << endl;
    
    My_iter ++;
    L.erase(My_iter);
    print(L);
    
    My_iter = L.begin(); // Iterator'u tekrar baþa al
    My_iter++;           // 2 elemanýný iþaret etsin
    My_iter++;           // 3 elemanýný iþaret etsin
    cout << *My_iter << endl; // Kontrol: 3 elemanýný iþaret ediyor mu?
    L.insert(My_iter, 15); // 3'ten önce 15 ekle
    print(L);
    
	
	return 0;
}

