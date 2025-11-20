#ifndef StackMHS_H
#define StackMHS_H

#include <iostream>
using namespace std;
#include <string>
#define nil NULL

// Definisi Struct Mahasiswa
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};
const int MAX = 6;

// Definisi ADT Stack Array
struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

// Deklarasi Function dan prosedur Primitif (Bagian A)
bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, Mahasiswa M_Baru);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa S, float min, float max);

// Deklarasi Tambahan (Bagian B)
void MaxNilaiAkhir(StackMahasiswa S);

#endif

