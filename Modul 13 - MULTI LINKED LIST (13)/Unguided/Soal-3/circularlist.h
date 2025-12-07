#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include <iostream>
using namespace std;
#define nil NULL

// definisi tipe data dan ADT untuk circular duoble linked list

struct Mahasiswa {
    string Nama;
    string Nim;
    char Jenis_Kelamin;
    float IPK;
};
typedef Mahasiswa infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// deklarsi fungsi atau prosedur primitif
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

// Pencarian berdasarkan NIM
address findElm(List L, infotype x);

void printInfo(List L);

#endif