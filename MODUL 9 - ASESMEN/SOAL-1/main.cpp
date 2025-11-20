#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    Product pTemp; // Variabel bantuan untuk menampung data produk

    // 1. Buat list kosong 
    createList(L);

    // 2. Gunakan insertLast untuk memasukkan 3 data 
    pTemp = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, pTemp);
    pTemp = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, pTemp);
    pTemp = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, pTemp);

    // 3. Tampilkan list
    viewList(L);

    // 4. Lakukan deleteFirst 
    Product deletedProd;
    cout << "\nMelakukan Delete First" << endl;
    deleteFirst(L, deletedProd);
    cout << "Data dihapus: " << deletedProd.Nama << endl;

    // 5. Tampilkan list kembali 
    viewList(L);

    // 6. Update data pada posisi ke-2 (Input sesuai soal)
    cout << "\ninput data update untuk posisi 2 sesuai soal (Stabilo)" << endl;
    updateAtPosition(L, 2);

    // 7. Tampilkan list setelah update
    viewList(L);

    // 8. Searching range min=2000, max=7000
    searchByFinalPriceRange(L, 2000, 7000);

    // Bagian B: Pemanggilan MaxHargaAkhir 
    MaxHargaAkhir(L);

    return 0;
}