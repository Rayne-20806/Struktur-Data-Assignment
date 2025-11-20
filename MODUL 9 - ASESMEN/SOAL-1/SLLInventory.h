#ifndef SLLInventory_H
#define SLLInventory_H
#define nil NULL

#include <iostream>
#include <string>
using namespace std;

// Soal Bagian A
// Definisi ADT  SLL
struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef struct Node *address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

//Bagian Function dan prosedur primitif
bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address &addr);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);


void updateAtPosition(List &L, int posisi);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

// Soal Bagian B 
void MaxHargaAkhir(List L);




#endif