#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Buat List Induk
    listinduk L;
    CreateList(L);
    cout << "=== PROGRAM MULTI LIST ANGKA ===" << endl;

    // 2. Insert Induk (1, 2, 3)
    address Induk1 = alokasi(1);
    insertFirst(L, Induk1);
    
    address Induk2 = alokasi(2);
    insertLast(L, Induk2);
    
    address Induk3 = alokasi(3);
    insertLast(L, Induk3);

    // 3. Insert Anak ke Induk 1 (Anak: 10, 20)
    insertLastAnak(Induk1->lanak, alokasiAnak(10));
    insertLastAnak(Induk1->lanak, alokasiAnak(20));

    // 4. Insert Anak ke Induk 2 (Anak: 50)
    insertLastAnak(Induk2->lanak, alokasiAnak(50));

    // 5. Insert Anak ke Induk 3 (Anak: 99, 100)
    insertLastAnak(Induk3->lanak, alokasiAnak(99));
    insertLastAnak(Induk3->lanak, alokasiAnak(100));

    // 6. Cetak
    printInfo(L);

    // 7. Hapus Anak 50 dari Induk 2
    cout << "\n>> Menghapus Anak 50 dari Induk 2..." << endl;
    delPAnak(Induk2->lanak, 50);
    printInfo(L);

    return 0;
}