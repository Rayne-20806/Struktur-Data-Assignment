#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;
#define Nil NULL

// definisi tipe data dan ADT multilist
typedef int infotypeinduk;
typedef int infotypeanak;
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

// struktu Elemen untuk anak
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};
struct listanak {
    address_anak first;
    address_anak last;
};

// struktur Elemen untuk induk
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak; // list anak ada di induknya
    address next;
    address prev;
};
struct listinduk {
    address first;
    address last;
};

//deklarasikan fungsi atau prosedur primiif

// Cek Kosong
bool ListEmpty(listinduk L);
bool ListEmptyAnak(listanak L);

// Create List
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

// Manajemen Memori
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

// Pencarian
address findElm(listinduk L, infotypeinduk X);
address_anak findElmAnak(listanak Lanak, infotypeanak X); // Saya rapikan namanya

// Penambahan Elemen Induk
void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

// Penambahan Elemen Anak
void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

// Penghapusan Elemen Induk
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X); // Hapus berdasarkan nilai

// Penghapusan Elemen Anak
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X); // Hapus berdasarkan nilai

// Cetak
void printInfo(listinduk L);
void printInfoAnak(listanak Lanak);

#endif