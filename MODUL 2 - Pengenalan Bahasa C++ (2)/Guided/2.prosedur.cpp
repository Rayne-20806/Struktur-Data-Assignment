#include <iostream>
using namespace std;

void tulis (int x) {
     for (int i = 0; i < x; i++) {
          cout << "Baris ke -: " << i+1 << endl;
     }
}

int main() {
     // 2, prosedur adalah void function, prosedur tidak mengembalikan nilai atau return value
     int jumlah;
     cout << "Masukkan jumlah baris: ";
     cin >> jumlah;
     tulis(jumlah);
}