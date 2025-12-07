#include "circularlist.h"
#include <iostream>
using namespace std;

// implementasi fungsi atau prosedur primitif untuk circular double link list
void CreateList(List &L){
    L.First = nil;
}

address alokasi(infotype x) {
    // buat node baru kemudian isi info dengan x dan next dengan nil
    address P = new ElmList;
    P -> info = x;
    P -> next = nil;
    return P;
}

void dealokasi(address P) {
    // hapus node yang ditunjuk P
    delete P;
}

void insertFirst(List &L, address P) {
    // jika list kosong
    if (L.First == nil) {
        L.First = P;
        P -> next = P; // circular dan menunjuk ke dirinya sendiri
    } else { // jika list tidak kosong
        address Last = L.First;
        // cari last node
        while (Last -> next != L.First) {
            Last = Last -> next;
        }
        P -> next = L.First;
        Last -> next = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    // jika list kosong
    if (L.First == nil) {
        insertFirst(L, P); 
    } else {
        // jika list tidak kosong
        address Last = L.First;
        // cari last node
        while (Last -> next != L.First) {
            Last = Last -> next;
        }
        Last -> next = P;
        P -> next = L.First; // circular kembali ke first
    }
}

void insertAfter(List &L, address Prec, address P){
    if (Prec != nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P){
    if (L.First != nil) {
        P = L.First;
        // jika hanya ada satu elemen
        if (P -> next == L.First) {
            L.First = nil;
        } else { 
            // jika lebih dari satu elemen
            address Last = L.First;
            while (Last->next != L.First) {
                Last = Last->next;
            }
            L.First = P->next;
            Last->next = L.First;
        }

    }
}



void deleteLast(List &L, address &P){
    // jika list tidak kosong
    if (L.First != NULL) {
        address Last = L.First;
        address PrecLast = NULL;
        
        // Cari Last dan Sebelum Last (PrecLast)
        while (Last->next != L.First) {
            PrecLast = Last;
            Last = Last->next;
        }
        
        P = Last;
        if (PrecLast == NULL) { // Jika cuma 1 elemen
            L.First = NULL;
        } else {
            PrecLast->next = L.First;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P){
    if (Prec != nil && Prec -> next != L.First) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next = nil;
    } else if (Prec != nil && Prec -> next == L.First) {
        deleteFirst(L, P);
    }
}

// Pencarian berdasarkan NIM
address findElm(List L, infotype x){
    if (L.First == nil) {
        return nil;
    } else {
        address P = L.First;
        do {
            if (P -> info.Nim == x.Nim) {
                return P;
            }
            P = P -> next;
        } while (P != L.First);
        return nil;
    }
}

void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List Kosong" << endl;
    } else {
        address P = L.First;
        int i = 1;
        do {
            cout << "Data ke-" << i << endl;
            cout << "Nama : " << P->info.Nama << endl;
            cout << "NIM  : " << P->info.Nim << endl;
            cout << "L/P  : " << P->info.Jenis_Kelamin << endl;
            cout << "IPK  : " << P->info.IPK << endl;
            cout << "--------------------" << endl;
            P = P->next;
            i++;
        } while (P != L.First);
    }
}