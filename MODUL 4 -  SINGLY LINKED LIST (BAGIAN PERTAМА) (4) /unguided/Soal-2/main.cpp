#include "Singlylist.h"

#include <iostream>
using namespace std;

int main () {
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);


    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    cout << "\n---Soal 2 terkait delete---" << endl;

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,P4);

    printInfo(L);
    cout << "Jumlah Node: "<< nbList(L) << endl;

    deleteList(L);
    cout << "-- List Berhasil Terhapus --" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}