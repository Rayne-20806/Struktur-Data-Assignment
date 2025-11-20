#include "DLLPlaylist.h"
#include <iostream>
using namespace std;


// Fungsi bantuan untuk mendapatkan address node pada posisi tertentu
address getAddressAt(List L, int pos) {
    address P = L.head;
    int i = 1;
    while (P != NULL && i < pos) {
        P = P->next;
        i++;
    }
    return P;
}

int main() {
    //1. buat list kosong
    List L;
    Song sTemp;
    createList(L);
    sTemp = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    insertLast(L, sTemp);
    sTemp = {"Langkahmu", "Delta", 185, 320, 4.8};
    insertLast(L, sTemp);
    sTemp = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    insertLast(L, sTemp);

    // 3. Tampilkan list
    viewList(L);

    //4. Lakukan deleteLast
    Song deletedSong;
    cout << "\nMelakukan Delete Last" << endl;
    deleteLast(L, deletedSong);
    cout << "Lagu dihapus: " << deletedSong.Title << endl;

    // 5. Upadate node posisi 2
    cout << "\nSilahkan input update untuk posisi 2 (Pelita)" << endl;
    updateAtPosition(L, 2);

    // 6. Tampilkan list setelah update
    viewList(L);

    // 7. Ambil node posisi 2 sebagai acuan (Q)
    address Q = getAddressAt(L, 2);
    
    if (Q != NULL) {
        // 7a. insertBefore pada node posisi 2 ("Senandung")
        cout << "\n>> Melakukan insertBefore posisi 2 (Senandung)..." << endl;
        sTemp = {"Senandung", "Mira", 175, 120, 4.0};
        insertBefore(L, Q, sTemp);
        viewList(L);

        Q = getAddressAt(L, 2); 

        // 7b. updateBefore pada node posisi 2
        // Node sebelum posisi 2 adalah posisi 1.
        cout << "\nMelakukan updateBefore posisi 2..." << endl;
        updateBefore(L, Q); 
        viewList(L);

        // 7c. deleteBefore pada node posisi 3
        address R = getAddressAt(L, 3);
        cout << "\nMelakukan deleteBefore posisi 3" << endl;
        deleteBefore(L, R, deletedSong); // Akan menghapus node posisi 2
        cout << "Lagu dihapus: " << deletedSong.Title << endl;
        viewList(L);
    }

    // 8 . Searching
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}