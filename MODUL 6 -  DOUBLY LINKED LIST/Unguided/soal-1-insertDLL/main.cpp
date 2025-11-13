#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    List L;        // buat list
    createList(L); // panggil createList untuk L.first = nil dan L.last = nil

    address P;
    infotype data;

    cout << "=== PROGRAM DATA KENDARAAN DENGAN DOUBLY LINKED LIST" << endl;
    cout << "=== SOAL NO 1. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;

    for (int i = 0; i < 4; i++) {//misal kita akan buat 4 input list
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;

        // cek duplikat dengan panggil finElmByNopol
        if (FindElmByNopol(L, data.nopol) != nil) {
            // Jika KETEMU (tidak nil), cetak error
            cout << "nomor polisi sudah terdaftar" << endl; 
            
            // Kita tetap minta input sisanya, tapi dibuang
            // agar sesuai alur di gambar
            string buangWarna;
            int buangTahun;
            cout << "masukkan warna kendaraan: ";
            cin >> buangWarna;
            cout << "masukkan tahun kendaraan: ";
            cin >> buangTahun;
        } else {
            // Jika TIDAK KETEMU, lanjutkan input
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            
            // Alokasi untuk node baru
            P = alokasi(data);
            // Kita pakai insertFirst agar outputnya terbalik
            // (D004, D003, D001)
            insertFirst(L, P);
        }
        if (i < 3) {
            cout << endl;
        }
    }

    cout << "\nData list 1" << endl;
    printInfo(L);

    return 0;

}
