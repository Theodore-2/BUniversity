#include <iostream>
#include <fstream>
using namespace std;

// Selection Sort Fonksiyonu
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Elemanlar� takas et
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    ifstream inputFile("Karisik.txt"); // Giri� dosyas�
    ofstream outputFile("sude.txt");  // ��k�� dosyas�

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Dosya acilamadi!" << endl;
        return 1;
    }

    int arr[100], size = 0;

    // Dosyadan say�lar� oku
    while (inputFile >> arr[size]) {
        size++;
    }
    inputFile.close();

    // Selection Sort ile s�ralama
    selectionSort(arr, size);

    // S�ralanan say�lar� yeni dosyaya yaz
    for (int i = 0; i < size; ++i) {
        outputFile << arr[i] << endl;
    }
    outputFile.close();

    cout << "Selection Sort ile siralanmis sayilar 'sude.txt' dosyasina kaydedildi." << endl;
    return 0;
}

