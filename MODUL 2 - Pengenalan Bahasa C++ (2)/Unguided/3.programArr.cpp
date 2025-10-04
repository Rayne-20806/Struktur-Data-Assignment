#include <iostream>
using namespace std;

// function cara maks
int cariMaksimum(int arr[], int ukuran) {
    int maks = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

// function cari min
int cariMinimum(int arr[], int ukuran) {
    int min = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    };
    return min;
}

// tampil isi array
void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// hitung rata2
void hitungRataRata(int arr[], int ukuran) {
    float total = 0;
    for (int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    cout << "Nilai rata-rata: " << total / ukuran << endl;
}

int main() {
    int arr[] = {11, 8, 7, 12, 26, 3, 53, 33, 55};
    // hitung ukuran array
    int ukuran = sizeof(arr) / sizeof(arr[0]);

    int pilihanMenu;
    do {
        cout << "\n---Menu Program Array ---" << endl;
        cout << "\n1. Tampilkan isi array" << endl;
        cout << "\n2. Cari nilai maksimum" << endl;
        cout << "\n3. Cari nilai minimum" << endl;
        cout << "\n4. Hitung nilai rata-rata" << endl;
        cout << "\n5. Keluar(tambah)" << endl;
        cout << "\nMasukkan pilihan Anda (1-5): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tampilkanArray(arr, ukuran);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arr, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arr, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arr, ukuran);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
        // pause sebelum lanjut dan tekan enter saja
        if (pilihanMenu != 5) {
            cout << "Teken untuk melanjutkan..." << endl;
            cin.ignore();
            cin.get();
        } 
    }
    
    while (pilihanMenu != 5);

    return 0;
}