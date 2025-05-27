#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> createSpamWords() {
    vector<string> spamWords;
    spamWords.push_back("Free");
    spamWords.push_back("Congratulations!");
    spamWords.push_back("Urgent");
    spamWords.push_back("Limited time offer");
    spamWords.push_back("Act now");
    spamWords.push_back("Click here");
    spamWords.push_back("Guaranteed");
    spamWords.push_back("Risk-free");
    spamWords.push_back("Once in a lifetime");
    spamWords.push_back("100% satisfaction");
    spamWords.push_back("Don't miss out");
    spamWords.push_back("Instant access");
    spamWords.push_back("Cash bonus");
    spamWords.push_back("Win big");
    spamWords.push_back("Exclusive offer");
    spamWords.push_back("Order now");
    spamWords.push_back("You've been selected");
    spamWords.push_back("Claim your prize");
    spamWords.push_back("Final notice");
    spamWords.push_back("Unsecured loan");
    spamWords.push_back("Easy money");
    spamWords.push_back("No credit check");
    spamWords.push_back("Make money fast");
    spamWords.push_back("Million dollars");
    spamWords.push_back("Pre-approved");
    spamWords.push_back("Double your income");
    spamWords.push_back("Act immediately");
    spamWords.push_back("Get rich quick");
    spamWords.push_back("Your account has been compromised");
    spamWords.push_back("Dear friend");
    return spamWords;
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int calculateSpamScore(const string& message, const vector<string>& spamWords) {
    int score = 0;
    string lowerMessage = toLower(message); 

    for (int i = 0; i < spamWords.size(); i++) { 
        if (lowerMessage.find(toLower(spamWords[i])) != string::npos) {
            score++;
        }
    }
    return score;
}

int main() {
    vector<string> spamWords = createSpamWords();

    string message;
    cout << "Enter the email message: ";
    getline(cin, message);

    int spamScore = calculateSpamScore(message, spamWords);
    cout << "Spam score: " << spamScore << endl;

    return 0;
}

