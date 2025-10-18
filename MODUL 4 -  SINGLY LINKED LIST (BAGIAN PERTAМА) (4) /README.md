# <h1 align="center">Laporan Praktikum Modul Singly Linked List (Bagian Pertama) (4)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
## 1.Linked List dengan pointer
Pada Modul kali ini mempelajari terkait dengan Linked List atau tepatnya bisa disebut sebagai list saja tetapi kali ini  dengan menggunakan pointer. SLL inisalah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berhubungan atau terikat dan bersifat fleksibel karena dapat tumbuh dan berkurang sesuai kebutuhan. Data yang disimpan biasanya tunggal atau majemuk. Tunggal berarti terdiri dari <code>satu variabel saja dan satu tipe data</code>. Sementara majemuk kumpulan data(record) yang di dalamnya terdiri dari <code>berbagai tipe data</code>, contoh data mahasiswa terdiri dari <code>nama string, NIM int, Alamat string</code>.

Alasan memakai pointer:
<ol>
    <lI>
        <code>Dinamis VS Statis</code>, pointer bersifat dinamis yang artinya dapat menambah atau mengurangi elemen kapan saja sesuai kebutuhan. Sementara itu array bersifat statis yang artinya ukurannya harus ditentukan sejak awal sebelum membuat dan tidak dapat diubah lagi setelah itu.
    </lI>
    <li>
        <code>Saling Berkait</code>, Linked list yang saling berikat atau bergantungan dimana elemen saling menunjuk satu sama lain(1-2-3-4).
    </li>
    <li>
        <code>Efisien</code>, lebih mudah untuk melakukan insert(tambah) dan delete(hapus) dimanapun, contohnya awal, akhir, tengah tanpa menggeser elemen lainnya seperti pada array.
    </li>
</ol>

## 2. Singly Linked List.
Merupakan model ADT linked list yang hanya memiliki satu arah pointer, terdapat sebuah kotak / elemen yang terdiri dari dua bagian, bagian kiri disebut dengan <code>data</code> yang digunakan untuk menyimpan informasi utama seperti nilai dari variabel. Kemudian ada <code>Next atau suksesor</code> yang digunakan untuk menghubungkan antar elemen sebelumnya dengan elemen selanjutnya.

Sifat dari singly Linked List: Hanya memerlukan satu buah pointer, Node akhir menunjuk ke nil kecuali untuk list circular, hanya dapa melakukan pembacaan maju, lebih mudah melakukan penyisipan, pencarian sekuensial dilakukan  jika data tidak terurut.

Istilah-istilah penting: first/heaad, next, NULL/nil, Node/Simpul/Elemen.

### 2.1 Pembentukan Komponen-Komponen List
<ol>
    <li>
        Pembentukan List (CreateList), sebuah prosedur yang digunakan untuk membuat sebuah list baru yang kosong. Prosesnya dengan mengatur pointer <code>first</code> menjadi <code>Nil</code>.
    </li>
    <li>
        Alokasi Memori, merupakan fungsi memesan gerbong atau node baru di memori. syntax <code>alokasi()</code>.
    </li>
    <li>
        Dealokasi, digunakan untuk menghapus sebuah memory address yang tersimpan atau telah dialokasikan dalam bahasa pemrogramn C. syntax <code>delete p</code>.
    </li>
    <li>
        Pengecekan List, Fungsi yang digunakan untuk mengecek apakah list itu kosong atau tidak. Akan mengembalikan nilai true(kosong) atau false(tidak kosong). Syntax <code>isEmpty()</code>.
    </li>
</ol>

### 2.2 Insert
Dalam setiap metode memasukkan, pasi ada istilah yang namanya insert(penambahan). Macam-macam insert: <code>Insert First, Insert Last, Insert After( memasukkan data ke dalam list yang diletakkan setelah node tertentu yang ditunjuk oleh user)</code>.

### 2.3 View
Merupakan operasi dasar pada list yang menampilkan isi node/simpul dengan suatu penelusuran list.
Mengunjungi setiap node kemudian menampilkan data yang tersimpan pada node tersebut.
Semua fungsi dasar di atas merupakan bagian dari ADT dari singgle linked list, dan aplikasi pada bahasa
pemrograman Cp semua ADT tersebut tersimpan dalam file <code>*.c dan file *.h.</code>


## Guided 
## 1. Program Implementasi SLL dan cara membuat SLL
## 1.1 list.h

```h
#ifndef LIST_H
#define LIST_H
#define nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```


## 1.2 list.cpp
```cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```


## 1.3 main.cpp
```cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```


## 2. Lanjutan Program SLL dengan penambahan bagaimana cara delete di SLL
## 2.1 list.h
```h
#ifndef LIST_H
#define LIST_H
#define nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &list);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

## 2.2 list.cpp
```cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == nil){
            List.first->next = nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != nil && nodePrev->next != nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
    F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = nil; 
    cout << "List sudah terhapus!" << endl;
}
```


## 2.3 main.cpp
```cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    //lanjutan
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    
    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}

//note: jika ingin hapus list maka lepas dulu pointer previousnya agar bisa hapus node
```


## Unguided 

### 1. Program SLL(Single Linked List) dengan menggunakan ADT
<img width="704" height="794" alt="image" src="https://github.com/user-attachments/assets/3a8d762e-79a8-46e1-a316-7a77d2628948" />
<img width="704" height="237" alt="image" src="https://github.com/user-attachments/assets/564f46e3-2dde-4dc9-bcfb-3757b1690850" />

### 1.1 Program .h
```h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List {
    address first;
};

// prosedur and function
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
#endif
```

### 1.2 Singlylist.cpp
```cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

// prosedur and function
void CreateList(List &L) {
    L.first = nil;
}

//buat gerbong atau node baru
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = nil;
    return P;
}

// Hapus node 
void dealokasi(address &P) {
    delete P;
}

// digunakan untuk menampilkan output dari node atau gerbong
void printInfo(List L){
    address  P = L.first;
    if (P == nil) {
        cout << "Listnya kosong" << endl;
    } else {
        while (P != nil) {
            cout << P -> info << " ";
            P = P -> next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P){
    P -> next = L.first;
    L.first = P;
}
```

### 1.3 Program main.cpp
```cpp
#include "Singlylist.h"

#include <iostream>
using namespace std;

int main () {
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

#### Output:
<img width="1623" height="182" alt="image" src="https://github.com/user-attachments/assets/4c31e9d8-c4c6-491c-a95d-b3c7e1ccacc4" />

Program ini dibuat dengan menerapkann Abstract Data Type (ADT) dan Single Linked List (SLL). Tujuannya untuk membuat struktur data, alokasi memori. Program ini dipecah menjadi 3 file seperti biasa karena menggunakan ADT:
<ol>
    <li>
        <code>Singlylist.h</code>, Setiap menggunakan ADT pasti ada .h karena digunakan untuk antarmuka di ADT linglylist ini. File ini berisi infotype sebagai int, struct elmlist sebagai yang nantinya akan digunakan untuk node dan menyimpan info dan next, serta struct List yang digunakan sebagai menyimpan pointer first. File ini juga akan mendeklarasikan beberapa function atau prosedur seperti <code>CreateList, alokasi, dealokasi, printInfo, dan insertFirst</code>.
    </li>
    <li>
        <code>Singlylist.cpp</code>, file ini merupakan badan dari file .h yang dimana berisi semua implementasi function dan prosedur. <code>create list</code> L.first menjadi nil. <code>alokasi</code> berfungsi untuk memesan memori (new elmlist) untuk sebuah node baru, mengisinya dengan data (x), mengatur next ke nil. <code>dealokasi</code> menggunakan fitur delete dan yang terpenting <code>insertFIrst</code> digunakan untuk menyabungkan P -> next ke L.first yang lama lalu memperbarui L.first agar menunjuk ke P. <code>printInfo</code> digunakan untuk mencetak setiap info dari setiap node dengan menggunakan perulangan while loop.
    </li>
    <li>
        <code>main.cpp</code>, tentunya ini merupakan program utama dari Singly linked list ini. Program ini menginisialisasi List L , lalu secara berurutan mengalokasi dan memasukkan lima nilai (2, 0, 8, 12, 9) menggunakan insertFirst . Karena insertFirst selalu menambah di depan, urutan akhir di dalam list menjadi kebalikan dari urutan input, yaitu 9 -> 12 -> 8 -> 0 -> 2. Kemudian printInfo(L) digunakan untuk menampilkan hasil di terminal nantinya.
    </li>
</ol>

#### Full code screenshot:
#### 1. FULL BAGIAN Singlylist.h
   <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/fa4d11e3-24b1-4c9f-b2dc-813e416f07f3" />
   
#### 2. FULL BAGIAN Singlylist.cpp
   <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ed8e851e-4f02-4198-a78f-edfa244d7395" />
   
#### 3. FULL BAGIAN main.cpp
   <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/1a9dfb06-8f22-4b60-ac67-41c86b636810" />


### 2. Lanjutan dari no 1
<img width="704" height="269" alt="image" src="https://github.com/user-attachments/assets/6ac9db2d-d52b-4592-b27d-c0ac9f4ef5dc" />


#### 1. Singlylist.h
```h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List {
    address first;
};

// prosedur and function
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

//lanjutan untuk nomor 2
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);


#endif
```

#### 2. Singlylist.cpp
```cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

// prosedur and function
void CreateList(List &L) {
    L.first = nil;
}

//buat gerbong atau node baru
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = nil;
    return P;
}

// Hapus node 
void dealokasi(address &P) {
    delete P;
}

// digunakan untuk menampilkan output dari node atau gerbong
void printInfo(List L){
    address  P = L.first;
    if (P == nil) {
        cout << "Listnya kosong" << endl;
    } else {
        while (P != nil) {
            cout << P -> info << " ";
            P = P -> next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P){
    P -> next = L.first;
    L.first = P;
}

// lanjutan untuk no 2
void deleteFirst(List &L) {
    if (L.first != nil) {
        address P = L.first;
        L.first = P -> next;
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    if (L.first == nil) {
        return;
    }
    if (L.first->next == nil) {
        dealokasi(L.first);
        L.first = nil;
    } else {
        address P = L.first;
        address Prec = nil; 
        while (P->next != nil) {
            Prec = P;
            P = P->next;
        }
        
        Prec->next = nil; 
        dealokasi(P);     
    }

}
void deleteAfter(List &L, address Prec) {
    if (Prec != nil && Prec->next != nil) {
        address P = Prec->next;
        Prec->next = P->next;  
        dealokasi(P); 
    }
}
int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != nil) {
        count++;
        P = P -> next;
    }
    return count;
}
void deleteList(List &L) {
    address P = L.first;
    while (P != nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp); 
    }
    L.first = nil; 
}

```


#### 3. main.cpp
```cpp
#include "Singlylist.h"

#include <iostream>
using namespace std;

int main () {
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);


    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    cout << "\n---Soal 2 terkait delete---" << endl;

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,P4);

    printInfo(L);
    cout << "Jumlah Node: "<< nbList(L) << endl;

    deleteList(L);
    cout << "-- List Berhasil Terhapus --" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
```


#### Output:
<img width="1393" height="402" alt="image" src="https://github.com/user-attachments/assets/1561326e-b638-4ecb-9d3b-08d38c256484" />
Program no 2 ini merupakan lanjutan dari no 1, hanya saja disini membedakan ialah menambahkan sebuah fitur baru yaitu bagaimana cara mendelete atau menghapus sebuah node. Seperti biasa ada 3 file karena menggunakan ADT:
<ol>
    <li>
        <code>Singlylist.h</code>, memiliki penambahan tiga fungsi penghapusan yaitu <code>deleteFirst, deleteLast, deleteAfter</code> dan dua fungsi lagi lainnya seperti <code>nbList</code> yang digunakan untuk menghitung jumlah node dan <code>deleteList</code> yang digunakan untuk menghapus semua elemen, harus menggunakan call-by-reference (List &L) agar dapat memodifikasi list asli.
    </li>
    <li>
        <code>Singlylist.cpp</code>, mengimplementasikan fungsi baru dari .h yang berisi kelima fungsi baru untuk delete dan juga 2 fungsi lainnya.
    </li>
    <li>
        <code>main.cpp</code> seperti biasa ini merupakan program main yang berfungsi menjalankan fungsi-fungsi yang baru ditambahkan. Setelah list 9 -> 12 -> 8 -> 0 -> 2, <code>deleteFirst()</code> akan dipanggil untuk hapus nilai 9(node awal). <code>deleteLast</code> digunakan untuk menghapus nilai 2(node terakhir). <code>deleteAfter(L,P4)</code> digunakan untuk menghapus 8 yang dimana p4 merupakan pointer ke node 12. Kemudian akan menghasilkan output 12 0 saja. <code>nbList</code> digunakan untuk menghitung berapa node yang ada, seperti contohnya hanya tersisa 2 node saja. Kemudian yang terakhir ada <code>deleteList</code> digunakan untuk menghapus seluruh list yang ada.
    </li>
</ol>



#### Full code screenshot:
#### 1. BAGIAN FULL Singlylist.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/7ef27ade-af1f-4560-a232-c34005f3ef82" />

#### 2. BAGIAN FULL Singlylist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/dcacd60a-9013-437d-8989-73b12409e86c" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a291bf39-8d54-4bf5-8f7d-ed808fa71fb9" />

#### 3. BAGIAN FULL main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/c2b94051-152a-4f62-ab00-a9c6237377ec" />




## Kesimpulan
Berdasarkan kesimpulan yang di dapat setelah praktikum struktur data, Saya jadi mengerti bagaimana mengimplementasikan struktur data yang dinamis dibandingkan array dengan menggunakan Single linked List (SLL) dengan konsep ADT agar pemrograman menjadi terstruktur dengan cara memisahkan 3 file menjadi .h .cpp dan main.cpp. SLL ini merupakan struktur data yang berupa kumpulan node yang dimana setiap node saling terhubung dengan node lainnya dan node berisi info dan next. Pada praktikum kali ini juga tidak hanya mempraktikan bagaimana cara membuat node, tetapi bagaimana cara menambahkan node dan menghapus node (deleteFirst, deleteAfter, deleteLast). Menurut saya memang materi praktikum kali ini bisa sangat kompleks karena menerapkan konsep ADT dan juga membuat Single linked list yang dimana ini bisa menjadi lanjutan untuk saya dalam memahami materi struktur data kali ini



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.








