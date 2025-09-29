#include <iostream>
using namespace std;

int main() {
     float bilangan1;
     float bilangan2;

     cout << " || Program input dua bil float ||" << endl;
     cout << "Masukkan bilangan 1: ";
     cin >> bilangan1;
     cout << "Masukkan bilangan 2: ";
     cin >> bilangan2;

     cout << endl;
     cout << " || Hasil/output dari operasi dua bil ||"<< endl;
     cout << "Pertambahan: " << bilangan1 << " + " << bilangan2 << " = " << (bilangan1 + bilangan2) << endl;
     cout << "Pengurangan: " << bilangan1 << " - " << bilangan2 << " = " << (bilangan1 - bilangan2) << endl;
     cout << "Perkalian:  " << bilangan1 << " * " << bilangan2 << " = " << (bilangan1 * bilangan2) << endl;
     cout << "Pembagian:   " << bilangan1 << " / " << bilangan2 << " = " << (bilangan1 / bilangan2) << endl;

     return 0;
}