#include <iostream>
#include <fstream>
using namespace std;

// Binary Search Fonksiyonu
int binarySearch(int arr[], int size, int num) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num)
            return mid;

        else if (num < arr[mid])
            right = mid - 1;

        else
            left = mid + 1;
    }
    return -1;
}

// Selection Sort Fonksiyonu
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
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
    ifstream iFile("Karisik.txt", ios::in);
    ofstream oFile("sonuc.txt", ios::out);

    if (!iFile.is_open() || !oFile.is_open())
        return 1;

    int arr[100], size = 0;
    int sum = 0;

    // Dosyadan say�lar� oku
    while (iFile >> arr[size])
        size++;

    iFile.close();

    // Diziyi s�ralama
    selectionSort(arr, size);

    // Binary Search ile 45'i arama
    int searchedIndex = binarySearch(arr, size, 45);

    // S�ral� diziyi dosyaya ve konsola yaz
    for (int i = 0; i < size; i++) {
        if (i == searchedIndex) {
            cout << arr[i] << " is SEARCHED NUMBER!" << endl;
            oFile << arr[i] << " is SEARCHED NUMBER!" << endl;
        } else {
            oFile << arr[i] << endl;
        }
        sum += arr[i]; // T�m say�lar� toplama
    }

    // Toplam� dosyaya yaz
    oFile << "SUM OF ALL SORTED NUMBERS = " << sum << endl;
    oFile.close();

    cout << "Dosya 'sonuc.txt' olarak kaydedildi." << endl;

    return 0;
}

