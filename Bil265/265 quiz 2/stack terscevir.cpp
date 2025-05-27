//stackte sayýlarý ters çeviren kod 
#include<iostream>
 #include<stack> 
 #include<vector>
 using namespace std;
int main() {
	
	stack reverseStack;
	string number;
	
	cout << "Lütfen maksimum 10 haneli bir tam sayý giriniz: ";
	cin >> number;
	
	if (number.length() > 10) {
	cout << "Hata: En fazla 10 haneli bir tam sayý girmelisiniz!" << endl;
	
	return 1;}
	
	for (char digit : number) {
		reverseStack.push(digit);}
		
		cout << "Sayýnýn ters çevrilmiþ hali: ";

	while (!reverseStack.empty()) {
		cout << reverseStack.top();
		reverseStack.pop(); }
		cout << endl;

	return 0;
}
