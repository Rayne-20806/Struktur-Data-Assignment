# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori

Modul ini awal praktikum struktur data dan menggunakan bahasa pemrograman C++. C++ adalah bahasa pemrograman yang dikembangkan dari bahasa C dengan penambahan fitur pemrograman berorientasi objek. C++ terdiri dari bagian utama seperti ```#include <iostream>``` yang digunakan untuk import library dan ```using namespace std``` untuk input output agar tidak mendeklarasikan ```std::``` berulang nantinya. fungsi ```int main()``` adalah program utama. modul ini akan membahas basic utama dari c++ seperti input-output, perulangan for, do-while, function, struktur, dan lain lain..

## Guided 

### 1. basicHelloWorld

```C++
#include <iostream> // pendeklarasikan library yang akan digunakan dalam program
using namespace std;

int main() {
     // 1. testing basic
     cout << "Hello World!!";
}
}
```
kode di atas digunakan untuk menampilkan output yaitu ```"Hello world```.

## 2. INPUT OUTPUT
```c++
#include <iostream>
using namespace std;

int main() {
     // 2. input output
     cout << "\n";
     int n;
     const float pi = 3.14;
     cout << "Masukkan angka: ";
     cin >> n;
     cout << "Angka dikeluarkan: " << n << "\n";
     cout << "Nilai konstanta pi: " << pi;
}
```
Memiliki 1 variabel int n dan constant pi dengan nilai 3.14. ```cin >>``` digunakan untuk agar user bisa menginput nilai dari suatu n dan ```cout <<``` berfungsi sebagai output dari variabel, di atas hanya menampilkan output dari user(n) dan juga nilai pi sendiri.

## 3. Operator basic c++
```c++
#include <iostream>
using namespace std;

int main() {
     // 3. Operator c++ artimatika dan logika
     int a;
     int b;
     cout << "Masukkkan angka a: ";
     cin >> a;
     cout << "Masukkan angka b: ";
     cin >> b;
     // operator aritmatika +, -, *, /, %
     cout << "a+b = " << (a+b) << endl;
     cout << "a-b = " << (a-b) << endl;
     cout << "a*b = " << (a*b) << endl;
     cout << "a/b = " << (a/b) << endl; 
     // operator logika >, < >=, <=, ==, !=
     cout << "a > b = " << (a>b) << endl;
}
```
Program ini dibuat untuk menampilkan beberapa penggunaan operator. Operator disini terbagi menjadi 2 di c++, ada operator aritmatika ```+, -, *, /``` yang digunakan untuk perhitungan dan ada operator logika atau yang digunakan untuk perbandingan. Program akan meminta inputan user berupa bilangan a dan b int(bilangan bulat) dan mengeksekusi serta menampilkan output berupa operasi aritmatika dan logika.
## 4. Percabangan
``` c++
#include <iostream>
using namespace std;

int main() {
     // 4. Percabangan
     int angka1 = 10;
     int angka2 = 20;
     // percabangan if else
     if (angka1 > angka2) {
          cout << "Angka1 lebih besar dari angka2" << endl;
     } else if (angka1 < angka2) {
          cout << "Angka1 lebih kecil dari angka2" << endl;
     } else {
          cout << "Angka1 sama dengan angka2" << endl;
     }
}
```
Program diatas menggunakan percabangan ```if-else``` untuk meenentukan sebuah outputnya. Program ini akan membandingkan hasil antara ```angka1 dan angka2``` yang hasilnya dimana ada 3 kondisi yaitu ```angka1 > angka2```, ```angka1 < angka2```, dan ```angka` == angka2```
## 5. Perulangan FOR
``` c++
#include <iostream>
using namespace std;

int main() {
     // 5. Perulangan for, increment dan decrement
     int i;
     int j;
     for (int i = 0; i <= 10; i++) {
          cout << i << "-";
     }
     cout << endl;
     
     for (int j = 20; j >= 10; j--) {
          cout << j << "-";
     }
     cout << endl;
}
```
Program diatas menggunakan program ```for``` untuk menjalankan kode secara berulang. Kode akan melakukan ```increment(++)``` untuk menampilkan atau mencetak angka dari 0 sampai 10 karena i dimulai dari 0. sementara for yang bawah akan melakukan ```decrement (--)``` untuk mencetak angka dari 20 hingga 10 secara menurun.
## 6. Do While
``` c++
#include <iostream>
using namespace std;

int main() {
     // 6. do while
     int i = 0;
     int j = 20;
     while (i <= 10) {
          cout << i << "-";
          i++;
     }
     cout << endl;

     do {
          cout << j << "-";
          j++;
     } while (j <= -2000);
}
```
Program di atas menunjukan dua perulangan yaitu ```while``` dan ```do-while```, bedanya ```while``` akan terus berjalan jika ```kondisi``` selalu benar dan akan berhenti jika kondisi sudah bernilai false. Sebaliknya ```do-while``` akan menjalankan kode minimal ```1 kali``` sebelum kemudian memeriksa kondisi apakah sudah terpenuhi atau belum.
## 7. Struktur
``` c++
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

```
Program di atas mengimplementasikan sebuah ```struct``` atau struktur, yaitu tipe data bentukan yang dapat mengelompokkan beberapa variabel namun menjadi satu kesatuan. Contoh di atas ```struct mahasiswa``` menyimpan string nama dan umur int. Kemudian ```Mahasiswa mhs[jumlah];``` adalah array of struct yang berguna menyimpan data inputan untuk mahasiswa yang nantinya akan ditampilkan pada perulangan for

## Unguided 

### 1. OPERATOR C++
<img width="600" alt="Soal nomor 1" src="https://github.com/user-attachments/assets/698348a3-2bb3-45c6-812a-714d13ab50f8" />


```C++
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
```
#### Output:
<img width="307" height="156" alt="image" src="https://github.com/user-attachments/assets/4d8e3fe1-3c24-43e2-81e3-986c27925a8e" />


Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/f56b2ba2-1452-42b4-9f2f-0e8d27d3033c" />

### 2. Ubah Angka menjadi Kalimat
<img width="581" height="126" alt="image" src="https://github.com/user-attachments/assets/750f5456-39c2-444c-b5f7-1116d997845b" />


```c++
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
      
}
```
#### Output:
<img width="1027" height="99" alt="image" src="https://github.com/user-attachments/assets/3e7492c8-5eb4-4122-8c99-74f76e72770c" />

penjelasan

#### Full code screenshot:
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/d6b3da10-ea13-402a-b15b-7a6d31dda052" />


### 3. Segitiga Angka
<img width="422" height="189" alt="image" src="https://github.com/user-attachments/assets/087a2123-40e2-4ac0-b34d-4fed4b488895" />



```c++
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
```
#### Output:
<img width="864" height="174" alt="image" src="https://github.com/user-attachments/assets/dd06e9ff-70a5-494e-b732-907fe40d42e3" />


penjelasan

#### Full code screenshot:
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/36d5d19e-3554-4e3c-9dc8-4041bc406559" />





## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
