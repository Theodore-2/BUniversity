#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Kitap s�n�f�
class Kitap {
public:
    string isim;
    int populerlik;

    Kitap(const string &isim, int populerlik) : isim(isim), populerlik(populerlik) {}
};

// ��renci s�n�f�
class Ogrenci {
public:
    string isim;
    vector<Kitap> kitaplar;

    Ogrenci(const string &isim) : isim(isim) {}
};

// Pop�lerlik s�ras�na g�re kar��la�t�rma fonksiyonu
bool populerlikSirala(const Kitap &a, const Kitap &b) {
    return a.populerlik > b.populerlik;
}

int main() {
    // Kitaplar� ekleme
    vector<Kitap> kitaplar;
    kitaplar.push_back(Kitap("Matematik", 8));
    kitaplar.push_back(Kitap("Tarih", 5));
    kitaplar.push_back(Kitap("Fizik", 7));

    // Pop�lerlik s�ras�na g�re s�ralama
    sort(kitaplar.begin(), kitaplar.end(), populerlikSirala);

    // ��rencileri olu�turma
    vector<Ogrenci> ogrenciler;
    ogrenciler.push_back(Ogrenci("Ahmet"));
    ogrenciler.push_back(Ogrenci("Ay�e"));
    ogrenciler.push_back(Ogrenci("Ali"));

    // Kitaplar� ��rencilere e�le�tirme
    for (size_t i = 0; i < ogrenciler.size(); i++) {
        ogrenciler[i].kitaplar.push_back(kitaplar[i % kitaplar.size()]);
    }

    // Kitaplar� bir stack'e ve bir vector'e ekleme
    stack<Kitap> kitapStack;
    vector<Kitap> kitapVector;

    for (vector<Kitap>::iterator it = kitaplar.begin(); it != kitaplar.end(); ++it) {
        kitapStack.push(*it);
        kitapVector.push_back(*it);
    }

    // ��kt�
    cout << "Pop�lerlik s�ras�na g�re kitaplar:" << endl;
    for (vector<Kitap>::iterator it = kitaplar.begin(); it != kitaplar.end(); ++it) {
        cout << it->isim << " (" << it->populerlik << ")" << endl;
    }

    cout << "\n��renciler ve kitaplar�:" << endl;
    for (vector<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); ++it) {
        cout << it->isim << " -> ";
        for (vector<Kitap>::iterator kitIt = it->kitaplar.begin(); kitIt != it->kitaplar.end(); ++kitIt) {
            cout << kitIt->isim << " (" << kitIt->populerlik << ") ";
        }
        cout << endl;
    }

    cout << "\nKitap stack:" << endl;
    while (!kitapStack.empty()) {
        Kitap k = kitapStack.top();
        cout << k.isim << " (" << k.populerlik << ")" << endl;
        kitapStack.pop();
    }

    cout << "\nKitap vector:" << endl;
    for (vector<Kitap>::iterator it = kitapVector.begin(); it != kitapVector.end(); ++it) {
        cout << it->isim << " (" << it->populerlik << ")" << endl;
    }

    return 0;
}

