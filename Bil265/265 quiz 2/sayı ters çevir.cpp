#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Reverse fonksiyonu: Kuyruktaki elemanlarý ters çevirir
template <typename T>
string Reverse(queue<T>& Q) {
    string reversed = "";

    while (!Q.empty()) {
        reversed = Q.front() + reversed; // Kuyruðun baþýndaki elemaný ters sýrayla ekle
        Q.pop(); // Kuyruðun baþýndaki elemaný çýkar
    }

    return reversed; // Ters çevrilmiþ stringi döndür
}

int main() {
    string sayi;

    // Kullanýcýdan giriþ al
    cout << "10 basamakli sayi: ";
    cin >> sayi;

    // Uzunluk kontrolü
    if (sayi.length() > 10) {
        cout << "patladý\n";
        return -1;
    }

    // Kuyruk oluþtur ve sayýnýn karakterlerini kuyruk yapýsýna ekle
    queue<char> q;
    for (size_t i = 0; i < sayi.length(); i++) {
        q.push(sayi[i]);
    }

    // Reverse fonksiyonunu çaðýr ve ters çevrilmiþ sayýyý al
    string reversed = Reverse(q);

    // Sonuçlarý yazdýr
    cout << "Ters cevrilmis sayi: " << reversed << endl;

    return 0;
}

