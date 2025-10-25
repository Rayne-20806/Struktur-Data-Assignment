#include "eldenRing.h"
#include <iostream>
using namespace std;

void createLog(LogList &Log) {
    Log.first = nil;
}

address alokasiMemory(infotype data) {
    address P = new Node;
    P -> isiData = data;
    P -> next = nil;
    return P;
}

void dealokasiMemory(address &P) {
    delete P;
}

void printLog(LogList Log){
    if (isEmpty(Log)) {
        cout << "[...Log Kenangan kosong...]" << endl;
    } else {
        address P = Log.first;
        int i = 1;
        while (P != nil) {
            cout << i << ". Nama     : " << P->isiData.name << endl;
            cout << "   Tipe     : " << P->isiData.type << endl;
            cout << "   Lokasi   : " << P->isiData.location << endl;
            cout << "   Rune     : " << P->isiData.runeReward << endl << endl;
            P = P->next;
            i++;
        }
    }
}

bool isEmpty(LogList Log){
    return Log.first == nil;
}

int nbList(LogList Log){
    int count = 0;
    address P = Log.first;
    while (P != nil) {
        count++;
        P = P -> next;
    }
    return count;
}

// fungsi insert
void insertMemoryFirst(LogList &Log, address P) {
    P -> next = Log.first;
    Log.first = P;
}

void insertMemoryLast(LogList &Log, address P) {
    if (isEmpty(Log)){
        Log.first = P;
    } else {
        address bantu = Log.first;
        while (bantu->next != nil) {
            bantu = bantu->next;
     }
    bantu -> next = P;   
}
}

void insertMemoryAfter(LogList &Log, address P, address Prev) {
    if (Prev != nil) {
        P->next = Prev->next;
        Prev->next = P;
    } else {
        cout << "[Gagal: Kenangan 'Sebelum' tidak ditemukan!]" << endl;
    }
}

/*--- FUNGSI DELETE (MENGHAPUS KENANGAN) ---*/
void deleteMemoryFirst(LogList &Log) {
    if (!isEmpty(Log)) {
        address P = Log.first;
        Log.first = P->next;
        dealokasiMemory(P);
        cout << "[Kenangan pertama berhasil dihapus.]" << endl;
    } else {
        cout << "[Gagal: Log sudah kosong!]" << endl;
    }
}

void deleteMemoryLast(LogList &Log) {
    if (isEmpty(Log)) {
        cout << "[Gagal: Log sudah kosong!]" << endl;
        return;
    }
    
    if (Log.first->next == nil) { // Jika cuma 1 kenangan
        dealokasiMemory(Log.first);
        Log.first = nil;
    } else { // Jika > 1 kenangan
        address P = Log.first;
        address Prev = nil;
        while (P->next != nil) {
            Prev = P;
            P = P->next;
        }
        // P = node terakhir, Prev = node kedua terakhir
        Prev->next = nil;
        dealokasiMemory(P);
    }
    cout << "[Kenangan terakhir berhasil dihapus.]" << endl;
}

void deleteMemoryAfter(LogList &Log, address Prev) {
    if (Prev != nil && Prev->next != nil) {
        address P = Prev->next; // P = node yang mau dihapus
        Prev->next = P->next;
        dealokasiMemory(P);
        cout << "[Kenangan setelah '" << Prev->isiData.name << "' berhasil dihapus.]" << endl;
    } else {
        cout << "[Gagal: Tidak ada kenangan setelah '" << Prev->isiData.name << "'!]" << endl;
    }
}

void deleteList(LogList &Log) {
    address P = Log.first;
    while (P != nil) {
        address temp = P;
        P = P->next;
        dealokasiMemory(temp);
    }
    Log.first = nil;
    cout << "[...Semua kenangan telah terhapus dari Log...]" << endl;
}


/*--- FUNGSI UPDATE (MENGUBAH KENANGAN) - MODUL 5 ---*/
void updateMemoryFirst(LogList &Log) {
    if (!isEmpty(Log)) {
        cout << "--- Mengubah Kenangan Pertama ('" << Log.first->isiData.name << "') ---" << endl;
        cout << "Nama baru: "; getline(cin >> ws, Log.first->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> Log.first->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, Log.first->isiData.location);
        cout << "Rune baru: "; cin >> Log.first->isiData.runeReward;
        cout << "[Kenangan pertama berhasil diupdate!]\n" << endl;
    }
}

void updateMemoryLast(LogList &Log) {
    if (!isEmpty(Log)) {
        address P = Log.first;
        while (P->next != nil) {
            P = P->next;
        }
        cout << "--- Mengubah Kenangan Terakhir ('" << P->isiData.name << "') ---" << endl;
        cout << "Nama baru: "; getline(cin >> ws, P->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> P->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, P->isiData.location);
        cout << "Rune baru: "; cin >> P->isiData.runeReward;
        cout << "[Kenangan terakhir berhasil diupdate!]\n" << endl;
    }
}

void updateMemoryAfter(LogList &Log, address Prev) {
    if (Prev != nil && Prev->next != nil) {
        address P = Prev->next;
        cout << "--- Mengubah Kenangan setelah '" << Prev->isiData.name << "' ---" << endl;
        cout << "(Data lama: '" << P->isiData.name << "')" << endl;
        cout << "Nama baru: "; getline(cin >> ws, P->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> P->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, P->isiData.location);
        cout << "Rune baru: "; cin >> P->isiData.runeReward;
        cout << "[Kenangan berhasil diupdate!]\n" << endl;
    } else {
        cout << "[Gagal: Tidak ada kenangan setelah '" << Prev->isiData.name << "'!]\n" << endl;
    }
}


/*--- FUNGSI SEARCHING (MENCARI KENANGAN) - MODUL 5 ---*/
address findMemoryByName(LogList Log, string name) {
    address P = Log.first;
    while (P != nil) {
        if (P->isiData.name == name) {
            return P;
        }
        P = P->next;
    }
    return nil; // Tidak ketemu
}

address findMemoryBefore(LogList Log, string name) {
    if (isEmpty(Log) || Log.first->isiData.name == name) {
        return nil; // Tidak ada node "before" jika list kosong atau datanya di node first
    }
    
    address P = Log.first;
    while (P->next != nil) {
        if (P->next->isiData.name == name) {
            return P; // P adalah node sebelum node yang dicari
        }
        P = P->next;
    }
    return nil; // Tidak ketemu
}

void printMemoriesByType(LogList Log, string type) {
    bool found = false;
    address P = Log.first;
    cout << "--- Hasil Pencarian Kenangan Tipe: '" << type << "' ---" << endl;
    while (P != nil) {
        if (P->isiData.type == type) {
            cout << " * " << P->isiData.name << " (di " << P->isiData.location << ")" << endl;
            found = true;
        }
        P = P->next;
    }
    if (!found) {
        cout << "[Tidak ada kenangan dengan tipe '" << type << "' ditemukan.]" << endl;
    }
    cout << endl;
}

