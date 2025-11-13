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
