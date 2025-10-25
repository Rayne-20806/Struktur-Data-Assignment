// Implementasi file Singly Linked List (SLL)
#include "Singlylist.h"
#include <iostream>
using namespace std;
#define nil NULL

void CreateList(List &L) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    L.first = nil;
}
address alokasi(infotype x) {
    /* Mengembalikan address hasil alokasi node baru
       Jika alokasi gagal, kembalikan Nil */
    address P = new ElmList;
    if (P != nil) {
        P -> info = x;
        P -> next = nil;
    }
    return P;
}
void dealokasi(address &P){
/* I.S. P terdefinisi
       F.S. memori yang digunakan P dikembalikan */
    delete P;
}
void printInfo(List L){
    /* I.S. List mungkin kosong
       F.S. Menampilkan info semua elemen list */
    address P = L.first;
    while (P != nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}
void  insertFirst(List &L, address P){
    /* I.S. sembarang, P sudah dialokasikan
       F.S. P menjadi elemen pertama list */
    if (L.first == nil) {
        L.first =  P;
    }
    else {
        P -> next = L.first;
        L.first = P;
    }
}

// implementasi latihan no 3
address findElm(List L, infotype x) {
    /* Mencari apakah ada elemen list dengan P->info = x */
    address P = L.first;
    while (P != nil) {
        if ( P -> info == x) {
            return P; // ketemu, kembalikan addressnya
        }
        else {
            P = P -> next; // pindah ke node selanjutnya
        }
    }
    // jika tidak ada
    return nil;
}

// implementasi latihan no 4
int sumInfo(List L) {
    /* Mengembalikan total penjumlahan info dari semua elemen */
    int total = 0;
    address P = L.first;
    while (P != nil) {
        total += P -> info;
        P = P -> next;
    }
    return total;
}