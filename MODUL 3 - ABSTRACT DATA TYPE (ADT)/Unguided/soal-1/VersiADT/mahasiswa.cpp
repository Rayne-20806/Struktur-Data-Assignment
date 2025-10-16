// mahasiswaArray.cpp
#include <iostream>
using  namespace std;
#include "mahasiswa.h"
#include <limits> // Diperlukan untuk cin.ignore


float rata2NilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}


void inputData(Mahasiswa mhs[], int &jumlahMhs) {
    cout << "||Program Menghitung Rata-rata Nilai Akhir Mahasiswa||" << endl;
    cout << "Masukkan jumlah Mahasiswa (maksimal 10): ";
    cin >> jumlahMhs;

    if (jumlahMhs > MAX_MHS || jumlahMhs <= 0) {
        cout << "Jumlah Mahasiswa tidak valid. Program berhenti." << endl;
        jumlahMhs = 0; 
        return;
    }

    cout << endl;
    cout <<  "-- Input Data Mahasiswa -- " << endl;
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = rata2NilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
}

void tampilkanData(const Mahasiswa mhs[], int jumlahMhs) {
    if (jumlahMhs == 0) return; 

    cout << "\n\n-- Data Mahasiswa --" << endl;
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "==========================" << endl;
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    cout << "==========================" << endl;
}
