#include "QueuePengiriman.h"
#include <iostream>
using namespace std;


// Helper untuk rapih
Paket inputPaket() {
    Paket p;
    cout << "--- Input Data Paket ---" << endl;
    cout << "Kode Resi     : "; cin >> p.KodeResi;
    cout << "Nama Pengirim : "; cin >> p.NamaPengirim;
    cout << "Berat (kg)    : "; cin >> p.BeratBarang;
    cout << "Tujuan        : "; cin >> p.Tujuan;
    return p;
}

int main() {
    QueueEkspedisi Q;
    int pilihan;
    
    // 1) Buat queue kosong 
    createQueue(Q);

    // Menu Switch-Case 
    do {
        cout << "\n=== Komaniya Express ===" << endl;
        cout << "1. Input Data Paket (Enqueue)" << endl;
        cout << "2. Hapus Data Paket (Dequeue)" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl; // Bagian B
        cout << "5. Load Data Test (Sesuai Soal)" << endl; // Helper buat testing cepat
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Input manual user
                Paket p = inputPaket();
                enQueue(Q, p);
                break;
            }
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4: // Bagian B 
                cout << "Total Biaya Pengiriman: Rp " << TotalBiayaPengiriman(Q) << endl;
                break;
            case 5: {
                // Opsi tambahan untuk memuat 5 data soal sekaligus
                cout << ">> Memuat 5 data dummy sesuai soal..." << endl;
                enQueue(Q, {"123456", "Hutao", 14, "Sumeru"});
                enQueue(Q, {"234567", "Ayaka", 10, "Fontaine"});
                enQueue(Q, {"345678", "Bennet", 7, "Natlan"});
                enQueue(Q, {"456789", "Furina", 16, "Liyue"});
                enQueue(Q, {"567890", "Nefer", 6, "Inazuma"});
                break;
            }
            case 0:
                cout << "Terima kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}