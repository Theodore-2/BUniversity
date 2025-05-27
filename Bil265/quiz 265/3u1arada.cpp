#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
	
	fstream file("Karisik.txt", ios::in | ios::out | ios::app);
	
	if(!file)
		cout<<"sude"<<endl;
		
	file<<"ardasude"<<endl;
	
	string line;
	
	file.seekg(0,ios::beg);
	
	while(getline(file,line)){
		
		cout<<line<<endl;
		
	}
	file.close();
	
	
	return 0;
	
}
