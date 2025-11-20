#include "SLLInventory.h"
#include <iostream>
using namespace std;

//tEmpat penerapan fungsi atau prosedur

// Cek apakah list kosong
bool isEmpty(List L) {
    return L.head == nil;
}

// Membuat list kosong
void createList(List &L) {
    L.head = nil;
}

// Alokasi memori untuk node baru
address allocate(Product P) {
    address newNode = new Node;
    newNode->info = P;
    newNode->next = nil;
    return newNode;
}

// Dealokasi memori
void deallocate(address &addr) {
    delete addr;
}

// Penambahan elemen di awal
void insertFirst(List &L, Product P) {
    address newNode = allocate(P);
    newNode->next = L.head;
    L.head = newNode;
}

// Penambahan elemen di akhir
void insertLast(List &L, Product P) {
    address newNode = allocate(P);
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        address temp = L.head;
        while (temp->next != nil) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Penambahan elemen setelah node tertentu
void insertAfter(List &L, address Q, Product P) {
    if (Q != nil) {
        address newNode = allocate(P);
        newNode->next = Q->next;
        Q->next = newNode;
    }
}

// Penghapusan elemen pertama
void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = L.head->next;
        deallocate(temp);
    }
}

// Penghapusan elemen terakhir
void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == nil) {
            deleteFirst(L, P);
        } else {
            address prev = nil;
            address temp = L.head;
            while (temp->next != nil) {
                prev = temp;
                temp = temp->next;
            }
            P = temp->info;
            prev->next = nil;
            deallocate(temp);
        }
    }
}

// Penghapusan elemen setelah node tertentu
void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != nil) {
        address temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

// Update data pada posisi tertentu (Input User)
void updateAtPosition(List &L, int posisi) {
    address temp = L.head;
    int i = 1;
    while (temp != nil && i < posisi) {
        temp = temp->next;
        i++;
    }

    if (temp != nil) {
        cout << "\n-Update Data Posisi " << posisi << " ---" << endl;
        cout << "Masukkan Nama Baru       : ";
        cin.ignore(); 
        getline(cin, temp->info.Nama);
        cout << "Masukkan SKU Baru        : "; cin >> temp->info.SKU;
        cout << "Masukkan Jumlah Baru     : "; cin >> temp->info.Jumlah;
        cout << "Masukkan Harga Satuan    : "; cin >> temp->info.HargaSatuan;
        cout << "Masukkan Diskon Persen   : "; cin >> temp->info.DiskonPersen;
        cout << "Data berhasil diupdate!" << endl;
    } else {
        cout << "Posisi tidak ditemukan!" << endl;
    }
}

// Menampilkan seluruh isi list
void viewList(List L) {
    cout << "\nDAFTAR PRODUK" << endl;
    if (isEmpty(L)) {
        cout << "List Kosong." << endl;
    } else {
        address temp = L.head;
        int i = 1;
        while (temp != nil) {
            float hargaAkhir = temp->info.HargaSatuan * (1.0 - temp->info.DiskonPersen / 100.0);
            
            cout << "Posisi " << i << ":" << endl;
            cout << "  Nama         : " << temp->info.Nama << endl;
            cout << "  SKU          : " << temp->info.SKU << endl;
            cout << "  Jumlah       : " << temp->info.Jumlah << endl;
            cout << "  Harga Satuan : " << temp->info.HargaSatuan << endl;
            cout << "  Diskon       : " << temp->info.DiskonPersen << "%" << endl;
            cout << "  Harga Akhir  : " << hargaAkhir << endl;
            
            temp = temp->next;
            i++;
        }
    }
    cout << endl;
}

// Mencari produk berdasarkan range harga akhir
void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    cout << "\nHASIL PENCARIAN (Range: " << minPrice << " - " << maxPrice << ")" << endl;
    address temp = L.head;
    int i = 1;
    bool found = false;
    while (temp != nil) {
        float hargaAkhir = temp->info.HargaSatuan * (1.0 - temp->info.DiskonPersen / 100.0);
        
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << "Ditemukan di Posisi " << i << " - " << temp->info.Nama 
                 << " (Harga Akhir: " << hargaAkhir << ")" << endl;
            found = true;
        }
        temp = temp->next;
        i++;
    }
    if (!found) cout << "Tidak ada produk dalam rentang harga tersebut." << endl;
}

// Soal Bag B: Menampilkan produk dengan Harga Akhir Terbesar
void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List Kosong, tidak ada harga maksimum." << endl;
        return;
    }

    // Tahap 1, Cari nilai maks
    float maxVal = -1.0;
    address temp = L.head;
    while (temp != nil) {
        float hargaAkhir = temp->info.HargaSatuan * (1.0 - temp->info.DiskonPersen / 100.0);
        if (hargaAkhir > maxVal) {
            maxVal = hargaAkhir;
        }
        temp = temp->next;
    }

    // Tahap 2, Tampilkan semua produk yang nilainya == maxVal
    cout << "\nPRODUK DENGAN HARGA AKHIR TERTINGGI" << endl;
    temp = L.head;
    int i = 1;
    while (temp != NULL) {
        float hargaAkhir = temp->info.HargaSatuan * (1.0 - temp->info.DiskonPersen / 100.0);
        if (hargaAkhir == maxVal) {
            cout << "Posisi " << i << " - " << temp->info.Nama 
                 << " (Harga: " << hargaAkhir << ")" << endl;
        }
        temp = temp->next;
        i++;
    }
}