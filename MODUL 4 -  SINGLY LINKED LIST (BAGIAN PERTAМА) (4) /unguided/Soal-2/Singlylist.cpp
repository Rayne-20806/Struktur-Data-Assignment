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
