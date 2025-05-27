#include <iostream>
#include <string>
using namespace std;

string encrypt(const string& text) {
    string plain = "abcdefghijklmnopqrstuvwxyz";
    string coded = "xvmhwgilzrdkqypnabecujsoft"; 

    string result;
    for (int i=0; i<text.length(); i++) {
 	
 		char c= text[i];
 
        if (c >= 'A' && c <= 'Z') {
            c = tolower(c); 
        }
        
        if (c >= 'a' && c <= 'z') {
            int index = plain.find(c); 
            result += coded[index];    
        } else {
            result += c; 
        }
    }

    return result;
}

int main() {
 
    string message;
 
    cout << "Enter a message: ";
    getline(cin, message);

    string encryptedMessage = encrypt(message);
    cout << "Encrypted message: " << encryptedMessage << endl;

    return 0;
}

