#include <iostream>
using namespace std;

int main() {
     int angka;
     cout << " || Program mirror input output angka ||" << endl;

     cout << "Input angka: ";
     cin >> angka;
     cout << endl;

     cout << "Outputnya adalah : " << endl;
     for (int i = angka; i >= 1; i-- ) {
          // spasi 
          for (int spasi = 0; spasi < angka-i; spasi++) {
               cout << "  ";
          }
          // baris kiri besar ke kecil
          for (int j = i; j >= 1; j--) {
               cout << j << " ";
          }
          //bintang tengah
          cout << "* ";
          //baris kanan kecil ke besar
          for (int j = 1; j <= i; j++){
               cout << j << " ";
          }
          cout << endl;    
      }
      // bintang terakhir beserta spasi
      for (int s = 0; s < angka; s++) {
          cout << "  ";
      }
      cout << "*";
      
}