#include <iostream>
#include <string>
using namespace std;


string reverseAndToggleCase(const string& text) {
    string result;
    for (int i = text.length() - 1; i >= 0; i--) {
        char c = text[i];
        if (isupper(c)) {
            result += tolower(c);
        } else if (islower(c)) {
            result += toupper(c);
        } else {
            result += c; 
        }
    }
    return result;
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    string reversedText = reverseAndToggleCase(text);
    cout << "Reversed and toggled case text: " << reversedText << endl;

    return 0;
}

