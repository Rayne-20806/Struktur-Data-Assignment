# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT) (3)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### 1. Apa Itu ADT?
Pada Modul kali ini membahas ADT atau Abstract Data Type. ADT adalah Type dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan definisi invarian dari TYPE dan aksioma yang berlaku. ADT definisi dari STATIK.

Definisi type dari sebuah ADT dapat mengandung sebuah definisi dari ADT lain:
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
        File Header (<code>.h</code>): File berisi definisi atau spesifikasi dari ADT. di dalamnya terdapat deklarasi struct dan prototype(deklarasi awal) dari semua fungsi atau prosedur.
    </li>
    <li>
        File implementasi(<code>.cpp</code>): File ini berisi realisasi atau kode program (body) dari setiap fungsi dan prosedur yang sudah dideklarasikan di file header. File ini meng <code>#include</code> file headernya sendiri.
    </li>
    <li>
        File Driver/Utama(<code>main.cpp</code>): Program utama yang akan menggunakan ADT tersebut. File ini juga meng #inclode file header (<code>.h</code>) untuk bisa mengakses tipe data dan fungsi yyang telah didefinisikan.
    </li>
</ol>

### 4. Cara Menjalankan Program ADT di VS-CODE
Karena program-program terpecah menjadi beberapa file (<code>.h </code>) dan (<code>.cpp</code>), cara menjalankannya berbeda dengan menjalankan file c++ yang berjumlah satu. Jadi misalkan kita mempunyai 3 file yaitu mahasiswa.h sebagai header, mahasiswa.cpp merupakan body dari setia <code>fungsi dan prosedur, dan main.cpp</code> yang bergfungsi sebagai program utama yang akan menggunakan ADT tersebut.
<ol>
    <li>
        Pastikan ketiga file tadi dalam satu folder yang sama di dalam VS-CODE, karena wajib 1 folder berisikan file <code>(.h), (.cpp), (main.cpp)</code>.
    </li>
    <li>
        Kemudian buka terminal dan gunakan perintah <code>g++ .\main.cpp .\mahasiswa.cpp -o mhs </code>. Ini adalah file-file yang akan dikompilasi, kita harus menyertakan semua file <code>.cppp</code> agar kompiler bisa menggabungkan logika dari program utama dan implementasi ADT. file .h tidak perlu disertakan karena sudah diinclude di file .cpp.
    </li>
    <li>
        Kemudian langsung saja jalankan perintah <code>.\mhs.exe</code> maka program akan berjalan.
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
Program ini bertindak sebagai file header. Didalam program ini mendefinisikan struct mahasiswa yang berisi variabel untuk nim, nilai1, dan nilai2. Selain itu, file ini mendeklarasikan fungsi dan prosedur yang beroperasi pada struct tersebut, yaitu <code>void inputMhs() dan float rata2()</code>. Adanya include (<code>#ifnde, #define, #endif</code>) memastikan bahwa isi file ini hanya dimasukkan sekali oleh compiler untuk menghidari error duplikasi.

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
Program ini berisi implementasi atau kode Program (body) dari fungsi-fungsi yang telah dideklarasikan sebelumnya di <code>mahasiswa.h</code> . Prosedur <code>inputMhs()</code> digunakan untuk meminta input dari pengguna dan menyimpannya ke dalam variabel struct mahasiswa. Fungsi/function dari <code>float rata2()</code> digunakan untuk menerima sebuah struct mahasiswa, menghitung nilai rata-rata antara nilai1 dan nilai2, lalu mengembalikan hasil perhitungan dalam bentuk float.

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
Program ini merupakan yang utama menggunakan ADT mahasiswa. File ini meng-include <code>"mahasiwa.h"</code> agar dapat mengenali struct dan fungsi yang telah kita buat. Di dalam <code>main()</code>, telah dibuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur <code>inputMhas()</code> untuk mengisi data, yang terakhir akan memanggil <code>fungsi rata2()</code> untuk menampilkan hasil dari perhitungan rata-rata.



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

Program diatas dibuat untuk menyimpan data mahasiswa dengan max 10 ke dalam sebuah array dengan field nama, nim uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari fungsi dengan rumus  <code>0.3*uts+0.4*uas+0.3*tugas</code>. Seperti biasa jangan lupa deklarasikan atau <code>#include</code> library untuk c++. Kemudian program ini mendeklarasikan sebuah <code>Struct mahasiswaArray</code> yang berisi beberapa variabel atau data untuk mahasiswa dan buat <code>fungsi rata2NilaiAkhir</code> yang nantinya akan digunakan untuk hasil akhir operasi beberapa variabel di dalam struct serta deklarasikan var konstanta untuk maks mahasiswa. Pada program <code>main</code> dideklarasikan kembali struct dengan var <code>mhs[MAX_MHS];</code> yang digunakan sebagai batasan untuk inputan nanti. Selain itu juga di program main ini akan meminta pengguna menginputkan jumlahMhs dan mengecek batasan apakah sesuai, kemudian ada inputan data untuk mahasiswa dan yang terakhir akan menampilkan data-data mahasiwa yang sebelumnya sudah diinputkan oleh pengguna.


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

 1. pelajaran.h
File <code>pelajaran.h</code> digunakan untuk mendfinisikan sebuah ADT pelajaran. Di dalam program ini terdapat <code>struct pelajaran : namaMapel dan kodeMapel</code> yang nantinya akan menerima sebuah string. Kemudian ada prosedur <code>void tampil_pelajaran(pelajaran pel)</code> yang nantinya akan digunakan di program lainnya untuk menampilkan pelajaran. 
2. pelajaran.cpp
Program <code>pelajaran.cpp</code> ini sebagai implementasi bagaimana nantinya setiap fungsi/prosedur berjalan, seperti fungsi <code>pelajaran create_pelajaran()</code> dan prosedur menampilkan pelajaran <code>voide tampil_pelajaran()</code>. Program ini akan mengisi data dan juga menerima data khususnya pada fungsi.
 3. main.cpp
Program <code>main.cpp</code> ini merupakan program utama pada ADT yang nantinya akan meng <code>#include pelajaran.h</code> yang nantinya digunakan untuk membuat dan memanipulasi objek <code>pelajaran</code> dengan cara memanggil fungsi dan prosedur yang sudah ada tadi. Kemudiann program ini nantinya akan menampilkan output dari prosedur <code>tampil_pelajaran(pel)</code>.



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

Program ini dibuat dengan berbagai ketentuan untuk membuat dua buah array 2 dimensi(baris x kolom) yang nantinya akan menukarkan dengan fungsi posisi tertentu dan menukarkan dengan variabel yang ditunjuk oleh pointer. Array disini mulai dari 0 yang dimana [0][0] memiliki arti baris 1 dan kolom 1.

Program ini memiliki prosedur <code>void tampilkanArray()</code> yang didalamnya berisi perulangan 1(untuk baris) dan perulangan 2(untuk kolom) atau nested loop(perulangan dalam perulangan) yang nantinya akan menampilkan hasil Array. Kemudian ada prosedur <code>void tukarElemenArray</code> yang akan digunakan sebagai operasi untuk menukar array sesuai baris dan kolom, ini juga di deklarasikan variabel <code>temp</code> untuk menyimpan nilai <code>arrSatu[baris][kolom]</code> agar tidak hilang saat proses pertukaran. Selanjutnya yang terpenting adalah prosedur <code>tukarViaPointer()</code> yang sama juga digunakan untuk proses pertukaran, bedanya dengan menukar biasa dengan pointer yaitu pointer akan menukarkan isi dari variabel atau nilai yang ditunjuk oleh pointer nantinya. Karena pointer ini menerima alamat memori sebagai argumen dan fungsinya bisa mengubah nilai asli variabel secara fleksibel. Pada Program <code>main()</code> berisi hal penting dalam mendeklarasikan dua array 2d yang berukuran 3 x 3(baris x kolom) dan akan menampilkan isinya. Kemudian program main ini akan melakukan pertukaran pertama elemen posisi dengan <code>tukerElemenArray()</code> dan setelahnya melakukan pertukaran dengan <code>tukarViaPointer()</code>.


#### Full code screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/09ededc6-978a-4841-8c87-ae39eaacd541" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6a575ffc-6ef7-4b1d-9efa-6af6753fc362" />






## Kesimpulan
Berdasarkan praktikum yang dilaksanan online, saya mendapatkan bahwa kali ini dapat memahami dan mengerti apa sebuah ADT atau _Abstract Data Type_ dalam C++. Pemahaman utama yang bisa didapat ialah sebelum mengenal ADT, biasanya menumpuk file menjadi satu, namun setelah mengenal ADT mampu memisah file-file menjadi beberapa bagian dalam 1 folder karena pendekatan ini kode menjadi terlihat terstruktur, mudah dipahami, dan gampang dikelola. Selain itu juga memahami bagaimana cara memecah dan isi masing-masing file pada program <code>.h dan .cpp</code> agar mampu mengimplementasikan ADT dan melatih kemampuan lanjutan saya terkait bahasa pemrograman C++ agar ilmu saya semakin luas.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.







