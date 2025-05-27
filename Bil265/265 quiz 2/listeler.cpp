#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;
template <typename T>

void print(list<T>& v) {
    typename list<T>::iterator myiter = v.begin(); // typename ile t�r� a��k�a belirttik

    while (myiter != v.end()) {
        cout << *myiter << " ";
        myiter++;
    }
    cout << endl;
}


int main() {
    int arr[] = {0, 1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(int);

    // L ad�nda Liste olu�turma
    list<int> L(arr, arr + arrSize);

    // Iterator tan�mlama
    list<int>::iterator My_iter = L.begin();
    cout << *My_iter << endl;


	list<int>::iterator My_iter2 = L.end();
	My_iter2--; //son eleman� yazd�rmak i�in kural
    cout << *My_iter2 << endl;
    
    My_iter ++;
    L.erase(My_iter);
    print(L);
    
    My_iter = L.begin(); // Iterator'u tekrar ba�a al
    My_iter++;           // 2 eleman�n� i�aret etsin
    My_iter++;           // 3 eleman�n� i�aret etsin
    cout << *My_iter << endl; // Kontrol: 3 eleman�n� i�aret ediyor mu?
    L.insert(My_iter, 15); // 3'ten �nce 15 ekle
    print(L);
    
	
	return 0;
}

