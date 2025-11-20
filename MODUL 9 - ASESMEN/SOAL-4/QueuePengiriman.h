#ifndef QueuePengiriman_H
#define QueuePengiriman_H

#include <iostream>
using namespace std;
#include <string>

//ADT QUEUE
const int MAX = 5;
struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; // satuan kg
    string Tujuan;
};
struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};
// Deklarasi Primitif (Bagian A)
bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, Paket P);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

// Deklarasi Tambahan (Bagian B)
int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif