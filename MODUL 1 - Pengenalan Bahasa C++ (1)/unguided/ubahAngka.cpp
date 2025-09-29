#include <iostream>
using namespace std;

string satuan(int angka) {
     switch (angka) {
     case 1: return "satu";
     case 2: return "dua";
     case 3: return "tiga";
     case 4: return "empat";
     case 5: return "lima";
     case 6: return "enam";
     case 7: return "tujuh";
     case 8: return "delapan";
     case 9: return "sembilan";
     default: return "";
     }
}

int main() {
     int bilangan;
     string hasil;

     cout << " || Program merubah angka menjadi sebuah tulisan ||" << endl;
     cout << "Masukkan angka 0 - 100: ";
     cin >> bilangan;

     if (bilangan >= 0 && bilangan <= 100) {
          if (bilangan == 0) {
            hasil = "nol";
        } else if (bilangan == 100) {
            hasil = "seratus";
        } else if (bilangan < 10) {
            hasil = satuan(bilangan);
        } else if (bilangan == 10) {
            hasil = "sepuluh";
        } else if (bilangan == 11) {
            hasil = "sebelas";
        } else if (bilangan < 20) {
            hasil = satuan(bilangan % 10) + " belas";
        } else { 
            hasil = satuan(bilangan / 10) + " puluh";
            if (bilangan % 10 != 0) {
                hasil += " " + satuan(bilangan % 10);
            }
        }
        cout << "Hasil: \n" << bilangan << ":" << hasil << endl;
     } else {
         cout << "Bilangan tidak valid, harus 0-100";
     };

     return 0;
}