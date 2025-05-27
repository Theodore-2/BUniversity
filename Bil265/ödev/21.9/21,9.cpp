#include <iostream>
#include <string>
using namespace std;


bool endControl(const string& word) {
    
	int len = word.length();
    
    if (word[len - 1] == 'r') {
        return true;
    }
    
    else if (len > 1 && word[len - 2] == 'a' && word[len - 1] == 'y') {
        return true;
    }
    
    return 0;
}

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    cout << "Enter words:\n";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        
        bool isLowercase = true;
        for (i=0 ; i<word.length(); i++) {
        	
        	char c = word[i];
        	
            if (c < 'a' || c > 'z') {
                isLowercase = false;
                break;
            }
        }

    
        if (isLowercase && endControl(word)) {
            cout << word << endl;
        }
    }

    return 0;
}

