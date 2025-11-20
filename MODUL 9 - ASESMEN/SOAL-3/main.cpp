#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

#include "StackMahasiswa.h"

int main() {
    StackMahasiswa S;
    Mahasiswa mTemp;

    // 1) Buat stack kosong
    createStack(S);

    // 2) Input data mahasiswa (Push 6 data)
    mTemp = {"Venti", "11111", 75.7, 82.1, 65.5};
    Push(S, mTemp);
    mTemp = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Push(S, mTemp);
    mTemp = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Push(S, mTemp);
    mTemp = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Push(S, mTemp);
    mTemp = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Push(S, mTemp);
    mTemp = {"Chasca", "66666", 99.9, 93.6, 87.3};
    Push(S, mTemp);

    // 3) Tampilkan stack awal
    cout << "STACK AWAL" << endl;
    View(S);

    // 4) Lakukan pop 1x
    cout << "\nMelakukan Pop" << endl;
    Pop(S);

    // 5) Tampilkan stack setelah pop
    cout << "STACK SETELAH POP" << endl;
    View(S);

    // 6) Update data posisi ke-3 (Heizou)
    cout << "\nMelakukan Update Posisi 3..." << endl;
    mTemp = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, mTemp);

    // 7) Tampilkan stack setelah update
    cout << "STACK SETELAH UPDATE" << endl;
    View(S);

    // 8) Searching Nilai Akhir (85.5 - 95.5)
    SearchNilaiAkhir(S, 85.5, 95.5);

    // Bagian B: Panggil MaxNilaiAkhir
    MaxNilaiAkhir(S);

    return 0;
}