#include <iostream>
#include <fstream>

using namespace std;


int main(){
	
	ofstream createFile("Karisik.txt");
	
	if(createFile.is_open()){
		
		createFile<<"merhaba SUDE!!!\n";
		createFile<<"haaarikasin asssskimmm\n";
		
		createFile.close();
		cout<<"Dosya olustu"<<endl;
	}else
		cout<<"dosya oluþturulamadý!!!!"<<endl;
	
	
	return 0;
}

