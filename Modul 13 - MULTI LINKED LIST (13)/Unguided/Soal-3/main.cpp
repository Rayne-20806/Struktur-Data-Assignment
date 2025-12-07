#include "circularlist.h"
#include <iostream>
using namespace std;

// fungsi bantuan untuk buat data mahasiswa
address createData(string nama, string nim, char jk, float ipk) {
    infotype mhs;
    mhs.Nama = nama;
    mhs.Nim = nim;
    mhs.Jenis_Kelamin = jk;
    mhs.IPK = ipk;
    return alokasi(mhs);
}

int main() {
     List L;
    address P1 = nil;
    address P2 = nil;
    infotype x; // variabel bantuan untuk searching (findElm)

    CreateList(L);

    cout << "coba insert first, last, dan after" << endl;

    // 1. Insert First (Danu)
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    // 2. Insert Last (Fahmi)
    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    // 3. Insert Last (Bobi)
    P1 = createData("Bobi", "02", 'l', 3.71);
    insertLast(L, P1); 

    // 4. Insert First (Ali)
    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    // 5. Insert First (Gita)
    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    // --- INSERT AFTER ---

    // 6. Insert Cindi (03) setelah Gita (07)
    x.Nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    // 7. Insert Hilmi (08) setelah Bobi (02)
    x.Nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    // 8. Insert Eli (05) setelah Danu (04)
    x.Nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}