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
    // cout << "=== SOAL NO 1. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;

    // for (int i = 0; i < 4; i++) {//misal kita akan buat 4 input list
    //     cout << "Masukkan nomor polisi: ";
    //     cin >> data.nopol;

    //     // cek duplikat dengan panggil finElmByNopol
    //     if (FindElmByNopol(L, data.nopol) != nil) {
    //         // Jika KETEMU (tidak nil), cetak error
    //         cout << "nomor polisi sudah terdaftar" << endl; 
            
    //         // Kita tetap minta input sisanya, tapi dibuang
    //         // agar sesuai alur di gambar
    //         string buangWarna;
    //         int buangTahun;
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> buangWarna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> buangTahun;
    //     } else {
    //         // Jika TIDAK KETEMU, lanjutkan input
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> data.warna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> data.thnBuat;
            
    //         // Alokasi untuk node baru
    //         P = alokasi(data);
    //         // Kita pakai insertFirst agar outputnya terbalik
    //         // (D004, D003, D001)
    //         insertFirst(L, P);
    //     }
    //     if (i < 3) {
    //         cout << endl;
    //     }
    // }

    // cout << "\nData list 1" << endl;
    // printInfo(L);

    // cout << "\n=== SOAL NO 2. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;
    
    // masukkan data 1-3
    data.nopol = "D001"; 
    data.warna = "hitam"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D003"; 
    data.warna = "putih"; 
    data.thnBuat = 70;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D004"; 
    data.warna = "Kuning"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    // // Mulai pencarian
    // string nopolCari;
    // address P_ditemukan;
    // cout << "Masukkan Nomor Polisi yang akan dicari: ";
    // cin >> nopolCari;
    // // panggil findElm
    // P_ditemukan = findElm(L, nopolCari);

    // // cek hasil
    // if (P_ditemukan != nil) {
    //     cout << "Nomor Polisi : " << P_ditemukan->info.nopol << endl;
    //     cout << "Warna        : " << P_ditemukan->info.warna << endl;
    //     cout << "Tahun        : " << P_ditemukan->info.thnBuat << endl;
    // } else {
    //     cout << "Data yang anda cari tidak dapat ditemukan" << endl;
    // }



    cout << "\n=== SOAL NO 3. Implementasi pada main.cpp unuk menghapus dengan berbagai macam Delete" << endl;

    string nopolHapus;
    address P_Hapus, Prec;
    cout << "Masukan nomor polisi yang akan dihapus: ";
    cin >> nopolHapus;

    // cari node yang mau di hapus
    P_Hapus = findElm(L, nopolHapus);

    // cek apakah nodenya ada
    if (P_Hapus != nil) {
        // ini kondisi node ketemu dan tentukan mau pake delete apa dari ketiga delete yang sudah dibuat
        if (P_Hapus == L.first) { // kondisi jika P(hapus) ada di pertama
            deleteFirst(L);
        } else if (P_Hapus == L.last) { // kondisi jika P(hapus) ada di akhir
            deleteLast(L);
        } else {
            Prec = P_Hapus -> prev;
            deleteAfter(L, Prec); // hapus node setelah prec
        }

        cout << "Data dengan nomor polisii " << nopolHapus << " berhasil dihapus." << endl;

        // tampilkan isi
        cout << "\nData List 1(setelah dihapus)" <<endl;
        printInfo(L);
    } else {
        cout << "Tidak ketemu dan tidak ada yang bisa dihapus" << endl;
    }
 return 0;
}
