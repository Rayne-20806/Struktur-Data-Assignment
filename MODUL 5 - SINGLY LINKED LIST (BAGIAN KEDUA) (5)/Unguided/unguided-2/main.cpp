#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    // implementasi latihan no 2
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L,P1);
    P2 = alokasi(0);
    insertFirst(L,P2);
    P3 = alokasi(8);
    insertFirst(L,P3);
    P4 = alokasi(12);
    insertFirst(L,P4);
    P5 = alokasi(9);
    insertFirst(L,P5);
    cout << "Hasil latihan 2: " << endl;
    printInfo(L);

    // implementasi latihan no 3
    cout << "Hasil latihan 3: " << endl;
    address P_cari = findElm(L, 8);
    if (P_cari != nil) {
        cout << P_cari -> info << " ditemukan dalam list." << endl;
    }
    else {
        cout << "tidak ditemukan dalam list." << endl;
    }
    cout << endl;

    // implementasi latihan no 4
    cout << "Hasil latihan 4: " << endl;
    int total = sumInfo(L);
    cout << "Total penjumlahan elemen dalam list: " << total << endl;

return 0;

}