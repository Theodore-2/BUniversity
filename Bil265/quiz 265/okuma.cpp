#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

	ifstream file("Karisik.txt", ios::in);
	
	if(!file){
		cout<<"olmadiii";
		return 1;
	}
	
	string line;
	
	while(getline(file, line)){
		cout<<line<<endl;
	}
	
	file.close();

	return 0;
}
