#include <iostream>
#include <vector>

using namespace std;

template<typename T>

void Birlestir(vector<T>& vA , const vector<T>& vB){
	
	for(int i=0; i<vB.size(); i++)
		vA.push_back(vB[i]);
}

// A VEKTÖRÜNÜN SONUNA B VEKTÖRÜNÜ EKLEME FONKSÝYONU


