#include <iostream>
#include <vector>

using namespace std;

template<typename T>

void Birlestir(vector<T>& vA , const vector<T>& vB){
	
	for(int i=0; i<vB.size(); i++)
		vA.push_back(vB[i]);
}

// A VEKT�R�N�N SONUNA B VEKT�R�N� EKLEME FONKS�YONU


