# <h1 align="center">Laporan Praktikum Modul Doubly Linked List (6)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
[PENJELASAN]


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


### 1.1 .h
```h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
using namespace std;
#include <string>


// 1. definisi tipe data ADT
typedef struct ElmList *address; // pointer ke elemen list
struct kendaraan { // info kendaraan
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype; 
struct ElmList {
    infotype info;
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


#endif // DOUBLYLIST_H

```

### 1.2 .cpp
```cpp

```

### 1.3 Program main.cpp
```cpp

```

#### Output:


#### Full code screenshot:






### 2. Lanjutan dari no 1, ini membuat fungsi pencarian
<img width="1715" height="515" alt="image" src="https://github.com/user-attachments/assets/30e52daf-0f3b-457d-91ab-db528ddf7b47" />




### 2.1 .h
```h

```

### 2.2 Program .cpp
```cpp

```

### 2.3 Program main.cpp
```cpp

```

#### Output

#### Full Code Screenshot

### 3. Lanjutan dari nomor2 sebelumnya, bedanya ini disuruh menghapus
<img width="1364" height="790" alt="image" src="https://github.com/user-attachments/assets/6add038f-013e-4365-b6df-39ca3f5277c4" />

### 2.1 .h
```h

```

### 2.2 Program .cpp
```cpp

```

### 2.3 Program main.cpp
```cpp

```

#### Output

#### Full Code Screenshot








## Kesimpulan




## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.










