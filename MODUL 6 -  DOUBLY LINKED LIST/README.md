# <h1 align="center">Laporan Praktikum Modul Doubly Linked List (6)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
Doubly Linked List atau DLL adalah linked list yang masing-masing elemennya memiliki 2 successor, yaitu prev(elemen sebelumnya) dan next(elemen sesudahnya). Berikut ini komponen-komponen penting dalam Doubly Linked List:

<img width="515" height="126" alt="image" src="https://github.com/user-attachments/assets/66f5d57f-f3ea-463b-804d-76eaf412a786" />

<ol>
    <li>
         First : pointer pada list yang menunjuk pada elemen pertama list
    </li>
    <li>
        Last : pointer pada list yang menunjuk pada elemen terakhir list
    </li>
    <li>
        Next : pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya
    </li>
    <li>
        Prev : pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya.
    </li>
</ol>

Dalam Doubly Linked List terdapat berbagai macam operasi:

A. Insert. Merupakan operasi yang digunakan untuk menambah elemene atau node-node baru pada list yang dimana nantinya node-node tersebut saling terhbung satu sama lain. Operasi insert terbagi menjadi 4 yaitu: Insert First, Insert Last, insert After, dan Insert Before.
<ol>
    <li>
        Insert First, menambah elemen atau node pada awal List.
    </li>
    <li>
        Insert Last, menambah elemen atau node baru pada akhir List.
    </li>
    <li>
        Insert after, Menambah elemen atau node baru setelah elemen tertentu.
    </li>
    <li>
        Insert Before, menambah elemen atau node baru sebelum elemen tertentu.
    </li>
</ol>

B. Delete. Merupakan operasi yang digunakan untuk menghapus atau menghilangkan suatu node tertentu. Node yang akan di hapus, pointer next dan prev nya akan bernilai nil. Delete juga terbagi menjadi 4 yaiu: Delete First, Delete Last, Delete After, Delete Before.
<ol>
    <li>
        Delete First, menghapus atau memutus sambungan untuk node paling awal, pindahkan first ke node selanjutnya dan putuskan sambungan antara node awal ke node selanjutnya.
    </li>
    <li>
        Delete Last, memindahkan last ke node sebelumnya sebelu kemudian node terakhir di putus dengan node sebelumnya.
    </li>
    <li>
        Delete After, Menghapus node yang berada setelah prec.
    </li>
    <li>
        Delete Before, sama seperti after namun ini sebelum prec
    </li>
</ol>

C. Update, View, dan Searching.
Proses pencarian, update data dan view data pada dasarnya sama dengan proses pada Singly linked
list. Hanya saja pada Doubly linked list lebih mudah dalam melakukan proses akses elemen, karena
bisa melakukan iterasi maju dan mundur.
Seperti halnya Singly linked list, Doubly linked list juga mempunyai ADT yang pada dasarnya sama
dengan ADT yang ada pada Singly linked list.

## Guided 

## 1. Doubly Linked List Insert
```cpp
// dll_insert.cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist


struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};


struct List { 
    address first; 
    address last; 
}; 


void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 


void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 


void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}


address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 


void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}


int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
Kode di atas merupakan bagaimana cara kita mengimplementasikan Doubly linked list(DLL) dalam C++. Pada dasarnya, DLL sama seperti SLL atau _Singly linked list_ namun yang berbeda adalah disini pada <code>struct elmList {infotype info; address next; address prev (BARU)</code> dan <code>struct List{ address first; address last(baru, karena DLL ada tambahan last juga);</code>. Kemudian pada DLL insert ini memiliki berbagai fungsi dan prosedur seperti <code>void insertFirst(List &L, address P)</code> yang digunakan untuk menambahkan elemen atau node pertama, <code>void insertLast(List &L, address P)</code> yang digunakan untuk menambahkan node bagian akhir, <code>void insertAfter(List &L, address P, address R)</code> yang digunakan untuk menambah node setelah elemen tertentu setelah R, <code>address alokasi(infotype x)</code> yang digunakan untuk membuat elemen atau node baru, dan <code>PrintInfo()</code> digunakan untuk menampilkan hasil DLL yang sudah kita buat. Pada func main kita akan menlakukan operasi-operasi dari function di atas.

## 2. Doubly Linked List Delete
```cpp
// dll_hapus.cpp
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil; 
    // Sisipkan elemen 1, 2, 3 di awal list
    insertFirst(L, alokasi(1)); 
    insertFirst(L, alokasi(2)); 
    insertFirst(L, alokasi(3)); 
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```
Penjelasan sama seperti di atas, bedanya dari namanya saja karena DLL lebih berfokus untuk melakukan operasi hapus atau delete. Terdapat <code>dealokasi</code> yang digunakan untuk mengosongkan memori elemen, <code>deleteFirst(), deleteLast(), deleteAfter()</code> yang masing masing digunakan untuk menghapus elemen atau node awal, node bagian akhir, node setelah elemen tertentu. Pada program mainnya juga sama kita akan memanggil function-function tadi untuk melakukan operasi penghapusan.

## 3. Tambahan untuk versi ADT

### 1.1 dll.h
```h
#ifndef DLL_INCLUDED
#define DLL_INCLUDED
#include <iostream>
using namespace std;
#define Nil NULL

//1. Definisikan tipe ADT
typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// 2. deklarasikan fungsi dan prosedur DLL INSERT
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address R);
address alokasi(infotype x);

// 3. deklarasikan fungsi dan prosedur DLL HAPUS/DELETE
void dealokasi(address &P);// Definisikan fungsi dealokasi untuk mengosongkan memori elemen
// hapus elemen pertama, terakhir, dan setelah elemen tertentu
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address R);

// digunakan untuk melihat isi list
void printInfo(List L);


#endif
```

Kode di atas merupakan file .h yang menggunakan tipe ADT, jadi file .h ini hanya akan berisi mendefinisikan tipe ADT seperti <code>struct</code> dan deklarasikan primitif function dan prosedur. Fungsi-Fungsi nya merupakan gabungan dari DLL Insert dan juga DLL Delete.

### 1.2 dll.cpp
```cpp
#include "dll.h"
#include <iostream>
using namespace std;
#define Nil NULL

//1. Bagian insert DLL
void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 
void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 
void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}
address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

//2. Bagian delete DLL
void dealokasi(address &P) { 
    delete P; 
    P = Nil; 
} // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}
void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}
```
Pada program dll.cpp kita akan menginclude terlebih dahulu <code>dll.h</code> kemudian kita membuat function dan isi dari function-function atau prosedur tersebut.


### 1.3 main.cpp
```cpp
#include "dll.h"
#include <iostream>
using namespace std;
#define Nil NULL

int main() {
    // bagian utama program INSERT
    // 1. deklarasi dan inisialisasi list
    List L; 
    // inisialisasi list kosong
    L.first = Nil; 
    L.last = Nil;
    // alokasi dan insert elemen
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    cout << "Isi list setelah insert: " << endl;
    printInfo(L); 

    // 2. bagian utama program DELETE
    address P; 
    deleteFirst(L, P); 
    dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); 
    dealokasi(P); // Hapus setelah first, dealokasi P
    cout << "Isi list setelah delete: " << endl;
    printInfo(L); 
    return 0; 
}
```
Ini merupakan program main atau utama untuk menjalankan atau testing dari dll.h, dll.cpp, dan main.cpp. Karena kita menggunakan ADT atau _Abstract data type_ maka jangan lupa untuk include <code>dll.h</code>


## Unguided 

### 1. Soal Membuat program Doubly Linked List
<img width="543" height="331" alt="image" src="https://github.com/user-attachments/assets/3491dce8-cfad-45fc-bbb6-fdf7e5cf860c" />

CONTOH OUTPUTNYA

<img width="386" height="320" alt="image" src="https://github.com/user-attachments/assets/55793e67-b561-41a2-b25c-406fdefaf171" />


### 1.1 Doublylist.h
```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;
#define nil NULL


// 1. definisi tipe data ADT
typedef struct ElmList *address; // pointer ke elemen list
struct kendaraan { // info kendaraan
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype; // definisikan infotype dengan tipe data kendaraan, ini infotype akan menampung isi dari struct kendaraan.
struct ElmList {
    infotype info; // info bertipe data infotype
    address next; // pointer ke elemen berikutnya
    address prev; // pointer ke elemen sebelumnya
};

struct List {
    address first; // pointer ke elemen pertama
    address last; // pointer ke elemen terakhir
};

// 2. definisi fungsi-fungsi dan prosedur primitif
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// tambahan agar sesuai permintaan output no 1
void insertFirst(List &L, address P);
address FindElmByNopol(List L, string nopol);


#endif // DOUBLYLIST_H
```

### 1.2 Doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#define nil NULL
using namespace std;

// 3. implementasi fungsi-fungsi dan prosedur primitif
void createList(List &L) {
    L.first = nil;
    L.last = nil;
}

address alokasi(infotype x) {
    address P = new ElmList; // create node baru
    P -> info = x; // tunjuk pointer ke info untuk isi data
    P -> next = nil; // pointer selanjutnya masih nul
    P -> prev = nil; // pointer sebelumnya masih nul
    return P; // mengembalikan nilai P
}

void dealokasi (address &P) {
    delete P; // menghapus P
}

void printInfo(List L) {
    address P = L.first;
    if (L.first == nil) {
        cout << "Tidak ada List atau kosong" << endl;
    } else {
        while(P != nil) {
            // Kita ubah formatnya biar sama kayak "Contoh Output"
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

void insertLast (List &L, address &P) {
    if (L.first == NULL) { // jika kondisi list kosong
        L.first = nil;
        L.last = nil;
    } else {
        address Q = L.last; // ambil node akhir yang lama(Q)
        Q -> next = P; //sambungkan next Q ke P
        P -> prev = Q; // sambungkan prev P ke q
        L.last = P; //update last atau pindah ke P
    }
}

// tambahan agar sesuai output
void insertFirst(List &L, address P) {      
    if (L.first == nil) {
        // KASUS 1: List masih kosong
        L.first = P;
        L.last = P;
    } else {
        // KASUS 2: List sudah ada isinya
        address Q = L.first; // 1. Ambil node first yang LAMA (Q)
        
        // 2. Sambungkan 2 arah
        P->next = Q;        // Sambungan maju: P -> Q
        Q->prev = P;        // Sambungan mundur: P <- Q
        
        // 3. Update pointer First
        L.first = P;
    }
}
// Fungsi pencarian untuk cek duplikat
address FindElmByNopol(List L, string nopol) {
    address P = L.first;
    while (P != nil) {
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next;
    }
    return nil; // Gak ketemu
}
```

### 1.3 Program main.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    List L;        // buat list
    createList(L); // panggil createList untuk L.first = nil dan L.last = nil

    address P;
    infotype data;

    cout << "=== PROGRAM DATA KENDARAAN DENGAN DOUBLY LINKED LIST" << endl;
    cout << "=== SOAL NO 1. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;

    for (int i = 0; i < 4; i++) {//misal kita akan buat 4 input list
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;

        // cek duplikat dengan panggil finElmByNopol
        if (FindElmByNopol(L, data.nopol) != nil) {
            // Jika KETEMU (tidak nil), cetak error
            cout << "nomor polisi sudah terdaftar" << endl; 
            
            // Kita tetap minta input sisanya, tapi dibuang
            // agar sesuai alur di gambar
            string buangWarna;
            int buangTahun;
            cout << "masukkan warna kendaraan: ";
            cin >> buangWarna;
            cout << "masukkan tahun kendaraan: ";
            cin >> buangTahun;
        } else {
            // Jika TIDAK KETEMU, lanjutkan input
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            
            // Alokasi untuk node baru
            P = alokasi(data);
            // Kita pakai insertFirst agar outputnya terbalik
            // (D004, D003, D001)
            insertFirst(L, P);
        }
        if (i < 3) {
            cout << endl;
        }
    }

    cout << "\nData list 1" << endl;
    printInfo(L);
}
```

#### Output:
<img width="1628" height="749" alt="image" src="https://github.com/user-attachments/assets/1e0ea886-daa6-42e5-9b3c-9a456f32323c" />
Untuk kode di atas atau soal pertama, kita diminta untuk membuat DLL atau Doubly linked list dengan menggunakan ADT. Pada file <code>Doublylist.h</code> akan menyimpan definisi tipe ADT yang dimana berisi struct kendaraan yang nantinya digunakan sebagai variabel infotype dan juga mendeklarasikan <code>ElmList</code> yang merupakan node dan isinya ada info(isi data), next(pointer kedepan), prev(pointer mundur ke belakang). Kemudian tambah struct <code>List</code> yang digunakan untuk First dan last(ini akan berguna untuk searching, insert, dan delete). Setelah itu definisikan juga fungsi dan prosedur primitif yang nantinya akan diimplementasikan pada <code>Doublylist.cpp</code> yang dimana terdiri dari <code>CreateList, alokasi, printInfo, insertLast, InsertFirst, dan FindElmByNopol</code>

Selanjutnyaa buat file Doublylist.cpp untuk mengimplementasikan fungsi ataupun prosedur dan main program nantinya akan menjadi program utama dalama menjalankan seluruh operasi pada Doubly Linked List.


#### Full code screenshot:

#### 1.1. Screenshot file .h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/5b08d9a5-d6b0-4041-9170-681aa2884e1b" />

#### 1.2. Screenshot file Doublylist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/448bd379-1751-43b8-99a0-d8d535d1cc81" />

#### 1.3. Screenshot file main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/55a1cd56-715e-401a-9a8c-c1b510935e01" />









### 2. Lanjutan dari no 1, ini membuat fungsi pencarian
<img width="953" height="287" alt="image" src="https://github.com/user-attachments/assets/85c9d0eb-e9f4-469b-b223-953708bd55bb" />


### 2.1 Doublylist.h
```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;
#define nil NULL

// 1. definisi tipe data ADT
typedef struct ElmList *address; // pointer ke elemen list
struct kendaraan { // info kendaraan
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype; // definisikan infotype dengan tipe data kendaraan, ini infotype akan menampung isi dari struct kendaraan.
struct ElmList {
    infotype info; // info bertipe data infotype
    address next; // pointer ke elemen berikutnya
    address prev; // pointer ke elemen sebelumnya
};

struct List {
    address first; // pointer ke elemen pertama
    address last; // pointer ke elemen terakhir
};

// 2. definisi fungsi-fungsi dan prosedur primitif
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// tambahan agar sesuai permintaan output no 1
void insertFirst(List &L, address P);
address FindElmByNopol(List L, string nopol);

//untuk soal no 2 lanjutan dari no 1
address findElm(List L, string nopol);


#endif // DOUBLYLIST_H

```

### 2.2 Program Doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#define nil NULL
using namespace std;

// 3. implementasi fungsi-fungsi dan prosedur primitif
void createList(List &L) {
    L.first = nil;
    L.last = nil;
}

address alokasi(infotype x) {
    address P = new ElmList; // create node baru
    P -> info = x; // tunjuk pointer ke info untuk isi data
    P -> next = nil; // pointer selanjutnya masih nul
    P -> prev = nil; // pointer sebelumnya masih nul
    return P; // mengembalikan nilai P
}

void dealokasi (address &P) {
    delete P; // menghapus P
}

void printInfo(List L) {
    address P = L.first;
    if (L.first == nil) {
        cout << "Tidak ada List atau kosong" << endl;
    } else {
        while(P != nil) {
            // Kita ubah formatnya biar sama kayak "Contoh Output"
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

void insertLast (List &L, address &P) {
    if (L.first == NULL) { // jika kondisi list kosong
        L.first = nil;
        L.last = nil;
    } else {
        address Q = L.last; // ambil node akhir yang lama(Q)
        Q -> next = P; //sambungkan next Q ke P
        P -> prev = Q; // sambungkan prev P ke q
        L.last = P; //update last atau pindah ke P
    }
}

// tambahan agar sesuai output
void insertFirst(List &L, address P) {      
    if (L.first == nil) {
        // KASUS 1: List masih kosong
        L.first = P;
        L.last = P;
    } else {
        // KASUS 2: List sudah ada isinya
        address Q = L.first; // 1. Ambil node first yang LAMA (Q)
        
        // 2. Sambungkan 2 arah
        P->next = Q;        // Sambungan maju: P -> Q
        Q->prev = P;        // Sambungan mundur: P <- Q
        
        // 3. Update pointer First
        L.first = P;
    }
}
// Fungsi pencarianuntuk cek duplikat
address FindElmByNopol(List L, string nopol) {
    address P = L.first;
    while (P != nil) {
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next;
    }
    return nil; // Gak ketemu
}


// Untuk nomor 2
address findElm(List L, string nopol){
    address P = L.first; // taruh P di elemen atau node pertama
    while (P != nil) {
        if (P -> info.nopol == nopol) {
            return P;
        }
        P = P -> next;
    }
    return nil;
}
```

### 2.3 Program main.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    List L;        // buat list
    createList(L); // panggil createList untuk L.first = nil dan L.last = nil

    address P;
    infotype data;

    cout << "=== PROGRAM DATA KENDARAAN DENGAN DOUBLY LINKED LIST" << endl;
    // cout << "=== SOAL NO 1. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;

    // for (int i = 0; i < 4; i++) {//misal kita akan buat 4 input list
    //     cout << "Masukkan nomor polisi: ";
    //     cin >> data.nopol;

    //     // cek duplikat dengan panggil finElmByNopol
    //     if (FindElmByNopol(L, data.nopol) != nil) {
    //         // Jika KETEMU (tidak nil), cetak error
    //         cout << "nomor polisi sudah terdaftar" << endl; 
            
    //         // Kita tetap minta input sisanya, tapi dibuang
    //         // agar sesuai alur di gambar
    //         string buangWarna;
    //         int buangTahun;
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> buangWarna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> buangTahun;
    //     } else {
    //         // Jika TIDAK KETEMU, lanjutkan input
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> data.warna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> data.thnBuat;
            
    //         // Alokasi untuk node baru
    //         P = alokasi(data);
    //         // Kita pakai insertFirst agar outputnya terbalik
    //         // (D004, D003, D001)
    //         insertFirst(L, P);
    //     }
    //     if (i < 3) {
    //         cout << endl;
    //     }
    // }

    // cout << "\nData list 1" << endl;
    // printInfo(L);

    cout << "\n=== SOAL NO 2. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;
    
    // masukkan data 1-3
    data.nopol = "D001"; 
    data.warna = "hitam"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D003"; 
    data.warna = "putih"; 
    data.thnBuat = 70;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D004"; 
    data.warna = "Kuning"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    // Mulai pencarian
    string nopolCari;
    address P_ditemukan;
    cout << "Masukkan Nomor Polisi yang akan dicari: ";
    cin >> nopolCari;
    // panggil findElm
    P_ditemukan = findElm(L, nopolCari);

    // cek hasil
    if (P_ditemukan != nil) {
        cout << "Nomor Polisi : " << P_ditemukan->info.nopol << endl;
        cout << "Warna        : " << P_ditemukan->info.warna << endl;
        cout << "Tahun        : " << P_ditemukan->info.thnBuat << endl;
    } else {
        cout << "Data yang anda cari tidak dapat ditemukan" << endl;
    }

    return 0;

}
```

#### Output
<img width="1544" height="877" alt="image" src="https://github.com/user-attachments/assets/d9e233dc-62a5-464c-971b-9162227d0dc2" />
Untuk soal bagian kedua sama kodenya seperti nomor satu, bedanya kita ditugaskan untuk mencari elemen dengan nomor polisi D001 dan membuat fungsi baru yaitu <code>findElm</code> yang digunakan untuk melakukan pencarian data tertentu pada suatu node, nantinya output akan menampilkan hasil yang sesuai jika nomor polisi yang dicari benar dan jika tidak ada, outputnya akan menampilkan bahwa nomor polisi yang dicari tidak ada. Sama seperti sebelumnya buat adt function terlebih dahulu fi <code>Doublylist.h</code> kemudian implementasikan di <code>Doublylist.cpp</code> yang nantinya akan di jalankan oleh program main.cpp.


#### Full Code Screenshot
#### 2.1. Screenshot file .h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/0c912376-a14c-4a77-84b1-e648eadaacc3" />


#### 2.2. Screenshot file Doublylist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/8ad819be-496d-493f-a882-f08656e18ae7" />


#### 2.3. Screenshot file main.cpp

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/0579bac3-7cf7-42bb-b1ba-5a605ca4098b" />



### 3. Lanjutan dari nomor2 sebelumnya, bedanya ini disuruh menghapus
<img width="897" height="656" alt="image" src="https://github.com/user-attachments/assets/b72d595d-edd4-4167-9492-61c271a70cb5" />


### 3.1 .h
```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;
#define nil NULL

// 1. definisi tipe data ADT
typedef struct ElmList *address; // pointer ke elemen list
struct kendaraan { // info kendaraan
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype; // definisikan infotype dengan tipe data kendaraan, ini infotype akan menampung isi dari struct kendaraan.
struct ElmList {
    infotype info; // info bertipe data infotype
    address next; // pointer ke elemen berikutnya
    address prev; // pointer ke elemen sebelumnya
};

struct List {
    address first; // pointer ke elemen pertama
    address last; // pointer ke elemen terakhir
};

// 2. definisi fungsi-fungsi dan prosedur primitif
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// tambahan agar sesuai permintaan output no 1
void insertFirst(List &L, address P);
address FindElmByNopol(List L, string nopol);

//untuk soal no 2 lanjutan dari no 1
address findElm(List L, string nopol);

// untuk soal no 3
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);


#endif // DOUBLYLIST_H

```

### 3.2 Program Doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#define nil NULL
using namespace std;

// 3. implementasi fungsi-fungsi dan prosedur primitif
void createList(List &L) {
    L.first = nil;
    L.last = nil;
}

address alokasi(infotype x) {
    address P = new ElmList; // create node baru
    P -> info = x; // tunjuk pointer ke info untuk isi data
    P -> next = nil; // pointer selanjutnya masih nul
    P -> prev = nil; // pointer sebelumnya masih nul
    return P; // mengembalikan nilai P
}

void dealokasi (address &P) {
    delete P; // menghapus P
}

void printInfo(List L) {
    address P = L.first;
    if (L.first == nil) {
        cout << "Tidak ada List atau kosong" << endl;
    } else {
        while(P != nil) {
            // Kita ubah formatnya biar sama kayak "Contoh Output"
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

void insertLast (List &L, address &P) {
    if (L.first == NULL) { // jika kondisi list kosong
        L.first = nil;
        L.last = nil;
    } else {
        address Q = L.last; // ambil node akhir yang lama(Q)
        Q -> next = P; //sambungkan next Q ke P
        P -> prev = Q; // sambungkan prev P ke q
        L.last = P; //update last atau pindah ke P
    }
}

// tambahan agar sesuai output
void insertFirst(List &L, address P) {      
    if (L.first == nil) {
        // KASUS 1: List masih kosong
        L.first = P;
        L.last = P;
    } else {
        // KASUS 2: List sudah ada isinya
        address Q = L.first; // 1. Ambil node first yang LAMA (Q)
        
        // 2. Sambungkan 2 arah
        P->next = Q;        // Sambungan maju: P -> Q
        Q->prev = P;        // Sambungan mundur: P <- Q
        
        // 3. Update pointer First
        L.first = P;
    }
}
// Fungsi pencarianuntuk cek duplikat
address FindElmByNopol(List L, string nopol) {
    address P = L.first;
    while (P != nil) {
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next;
    }
    return nil; // Gak ketemu
}


// Untuk nomor 2
address findElm(List L, string nopol){
    address P = L.first; // taruh P di elemen atau node pertama
    while (P != nil) {
        if (P -> info.nopol == nopol) {
            return P;
        }
        P = P -> next;
    }
    return nil;
}


// untuk no 3
void deleteFirst(List &L){
    if (L.first == nil) { // jika kondisi kosong
        cout << "List kosong dan tidak ada yang bisa dihapus" << endl;
    } else {
        address P = L.first;
        if (L.first == L.last) { // Jika hanya ada 1 node
            L.first = nil;
            L.first = nil;
        } else {
            L.first = P -> next; // pindah firs ke elemen 2
            L.first -> prev = nil; // putus sambungan dari prev ke elemen pertama(yang akan dihapus)
        }
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    if (L.last == nil) {
        cout << "list kosong dan tidak ada yang bisa dihapus" << endl;
    } else {
        address P = L.last;
        if (L.first = L.last) { // jika hanya ada 1 node
            L.first = nil;
            L.last = nil;
        } else {
            L.last = P -> prev; //pindah last ke node sebelum akhir;
            L.last -> next = nil; //putus sambungan 'next' dari last baru ke elemen akhir(yang akan dihapus)
        }
        dealokasi(P);
    }
}
void deleteAfter(List &L, address Prec) {
    if (Prec != nil && Prec->next != nil) {
        address P = Prec->next; // P adalah node yang mau dihapus
        
        if (P == L.last) {
            // Kasus 1: Node yang dihapus adalah node terakhir
            deleteLast(L);
        } else {
            // Kasus 2: Node yang dihapus di tengah
            Prec->next = P->next; // 1. Sambungan 'next' Prec melompati P
            (P->next)->prev = Prec; // 2. Sambungan 'prev' dari (P->next) melompati P
            dealokasi(P);
        }
    } else {
        cout << "Tidak bisa delete after, node Prec tidak valid." << endl;
    }
}
```

### 3.3 Program main.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    List L;        // buat list
    createList(L); // panggil createList untuk L.first = nil dan L.last = nil

    address P;
    infotype data;

    cout << "=== PROGRAM DATA KENDARAAN DENGAN DOUBLY LINKED LIST" << endl;
    // cout << "=== SOAL NO 1. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;

    // for (int i = 0; i < 4; i++) {//misal kita akan buat 4 input list
    //     cout << "Masukkan nomor polisi: ";
    //     cin >> data.nopol;

    //     // cek duplikat dengan panggil finElmByNopol
    //     if (FindElmByNopol(L, data.nopol) != nil) {
    //         // Jika KETEMU (tidak nil), cetak error
    //         cout << "nomor polisi sudah terdaftar" << endl; 
            
    //         // Kita tetap minta input sisanya, tapi dibuang
    //         // agar sesuai alur di gambar
    //         string buangWarna;
    //         int buangTahun;
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> buangWarna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> buangTahun;
    //     } else {
    //         // Jika TIDAK KETEMU, lanjutkan input
    //         cout << "masukkan warna kendaraan: ";
    //         cin >> data.warna;
    //         cout << "masukkan tahun kendaraan: ";
    //         cin >> data.thnBuat;
            
    //         // Alokasi untuk node baru
    //         P = alokasi(data);
    //         // Kita pakai insertFirst agar outputnya terbalik
    //         // (D004, D003, D001)
    //         insertFirst(L, P);
    //     }
    //     if (i < 3) {
    //         cout << endl;
    //     }
    // }

    // cout << "\nData list 1" << endl;
    // printInfo(L);

    // cout << "\n=== SOAL NO 2. Implementasi pada main.cpp unuk menambah data kendaraan" << endl;
    
    // masukkan data 1-3
    data.nopol = "D001"; 
    data.warna = "hitam"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D003"; 
    data.warna = "putih"; 
    data.thnBuat = 70;
    P = alokasi(data);
    insertFirst(L, P);

    data.nopol = "D004"; 
    data.warna = "Kuning"; 
    data.thnBuat = 90;
    P = alokasi(data);
    insertFirst(L, P);

    // // Mulai pencarian
    // string nopolCari;
    // address P_ditemukan;
    // cout << "Masukkan Nomor Polisi yang akan dicari: ";
    // cin >> nopolCari;
    // // panggil findElm
    // P_ditemukan = findElm(L, nopolCari);

    // // cek hasil
    // if (P_ditemukan != nil) {
    //     cout << "Nomor Polisi : " << P_ditemukan->info.nopol << endl;
    //     cout << "Warna        : " << P_ditemukan->info.warna << endl;
    //     cout << "Tahun        : " << P_ditemukan->info.thnBuat << endl;
    // } else {
    //     cout << "Data yang anda cari tidak dapat ditemukan" << endl;
    // }



    cout << "\n=== SOAL NO 3. Implementasi pada main.cpp unuk menghapus dengan berbagai macam Delete" << endl;

    string nopolHapus;
    address P_Hapus, Prec;
    cout << "Masukan nomor polisi yang akan dihapus: ";
    cin >> nopolHapus;

    // cari node yang mau di hapus
    P_Hapus = findElm(L, nopolHapus);

    // cek apakah nodenya ada
    if (P_Hapus != nil) {
        // ini kondisi node ketemu dan tentukan mau pake delete apa dari ketiga delete yang sudah dibuat
        if (P_Hapus == L.first) { // kondisi jika P(hapus) ada di pertama
            deleteFirst(L);
        } else if (P_Hapus == L.last) { // kondisi jika P(hapus) ada di akhir
            deleteLast(L);
        } else {
            Prec = P_Hapus -> prev;
            deleteAfter(L, Prec); // hapus node setelah prec
        }

        cout << "Data dengan nomor polisii " << nopolHapus << " berhasil dihapus." << endl;

        // tampilkan isi
        cout << "\nData List 1(setelah dihapus)" <<endl;
        printInfo(L);
    } else {
        cout << "Tidak ketemu dan tidak ada yang bisa dihapus" << endl;
    }
 return 0;
}
```

#### Output

<img width="1303" height="480" alt="image" src="https://github.com/user-attachments/assets/8423ce09-0e59-4c6e-a62b-7a440e0db66e" />

Soal bagian 3 masih menggunakan kode lanjutan dari no 1-2 yang dimana sebelumnya sudah melakukan <code>Insert dan Searching</code>, kali ini akan dilakukan delete dengan membuat prosedur <code>deleteFIrst, deleteLast, deleteAfter</code>. Tujuannya adalah pengguna bisa menginputkan node mana yang ingin dihapus dan program akan menentukan akan menggunakan jenis penghapusan yang mana sesuai dengan letak node yang ada, jika list kosong maka tidak akan adanya penghapusan.


#### Full Code Screenshot
#### 3.1. Screenshot file .h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/64736220-bc87-4a01-ac94-f7fae7d6d83b" />



#### 3.2. Screenshot file Doublylist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a791d18e-4488-43db-b94e-543924ae0d14" />



#### 3.3. Screenshot file main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/08483ff5-9065-46e1-bcee-3591742618e9" />








## Kesimpulan
Berdasarkan dari praktikum modul 6 yang dilaksanakan secara daring atau online, saya mampu perlahan-lahan memahami terkait bagaimana cara mengimplementasikan Doubly Linked List (DLL). Pernedaan antara SLL dan DLL ialah pada DLL ada penambahan pointer <code>prev</code> pada setiap elemen atau node(node bentuknya kotak) dan pointer <code>last</code> pada struktur List. Dengan adanya penambahan kedua pointer tersebut memberikan hal yang bermanfaat seperti :
<ol>
    <li>
        Traversal dua arah. Ya dengan adanya next dan prev memungkinkan penelusuran tidak hanya maju kedepan namun bisa mundur ke belakang dengan menggunakan prev.
    </li>
    <li>
        Efisien. Pada insertLast dan deleteLast menjadi sangat efisien karena tidak perlu melakukan traversal dari node awal hingga akhir, kita bisa langsung ke elemen akhir dengan pointer last.
    </li>
</ol>

Meskipun itu juga pada DLL kali ini memang banyak menimbulkan manfaat namun kekurangannya adalah code semakin kompleks karena harus mengelola 2 sambungan pointer setiap node terhadap node lainnya, namun tetap saja dengan menggunakan DLL lebih efisien daripada SLL yang hanya memiliki 1 pointer next.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.










