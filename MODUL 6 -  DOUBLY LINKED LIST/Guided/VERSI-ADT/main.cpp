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