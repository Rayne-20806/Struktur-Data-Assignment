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