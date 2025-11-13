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