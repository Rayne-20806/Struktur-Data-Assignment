#include <iostream>
using namespace std;

struct Mahasiswa {
     string nama;
     int umur;
};

int main() {
     int jumlah;
     cout << "Masukkan jumlah Mahasiswa: ";
     cin >> jumlah;

     Mahasiswa mhs[jumlah];
     // input menggunakan for loop
     for (int i = 0; i < jumlah; i++) {
          cout << "\nMahasiswa ke-" << i + 1 << endl;
          cout << "Nama: ";
          cin >> mhs[i].nama;
          cout << "Umur: ";
          cin >> mhs[i].umur;
     }
     /// tampilkan data
     cout << "\n== Data Mahasiswa ==\n";
     for (int i = 0; i < jumlah; i++) {
          cout << "Mahasiswa ke-" << i + 1
               << " | Nama: " << mhs[i].nama 
               << " | Umur: " << mhs[i].umur << endl;
     }

     return 0;

}
