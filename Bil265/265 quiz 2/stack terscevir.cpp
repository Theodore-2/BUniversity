//stackte say�lar� ters �eviren kod 
#include<iostream>
 #include<stack> 
 #include<vector>
 using namespace std;
int main() {
	
	stack reverseStack;
	string number;
	
	cout << "L�tfen maksimum 10 haneli bir tam say� giriniz: ";
	cin >> number;
	
	if (number.length() > 10) {
	cout << "Hata: En fazla 10 haneli bir tam say� girmelisiniz!" << endl;
	
	return 1;}
	
	for (char digit : number) {
		reverseStack.push(digit);}
		
		cout << "Say�n�n ters �evrilmi� hali: ";

	while (!reverseStack.empty()) {
		cout << reverseStack.top();
		reverseStack.pop(); }
		cout << endl;

	return 0;
}
