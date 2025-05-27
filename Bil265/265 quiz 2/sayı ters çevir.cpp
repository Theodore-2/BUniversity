#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Reverse fonksiyonu: Kuyruktaki elemanlar� ters �evirir
template <typename T>
string Reverse(queue<T>& Q) {
    string reversed = "";

    while (!Q.empty()) {
        reversed = Q.front() + reversed; // Kuyru�un ba��ndaki eleman� ters s�rayla ekle
        Q.pop(); // Kuyru�un ba��ndaki eleman� ��kar
    }

    return reversed; // Ters �evrilmi� stringi d�nd�r
}

int main() {
    string sayi;

    // Kullan�c�dan giri� al
    cout << "10 basamakli sayi: ";
    cin >> sayi;

    // Uzunluk kontrol�
    if (sayi.length() > 10) {
        cout << "patlad�\n";
        return -1;
    }

    // Kuyruk olu�tur ve say�n�n karakterlerini kuyruk yap�s�na ekle
    queue<char> q;
    for (size_t i = 0; i < sayi.length(); i++) {
        q.push(sayi[i]);
    }

    // Reverse fonksiyonunu �a��r ve ters �evrilmi� say�y� al
    string reversed = Reverse(q);

    // Sonu�lar� yazd�r
    cout << "Ters cevrilmis sayi: " << reversed << endl;

    return 0;
}

