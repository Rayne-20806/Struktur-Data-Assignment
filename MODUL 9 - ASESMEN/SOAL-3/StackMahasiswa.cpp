#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

// Cek Stack Kosong
bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

// Cek Stack Penuh
bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

// Buat Stack Kosong
void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

// Operasi Push (Tambah Data)
void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
    }
}

// Operasi Pop (Hapus Data Tops)
void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        S.Top--;
    }
}

// Update Data Berdasarkan Posisi (Indeks = Posisi - 1)
void Update(StackMahasiswa &S, int posisi, Mahasiswa M_Baru) {
    if (isEmpty(S)) {
        cout << "Stack Kosong!" << endl;
    } else {
        int idx = posisi - 1; // Konversi posisi user (1-based) ke index (0-based)
        if (idx >= 0 && idx <= S.Top) {
            S.dataMahasiswa[idx] = M_Baru;
            cout << "Data posisi " << posisi << " berhasil diupdate." << endl;
        } else {
            cout << "Posisi tidak valid!" << endl;
        }
    }
}

// Menampilkan Isi Stack
void View(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
    } else {
        // Loop dari Top ke 0 (LIFO)
        for (int i = S.Top; i >= 0; i--) {
            float na = (0.2 * S.dataMahasiswa[i].NilaiTugas) + 
                       (0.4 * S.dataMahasiswa[i].NilaiUTS) + 
                       (0.4 * S.dataMahasiswa[i].NilaiUAS);
            
            cout << "Posisi " << (i + 1) << ": " << S.dataMahasiswa[i].Nama 
                 << " (NA: " << na << ")" << endl;
        }
    }
}

// Search Mahasiswa berdasarkan Range Nilai Akhir
void SearchNilaiAkhir(StackMahasiswa S, float min, float max) {
    cout << "\n>> Search Range Nilai Akhir: " << min << " - " << max << endl;
    bool found = false;
    for (int i = S.Top; i >= 0; i--) {
        float na = (0.2 * S.dataMahasiswa[i].NilaiTugas) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUTS) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUAS);
        
        if (na >= min && na <= max) {
            cout << "Ditemukan: " << S.dataMahasiswa[i].Nama 
                 << " (Posisi: " << i + 1 << ", NA: " << na << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ada data dalam range tersebut." << endl;
}

// Bagian B: Cari Nilai Akhir Tertinggi
void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) return;

    float maxVal = -1;
    
    // Cari nilai max dulu
    for (int i = S.Top; i >= 0; i--) {
        float na = (0.2 * S.dataMahasiswa[i].NilaiTugas) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUTS) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUAS);
        if (na > maxVal) maxVal = na;
    }

    cout << "\n>> Mahasiswa Nilai Akhir Tertinggi:" << endl;
    for (int i = S.Top; i >= 0; i--) {
        float na = (0.2 * S.dataMahasiswa[i].NilaiTugas) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUTS) + 
                   (0.4 * S.dataMahasiswa[i].NilaiUAS);
        if (na == maxVal) {
            cout << "Nama: " << S.dataMahasiswa[i].Nama 
                 << " | Posisi: " << i + 1 << " | NA: " << na << endl;
        }
    }
}
