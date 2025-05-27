#include <iostream>
#include <string>

using namespace std;

string rot13(string text) {
    
	for (int i = 0; i < text.length(); i++) { 
        
		char &c = text[i];
       
	    if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + 13) % 26;
        } else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + 13) % 26;
        }
    }
   
    return text;
}

int main() {
    
	string message;

    cout << "Enter your message: ";
    getline(cin, message);

    string encrypted = rot13(message);
    cout << "Encrypted message: " << encrypted << endl;

	string decrypted = rot13(encrypted);  
    cout << "Decrypted message: " << decrypted << endl;
    
    return 0;
}

