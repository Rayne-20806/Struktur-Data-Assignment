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

## 2. INPUT OUTOUT
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

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
