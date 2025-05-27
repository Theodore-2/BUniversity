#include <iostream>
#include <vector>

using namespace std;
template <typename T>


void printVector(const vector<T>& v) {
    
	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}


int main() {
    
	int array[]= {0,1,2,3,4,5};
	int arraySize= sizeof(array)/sizeof(int);
	
	vector<int> v(array, array + arraySize);
	

	v.resize(2*arraySize); //size � 2 kat�na ��kard�k 0 dolar yeni yerlere 	
	printVector(v);
	

	v.resize(4); 	//4 indis
	printVector(v);

	
	v.resize(6,1) ;	//tekrar 6 indise ��kt� ama 4 ten sonra bo� olan yerler geni�lerken 1 koyduk
	printVector(v);
	

	cout<<v.front()<<" = ilk indis\t"<<v.back()<<" = son indis bu\n";
	v.front()=15;	//ilk eleman� de�i�tirme
	v.back()=25;	//son indisi de�i�tirme
	printVector(v);
	    

    return 0;
}






