#include <iostream>
#include <vector>

using namespace std;

int main() {
    
	char vowel[]= {'a','e','i','u','o'};
	int vowelSize = sizeof(vowel)/sizeof(char);
	vector<char> v(vowel, vowel + vowelSize);

	cout<< v.back()<<endl;	//back() son eleman� getirir 
	v.push_back('w');		//push_back(eklenecek �ey)

   
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
    
    
    v.pop_back(); //sonuncuyu ��kart�r
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    

    return 0;
}

