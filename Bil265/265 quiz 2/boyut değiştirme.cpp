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
	

	v.resize(2*arraySize); //size ý 2 katýna çýkardýk 0 dolar yeni yerlere 	
	printVector(v);
	

	v.resize(4); 	//4 indis
	printVector(v);

	
	v.resize(6,1) ;	//tekrar 6 indise çýktý ama 4 ten sonra boþ olan yerler geniþlerken 1 koyduk
	printVector(v);
	

	cout<<v.front()<<" = ilk indis\t"<<v.back()<<" = son indis bu\n";
	v.front()=15;	//ilk elemaný deðiþtirme
	v.back()=25;	//son indisi deðiþtirme
	printVector(v);
	    

    return 0;
}






