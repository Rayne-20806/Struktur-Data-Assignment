#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
const int MAX_MHS = 10;

struct  Mahasiswa{
    string nama, nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float rata2NilaiAkhir(float uts, float uas, float tugas);
void inputData(Mahasiswa mhs[], int &jumlahMhs);
void tampilkanData(const Mahasiswa [], int jumlahMhs);

#endif
