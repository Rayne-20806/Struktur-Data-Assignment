# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT) (3)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### 1. Apa Itu ADT?
Pada Modul kali ini membahas ADT atau Abstract Data Type. ADT adalah Type dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan definisi invarian dari TYPE dan aksioma yang berlaku. ADT definisi dari STATIK.

Definisi type dari sebuah ADT dapat mengandung sebuah definidi dari ADT lain:
<ol>
    <li>
        ADT waktu terdiri dari ADT JAM dan ADT lain.
    </li>
    <li>
        Garis  terdiri dari dua buah ADT POINT
    </li>
</ol>

###  2. Komponen Primitif (ADT)
TYPE diterjemahkan menjad type terdefinis dalam bahasa yang bersangkutan. Jika dalam bahaasa C menggunakan struct PRIMITIF, dalam konteks prosedural, diterjemahkan menjadi fungsi atau prosedur. PRIMITIF dikelompokkan menjadi:
<ol>
    <li>
        Kontrukor/kreator, Pembentuk nilai type. Semua objek(variabel) bertype tersebut harus melalui konstrutor. Biasanya namanya di awali Make.
    </li>
    <li>
        Selector, untuk mengakses tipe komponen dan di awali Get.
    </li>
    <li>
        Prosedur oengubah nilai komponen (biasanya namanya diawali get).
    </li>
    <li>
        Validator Komponen dipakai untuk test apakah dapat membentuk tipe sesuai batasan.
    </li>
    <li>
       Destruktor/Dealokator, digunakan untuk menghancurkan nilai objek/variabel (sekaligus memori penyimpanannya) 
    </li>
    <li>
        Baca/tulis, interface dengan I/O device.
    </li>
    <li>
        Operator relasional, mendefinisikan lebih besar, kecil, sama dengan dan sebagainya.
    </li>
    <li>
        Aritmatika terhadap tipe tersebut, dalam bahasa C hanya terdefinisi untuk bilangan numerik.
    </li>
    <li>
        Konversi dari tipe tersebut ke tipe dasar dan sebaliknya
    </li>
</ol>

### 3. Implementasi ADT
Biasanya ADT diimplementasikan menjadi dua buah modul utama dan satu modul interface program utama(driver).
<ol>
    <li>
        File Header (.h): File berisi definisi atau spesifikasi dari ADT. di dalamnya terdapat deklarasi struct dan prototype(deklarasi awal) dari semua fungsi atau prosedur.
    </li>
    <li>
        File implementasi(.cpp): File ini berisi realisasi atau kode program (body) dari setiap fungsi dan prosedur yang sudah dideklarasikan di file header. File ini meng #include file headernya sendiri.
    </li>
    <li>
        File Driver/Utama(main.cpp): Program utama yang akan menggunakan ADT tersebut. File ini juga meng #inclode file header (.h) untuk bisa mengakses tipe data dan fungsi yyang telah didefinisikan.
    </li>
</ol>

### 4. Cara Menjalankan Program ADT di VS-CODE
Karena program-program terpecah menjadi beberapa file (.h) dan (.cpp), cara menjalankannya berbeda dengan menjalankan file c++ yang berjumlah satu. Jadi misalkan kita mempunyai 3 file yaitu mahasiswa.h sebagai header, mahasiswa.cpp merupakan body dari setiao fungsi dan prosedur, dan main.cpp yang bergfungsi sebagai program utama yang akan menggunakan ADT tersebut.
<ol>
    <li>
        Pastikan ketiga file tadi dalam satu folder yang sama di dalam VS-CODE, karena wajib 1 folder berisikan file (.h), (.cpp), (main.cpp)
    </li>
    <li>
        Kemudian buka terminal dan gunakan perintah g++ .\main.cpp .\mahasiswa.cpp -o mhs. Ini adalah file-file yang akan dikompilasi, kita harus menyertakan semua file .cppp agar kompiler bisa menggabungkan logika  dari program utama dan implementasi ADT. file .h tidak perlu disertakan karena sudah diinclude di file .cpp.
    </li>
    <li>
        Kemudian langsung saja jalankan perintah .\mhs.exe maka program akan berjalan.
    </li>
</ol>


## Guided 

### 1. Mahasiswa.h

```h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct  mahasiswa {
    /* data */
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED


```
Program ini bertindak sebagai file header. Didalam program ini mendefinisikan struct mahasiswa yang berisi variabel untuk nim, nilai1, dan nilai2. Selain itu, file ini mendeklarasikan fungsi dan prosedur yang beroperasi pada struct tersebut, yaitu void inputMhs() dan float rata2(). Adanya include (#ifnde, #define, #endif) memastikan bahwa isi file ini hanya dimasukkan sekali oleh compiler untuk menghidari error duplikasi.

## 2. Mahasiswa.cpp
```c++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m) {
    cout << "Input nim = ";
    cin >> (m).nim;
    cout << "Input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}

```
Program ini berisi implementasi atau kode Program (body) dari fungsi-fungsi yang telah dideklarasikan sebelumnya di mahasiswa.h . Prosedur inputMhs() digunakan untuk meminta input dari pengguna dan menyimpannya ke dalam variabel struct mahasiswa. Fungsi/function dari float rata2() digunakan untuk menerima sebuah struct mahasiswa, menghitung nilai rata-rata antara nilai1 dan nilai2, lalu mengembalikan hasil perhitungan dalam bentuk float.

## 3. Main.cpp
```c++
// testing
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai = " << rata2(mhs) << endl;
    return 0;
}
}
```
Program ini merupakan yang utama menggunakan ADT mahasiswa. File ini meng-include "mahasiwa.h" agar dapat mengenali struct dan fungsi yang telah kita buat. Di dalam main(), telah dibuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur inputMhas() untuk mengisi data, yang terakhir akan memanggil fungsi rata2() untuk menampilkan hasil dari perhitungan rata-rata.



## Unguided 

### 1. Program Data Mahasiswa
<img width="797" height="88" alt="image" src="https://github.com/user-attachments/assets/fb14e08f-d1b3-478f-8969-c3d86d1fad4f" />


```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:



### 2. Program Pelajaran Dengan Menggunakan ADTA
<img width="863" height="537" alt="image" src="https://github.com/user-attachments/assets/bf8de443-2abf-4418-bec2-d94c4ea1f3bd" />


```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:



### 3. Program dibuat dengan berbagai ketentuan
<img width="738" height="104" alt="image" src="https://github.com/user-attachments/assets/5362d46d-54c2-4dc7-ad7c-36a05851d48e" />
<img width="738" height="45" alt="image" src="https://github.com/user-attachments/assets/656825bc-3166-4117-80d6-5ffba717ae3b" />



```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:







## Kesimpulan



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.







