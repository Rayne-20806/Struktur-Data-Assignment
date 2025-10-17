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