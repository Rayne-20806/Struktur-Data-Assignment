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
```
Program ini merupakan yang utama menggunakan ADT mahasiswa. File ini meng-include "mahasiwa.h" agar dapat mengenali struct dan fungsi yang telah kita buat. Di dalam main(), telah dibuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur inputMhas() untuk mengisi data, yang terakhir akan memanggil fungsi rata2() untuk menampilkan hasil dari perhitungan rata-rata.



## Unguided 

### 1. Program Data Mahasiswa
<img width="797" height="88" alt="image" src="https://github.com/user-attachments/assets/fb14e08f-d1b3-478f-8969-c3d86d1fad4f" />


```c++
#include <iostream>
#include <limits> // digunakan untuk numeric_limits
using namespace std;


struct mahasiswaArray {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float rata2NilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
};

const int MAX_MHS = 10;

int main() {
    mahasiswaArray mhs[MAX_MHS];
    int jumlahMhs = 0;
    
    cout << "||Program Menghitung Rata-rata Nilai Akhir Mahasiswa||" << endl;
    cout << "Masukkan jumlah Mahasiswa (maksimal 10); ";
    cin >> jumlahMhs;
    
    if (jumlahMhs > MAX_MHS) {
        cout << "Jumlah Mahasiswa melebihi batas maksimal: " << MAX_MHS << endl;
        return 1;
    }

    cout << endl;
    cout <<  "-- Input Data Mahasiswa -- ";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: "; 
        // membersihkan newline character dari input sebelumnya
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, mhs[i].nama); // untuk menangkap spasi pada nama
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = rata2NilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << endl;
    cout << "-- Data Mahasiswa --" << endl;
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "==========================" << endl;
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    cout << "==========================" << endl;
    return 0;
}
```

#### Output:
<img width="1090" height="94" alt="image" src="https://github.com/user-attachments/assets/6f7cf30e-8828-4101-a1f7-32b8dfbd3f22" />

<img width="1333" height="825" alt="image" src="https://github.com/user-attachments/assets/682a4a11-eace-4f3b-99cc-eade85987561" />

[Penjelasan Program]


#### Full code screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b5ca68d8-5584-463a-802a-472d0afe2ba7" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/7f4b3b36-d092-485b-b672-4b55ad098842" />






### 2. Program Pelajaran Dengan Menggunakan ADT (Abstract Data Type)
<img width="863" height="537" alt="image" src="https://github.com/user-attachments/assets/bf8de443-2abf-4418-bec2-d94c4ea1f3bd" />

#### 1. pelajaran.h
```h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);
#endif
```
#### 2. Pelajaran.cpp
```cpp
#include <iostream>
using namespace std;
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel; // var struct sementara
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "NamA pelajaran: " << pel.namaMapel << endl;
    cout << "nilai: " << pel.kodeMapel << endl;
}
```

#### 3. main.cpp
```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel,kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

#### Output:
<img width="1296" height="281" alt="image" src="https://github.com/user-attachments/assets/d6d28100-d6e3-4b07-94db-b3a3c3c887c2" />

[Penjelasan Program]


#### Full code screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b9d626c5-c84e-4516-bcfb-fa50f11267e3" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/05d22de7-fd82-4786-97fa-fba7593d3131" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f4627d53-4ac1-42d9-af54-b2ec2c8696ac" />




### 3. Program dibuat dengan berbagai ketentuan
<img width="738" height="104" alt="image" src="https://github.com/user-attachments/assets/5362d46d-54c2-4dc7-ad7c-36a05851d48e" />
<img width="738" height="45" alt="image" src="https://github.com/user-attachments/assets/656825bc-3166-4117-80d6-5ffba717ae3b" />



```c++
#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) { //baris
        for (int j = 0; j < 3; j++) { // kolom 
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemenArray(int arrSatu[3][3], int arrDua[3][3], int baris, int kolom) {
    int temp = arrSatu[baris][kolom];
    arrSatu[baris][kolom] = arrDua[baris][kolom];
    arrDua[baris][kolom] = temp;
}

void tukarViaPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arraySatu2D[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrayDua2D[3][3] = {
        {10,15,20},
        {25,30,35},
        {40,45,50}
    };

    cout << "--Isi Array Awal Sebelum ubah--" << endl;
    cout << "Isi Array Pertama: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nIsi Array Kedua: " << endl;
    tampilkanArray(arrayDua2D);

    //Tukar elemen dengan indeks arr
    tukarElemenArray(arraySatu2D, arrayDua2D, 1, 1); // note ini bukan baris 1 kolom satu tapi baris 2 kolom 2, array mulai dari 0
    cout << "\n--Setelah menukar elemen di [1][1]--" <<endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "Array Dua" << endl;
    tampilkanArray(arrayDua2D);

    // pointer
    int *ptrA;
    int *ptrB;

    ptrA = &arraySatu2D[0][0]; // simpan alamat 1 (baris 1 kolom 1)
    ptrB = &arrayDua2D[2][2]; // simpan alamat 50 (baris 3 kolom 3)

    cout << "\n--Menukar nilai via pointer--" << endl;
    cout << "Nilai yang ditunjuk pointerA(sebelum): " << *ptrA << endl;
    cout << "Nilai yang ditunjuk pointerB(sebelum): " << *ptrB << endl;

     tukarViaPointer(ptrA, ptrB);

    cout << "\nNilai yang ditunjuk pointerA (setelah): " << *ptrA << endl; // Akan menampilkan 50
    cout << "Nilai yang ditunjuk pointerB (setelah): " << *ptrB << endl; // Akan menampilkan 1

    cout << "\nIsi Array Final Setelah Semua Penukaran " << endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nArray Dua: " << endl;
    tampilkanArray(arrayDua2D);

}
```

#### Output:
<img width="1564" height="976" alt="image" src="https://github.com/user-attachments/assets/615f957e-8cf9-48e3-8e7c-47a40143a9dc" />

[Penjelasan Program]


#### Full code screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/09ededc6-978a-4841-8c87-ae39eaacd541" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6a575ffc-6ef7-4b1d-9efa-6af6753fc362" />








## Kesimpulan



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.







