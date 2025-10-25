#include "eldenRing.h"
#include <iostream>
#include <limits> // Perlu untuk pressEnter
#include <string>
using namespace std;

// Fungsi helper untuk jeda (sudah diperbaiki)
void pressEnter() {
    cout << "\n...Tekan Enter untuk melanjutkan perjalanan..." << endl;
    // Membersihkan buffer input sebelum cin.get()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    LogList LogTarnished; 
    createLog(LogTarnished);
    address P, Prev; 

    cout << "=================================================" << endl;
    cout << "       CATATAN PERJALANAN DI LAND OF SHADOW      " << endl;
    cout << "=================================================\n" << endl;

    // === TAHAP 1: INSERT (Menemukan Kenangan) ===
    cout << "--- TAHAP 1: MENAMBAH KENANGAN (INSERT) ---\n" << endl;
    cout << "Log Awal:" << endl;
    printLog(LogTarnished); // Mencetak "[...Log Kenangan kosong...]"

    cout << "\nAKSI: insertMemoryFirst(\"Scadutree Fragment\")" << endl;
    P = alokasiMemory({"Scadutree Fragment", "Item", "Gravesite Plain", 0});
    insertMemoryFirst(LogTarnished, P);

    cout << "\nAKSI: insertMemoryLast(\"Divine Beast Dancing Lion\")" << endl;
    P = alokasiMemory({"Divine Beast Dancing Lion", "Boss", "Belurat", 80000});
    insertMemoryLast(LogTarnished, P);

    cout << "\nAKSI: insertMemoryLast(\"Rellana, Twin Moon Knight\")" << endl;
    P = alokasiMemory({"Rellana, Twin Moon Knight", "Boss", "Shadow Keep", 120000});
    insertMemoryLast(LogTarnished, P);
    
    cout << "\nAKSI: insertMemoryAfter(..., \"Miquella's Cross\", ...setelah \"Divine Beast\")" << endl;
    Prev = findMemoryByName(LogTarnished, "Divine Beast Dancing Lion");
    P = alokasiMemory({"Miquella's Cross", "NPC", "Scadutree Base", 0});
    insertMemoryAfter(LogTarnished, P, Prev);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\n--- TAHAP 1 SELESAI ---" << endl;
    cout << "Total Kenangan: " << nbList(LogTarnished) << endl;
    pressEnter();

    // === TAHAP 2: UPDATE (Mengkoreksi Kenangan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 2: MENGUBAH KENANGAN (UPDATE)     " << endl;
    cout << "=================================================\n" << endl;
    
    cout << "AKSI: updateMemoryFirst() pada \"Scadutree Fragment\"..." << endl;
    updateMemoryFirst(LogTarnished); // Ini akan interaktif meminta input baru

    cout << "AKSI: updateMemoryLast() pada \"Rellana\"..." << endl;
    updateMemoryLast(LogTarnished); // Ini akan interaktif meminta input baru


    cout << "\nAKSI: updateMemoryAfter() pada node setelah \"Miquella's Cross\"..." << endl;
    Prev = findMemoryByName(LogTarnished, "Miquella's Cross"); 
    updateMemoryAfter(LogTarnished, Prev); // akan mengupdate "Rellana"
    printLog(LogTarnished); // Langsung cetak hasilnya
    
    
    cout << "\n--- TAHAP 2 SELESAI ---" << endl;
    pressEnter();

    // === TAHAP 3: SEARCHING (Mengingat Kembali) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 3: MENCARI KENANGAN (SEARCH)      " << endl;
    cout << "=================================================\n" << endl;

    cout << "AKSI: printMemoriesByType(\"Boss\")" << endl;
    printMemoriesByType(LogTarnished, "Boss");

    cout << "\nAKSI: findMemoryByName(\"Messmer the Impaler\")" << endl;
    P = findMemoryByName(LogTarnished, "Messmer the Impaler");
    if (P == nil) {
        cout << "[Kenangan 'Messmer the Impaler' belum ditemukan...]\n" << endl;
    } else {
        cout << "[Ya, kenangan 'Messmer' ada di Log.]\n" << endl;
    }
    
    cout << "\n--- TAHAP 3 SELESAI ---" << endl;
    pressEnter();

    // === TAHAP 4: DELETE (Melupakan Kenangan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 4: MENGHAPUS KENANGAN (DELETE)    " << endl;
    cout << "=================================================\n" << endl;
    cout << "Kondisi List Awal (setelah di-update):" << endl;
    printLog(LogTarnished);

    cout << "\nAKSI: deleteMemoryFirst()" << endl;
    deleteMemoryFirst(LogTarnished);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\nAKSI: deleteMemoryLast()" << endl;
    deleteMemoryLast(LogTarnished);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\nAKSI: deleteMemoryAfter(..., ...setelah \"Divine Beast\")" << endl;
    Prev = findMemoryByName(LogTarnished, "Divine Beast Dancing Lion"); 
    deleteMemoryAfter(LogTarnished, Prev); // Hapus "Miquella's Cross"
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\n--- TAHAP 4 SELESAI ---" << endl;
    cout << "Total Kenangan Tersisa: " << nbList(LogTarnished) << endl;
    pressEnter();

    // === TAHAP 5: CLEANUP (Akhir Perjalanan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 5: MENGHAPUS SEMUA (DELETELIST)   " << endl;
    cout << "=================================================\n" << endl;
    
    cout << "AKSI: deleteList()" << endl;
    deleteList(LogTarnished);
    printLog(LogTarnished);
    cout << "Total Kenangan Tersisa: " << nbList(LogTarnished) << endl;

    cout << "\n=================================================" << endl;
    cout << "            SHADOW OF THE ERDTREE - END            " << endl;
    cout << "=================================================" << endl;

    return 0;
}