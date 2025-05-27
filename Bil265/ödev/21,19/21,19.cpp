#include <iostream>
#include <string>

using namespace std;


string removeBy(string text) {
    size_t pos;


    while ((pos = text.find("by")) != string::npos) {
        text.erase(pos, 2);
    }

    while ((pos = text.find("BY")) != string::npos) {
        text.erase(pos, 2);
    }

    return text;
}

int main() {
    string message;
    cout << "Enter a message: ";
    getline(cin, message);

    string modifiedMessage = removeBy(message);
    cout << "Modified message: " << modifiedMessage << endl;

    return 0;
}

