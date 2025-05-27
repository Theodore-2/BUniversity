#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream updateFile("Karisik.txt", ios::app); 
   
    if (updateFile) {
        updateFile << "deneme satiri AAAAAAAAAAAAAAA.\n";
        updateFile.close();
        cout << "Dosya 'Karisik.txt' guncellendi ve veri eklendi." << endl;
    } else {
        cout << "Dosya guncellenemedi." << endl;
    }

    return 0;
}

