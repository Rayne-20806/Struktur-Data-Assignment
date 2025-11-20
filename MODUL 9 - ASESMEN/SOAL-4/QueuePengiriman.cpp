#include "QueuePengiriman.h"
using namespace std;
#include <iostream>

// implementasi semua func dan procedure

// Cek Queue Kosong
bool isEmpty(QueueEkspedisi Q) {
    // Kosong jika Head dan Tail -1
    return (Q.Head == -1 && Q.Tail == -1);
}

// Cek Queue Penuh
bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

// Buat Queue Kosong
void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

// Enqueue: Menambah di Belakang (Tail bergerak)
void enQueue(QueueEkspedisi &Q, Paket P) {
    if (isFull(Q)) {
        cout << "Antrean Penuh! Paket " << P.NamaPengirim << " gagal masuk." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
            Q.Tail = 0;
            Q.dataPaket[0] = P;
        } else {
            Q.Tail++;
            Q.dataPaket[Q.Tail] = P;
        }
        cout << "Paket " << P.KodeResi << " berhasil masuk antrean." << endl;
    }
}

// Dequeue: Mengeluarkan dari Depan
void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrean Kosong!" << endl;
    } else {
        cout << "Paket " << Q.dataPaket[Q.Head].KodeResi 
             << " (" << Q.dataPaket[Q.Head].NamaPengirim << ") telah diproses/dihapus." << endl;
        if (Q.Head == Q.Tail) {
            createQueue(Q);
        } else {
            for (int i = Q.Head; i < Q.Tail; i++) {
                Q.dataPaket[i] = Q.dataPaket[i + 1];
            }
            Q.Tail--;
        }
    }
}

// Menampilkan Isi Queue
void viewQueue(QueueEkspedisi Q) {
    cout << "\n=== ANTREAN KOMANIYA EXPRESS ===" << endl;
    if (isEmpty(Q)) {
        cout << "Antrean Kosong." << endl;
    } else {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << i+1 << ". Resi: " << Q.dataPaket[i].KodeResi 
                 << " | Pengirim: " << Q.dataPaket[i].NamaPengirim 
                 << " | Berat: " << Q.dataPaket[i].BeratBarang << "kg" 
                 << " | Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        }
    }
    cout << "================================" << endl;
}

// Bagian B: Menghitung Total Biaya
// Rumus: 1 kg sama dengan Rp 8250
int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int totalBiaya = 0;
    if (!isEmpty(Q)) {
        for (int i = Q.Head; i <= Q.Tail; i++) {
            totalBiaya += (Q.dataPaket[i].BeratBarang * 8250);
        }
    }
    return totalBiaya;
}