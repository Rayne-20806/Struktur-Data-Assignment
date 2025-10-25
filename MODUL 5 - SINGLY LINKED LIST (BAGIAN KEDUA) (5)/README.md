# <h1 align="center">Laporan Praktikum Modul Singly Linked List (Bagian Kedua) (5)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
Modul 5 kali ini merupakan lanjutan dari modul 4 yaitu Singly linked list bagian pertama, hanya saja ini yang bagian kedua. Pada pembahasan kali ini membahas terkait Update dan juga searching pada Singly linked List.
<ol>
    <li>
        Update(). Pada SLL kita dapat melakukan update, disini update ada 3 macam yaitu <code>UpdateFirst, updateLast, dan updateAfter</code>. Operasi update ini merupakan proses memodifikasi bagian <code>info</code> didalam node yang sudah ada di dalam list. Berbeda halnya dengan insert dan juga delete yang memanipulasi pointer next, update hanya mengubah nilai dari info pada suatu nodenya saja. Untuk <code>updateFirst</code> akan melakukan update node yang ditunjuk oleh pointer first. <code>updateLast</code> akan melakukan penelusuran atau pencarian hingga node akhir yang dimana <code>next -> Nil</code> lalu mengubah info di node tersebut. <code>updateAfter</code> akan mengubah info pada node yang berada tepat setelah node prev(node sebelumnya) yang diberikan. Penting diingat juga bahwa fungsi-fungsi tersebut harus menerima parameter <code>List &L</code> atau call by reference yang dimana agar perubahan data bersifat permanen pada list asli.
    </li>
    <li>
        Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node-node tertentu. Proses ini akan mengunjungi setiap node(raversal) dan berhenti setelah node yang dicari ketemu atau status pencarian ada(TRUE). Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan update akan lebih mudah. Pada praktikum kali ini dijelaskan juga ada macam-macam seraching berdasarkan pencarian seperti <code>Searching data(mencari berdasarkan data), Searching address(mencari berdasarkan alamat), Searching range(mencari berdasarkan jarak)</code>.
    </li>
</ol>


## Guided 

## 1. Program Lanjutan dari Guided Modul 4, ini terkait update dan searching
## 1.1 listBuah.h
```h
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};


bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &list);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedlist &List);
void updateLast(linkedlist &List);
void updateAfter(linkedlist &List, address prev);

// materi modul 5 (part 2, searching)
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```

## 1.2 listBuah.cpp
```cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist &List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist &List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```


## 1.3 main.cpp
```cpp
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtbBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 314500);
   

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    //lanjutan  
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;


    cout << "--- ISIS LIST SETELAH DILAKUKAN UPDATE --- " << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    
    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
}

//note: jika ingin hapus list maka lepas dulu pointer previousnya agar bisa hapus node
// Untuk Laprak Unguided....hindara Data Buah dan Data Mahasiswa
```


## Unguided 

### 1. Buat Program Kreatif, bebas Apa saja namun tidak data mahasiswa dan buah yang tadi

### 1.1 Program eldenRing.h
```h
#ifndef ERDTREE_LOG_H
#define ERDTREE_LOG_H
#define nil NULL

#include <iostream>
#include <string>
using namespace std;

// 1. definisi tipe data
// ini kenangan yang disimpan di dalam log
struct Memory {
    string name; // nama kenangan (misal: "Messmer the impaler")
    string type; // tipe(Boss, Lokasi, NPC)
    string location; // Lokas ditemukannya 
    int runeReward; // jumlah rune yang didapat
};

typedef Memory infotype;
typedef struct Node *address;

// 2. definisi Node dan List, gerbong
struct Node {
    infotype isiData; // isi data kenangan
    address next; // pointer ke kenangan selanjutnya
};
struct LogList {
    address first;
};

//3. berbagai fungsi dan prosedur pada singly linked list
// prosedur dan fungsi utama
void createLog(LogList &Log);
address alokasiMemory(infotype data);
void dealokasiMemory(address &P);
void printLog(LogList Log);
bool isEmpty(LogList Log);
int nbList(LogList Log);

// prosedur untuk menambahkan kenangan
void insertMemoryFirst(LogList &Log, address P);
void insertMemoryLast(LogList &Log, address P);
void insertMemoryAfter(LogList &Log, address P, address Prev);

// prosedur untuk menghapus kenangan
void deleteMemoryFirst(LogList &Log);
void deleteMemoryLast(LogList &Log);
void deleteMemoryAfter(LogList &Log, address Prev);
void deleteList(LogList &Log); // Hapus semua kenangan

// prosedur untuk memperbarui kenangan
void updateMemoryFirst(LogList &Log);
void updateMemoryLast(LogList &Log);
void updateMemoryAfter(LogList &Log, address Prev);

// fungsi untuk mencari kenangan
address findMemoryByName(LogList Log, string name);
address findMemoryBefore(LogList Log, string name);
void printMemoriesByType(LogList Log, string type);


#endif //ERDTREE_LOG_H
```

### 1.2 eldenRing.cpp
```cpp
#include "eldenRing.h"
#include <iostream>
using namespace std;

void createLog(LogList &Log) {
    Log.first = nil;
}

address alokasiMemory(infotype data) {
    address P = new Node;
    P -> isiData = data;
    P -> next = nil;
    return P;
}

void dealokasiMemory(address &P) {
    delete P;
}

void printLog(LogList Log){
    if (isEmpty(Log)) {
        cout << "[...Log Kenangan kosong...]" << endl;
    } else {
        address P = Log.first;
        int i = 1;
        while (P != nil) {
            cout << i << ". Nama     : " << P->isiData.name << endl;
            cout << "   Tipe     : " << P->isiData.type << endl;
            cout << "   Lokasi   : " << P->isiData.location << endl;
            cout << "   Rune     : " << P->isiData.runeReward << endl << endl;
            P = P->next;
            i++;
        }
    }
}

bool isEmpty(LogList Log){
    return Log.first == nil;
}

int nbList(LogList Log){
    int count = 0;
    address P = Log.first;
    while (P != nil) {
        count++;
        P = P -> next;
    }
    return count;
}

// fungsi insert
void insertMemoryFirst(LogList &Log, address P) {
    P -> next = Log.first;
    Log.first = P;
}

void insertMemoryLast(LogList &Log, address P) {
    if (isEmpty(Log)){
        Log.first = P;
    } else {
        address bantu = Log.first;
        while (bantu->next != nil) {
            bantu = bantu->next;
     }
    bantu -> next = P;   
}
}

void insertMemoryAfter(LogList &Log, address P, address Prev) {
    if (Prev != nil) {
        P->next = Prev->next;
        Prev->next = P;
    } else {
        cout << "[Gagal: Kenangan 'Sebelum' tidak ditemukan!]" << endl;
    }
}

/*--- FUNGSI DELETE (MENGHAPUS KENANGAN) ---*/
void deleteMemoryFirst(LogList &Log) {
    if (!isEmpty(Log)) {
        address P = Log.first;
        Log.first = P->next;
        dealokasiMemory(P);
        cout << "[Kenangan pertama berhasil dihapus.]" << endl;
    } else {
        cout << "[Gagal: Log sudah kosong!]" << endl;
    }
}

void deleteMemoryLast(LogList &Log) {
    if (isEmpty(Log)) {
        cout << "[Gagal: Log sudah kosong!]" << endl;
        return;
    }
    
    if (Log.first->next == nil) { // Jika cuma 1 kenangan
        dealokasiMemory(Log.first);
        Log.first = nil;
    } else { // Jika > 1 kenangan
        address P = Log.first;
        address Prev = nil;
        while (P->next != nil) {
            Prev = P;
            P = P->next;
        }
        // P = node terakhir, Prev = node kedua terakhir
        Prev->next = nil;
        dealokasiMemory(P);
    }
    cout << "[Kenangan terakhir berhasil dihapus.]" << endl;
}

void deleteMemoryAfter(LogList &Log, address Prev) {
    if (Prev != nil && Prev->next != nil) {
        address P = Prev->next; // P = node yang mau dihapus
        Prev->next = P->next;
        dealokasiMemory(P);
        cout << "[Kenangan setelah '" << Prev->isiData.name << "' berhasil dihapus.]" << endl;
    } else {
        cout << "[Gagal: Tidak ada kenangan setelah '" << Prev->isiData.name << "'!]" << endl;
    }
}

void deleteList(LogList &Log) {
    address P = Log.first;
    while (P != nil) {
        address temp = P;
        P = P->next;
        dealokasiMemory(temp);
    }
    Log.first = nil;
    cout << "[...Semua kenangan telah terhapus dari Log...]" << endl;
}


/*--- FUNGSI UPDATE (MENGUBAH KENANGAN) - MODUL 5 ---*/
void updateMemoryFirst(LogList &Log) {
    if (!isEmpty(Log)) {
        cout << "--- Mengubah Kenangan Pertama ('" << Log.first->isiData.name << "') ---" << endl;
        cout << "Nama baru: "; getline(cin >> ws, Log.first->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> Log.first->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, Log.first->isiData.location);
        cout << "Rune baru: "; cin >> Log.first->isiData.runeReward;
        cout << "[Kenangan pertama berhasil diupdate!]\n" << endl;
    }
}

void updateMemoryLast(LogList &Log) {
    if (!isEmpty(Log)) {
        address P = Log.first;
        while (P->next != nil) {
            P = P->next;
        }
        cout << "--- Mengubah Kenangan Terakhir ('" << P->isiData.name << "') ---" << endl;
        cout << "Nama baru: "; getline(cin >> ws, P->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> P->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, P->isiData.location);
        cout << "Rune baru: "; cin >> P->isiData.runeReward;
        cout << "[Kenangan terakhir berhasil diupdate!]\n" << endl;
    }
}

void updateMemoryAfter(LogList &Log, address Prev) {
    if (Prev != nil && Prev->next != nil) {
        address P = Prev->next;
        cout << "--- Mengubah Kenangan setelah '" << Prev->isiData.name << "' ---" << endl;
        cout << "(Data lama: '" << P->isiData.name << "')" << endl;
        cout << "Nama baru: "; getline(cin >> ws, P->isiData.name);
        cout << "Tipe baru (Boss/Lokasi/NPC/Item): "; cin >> P->isiData.type;
        cout << "Lokasi baru: "; getline(cin >> ws, P->isiData.location);
        cout << "Rune baru: "; cin >> P->isiData.runeReward;
        cout << "[Kenangan berhasil diupdate!]\n" << endl;
    } else {
        cout << "[Gagal: Tidak ada kenangan setelah '" << Prev->isiData.name << "'!]\n" << endl;
    }
}


/*--- FUNGSI SEARCHING (MENCARI KENANGAN) - MODUL 5 ---*/
address findMemoryByName(LogList Log, string name) {
    address P = Log.first;
    while (P != nil) {
        if (P->isiData.name == name) {
            return P;
        }
        P = P->next;
    }
    return nil; // Tidak ketemu
}

address findMemoryBefore(LogList Log, string name) {
    if (isEmpty(Log) || Log.first->isiData.name == name) {
        return nil; // Tidak ada node "before" jika list kosong atau datanya di node first
    }
    
    address P = Log.first;
    while (P->next != nil) {
        if (P->next->isiData.name == name) {
            return P; // P adalah node sebelum node yang dicari
        }
        P = P->next;
    }
    return nil; // Tidak ketemu
}

void printMemoriesByType(LogList Log, string type) {
    bool found = false;
    address P = Log.first;
    cout << "--- Hasil Pencarian Kenangan Tipe: '" << type << "' ---" << endl;
    while (P != nil) {
        if (P->isiData.type == type) {
            cout << " * " << P->isiData.name << " (di " << P->isiData.location << ")" << endl;
            found = true;
        }
        P = P->next;
    }
    if (!found) {
        cout << "[Tidak ada kenangan dengan tipe '" << type << "' ditemukan.]" << endl;
    }
    cout << endl;
}


```

### 1.3 Program main.cpp
```cpp
#include "eldenRing.h"
#include <iostream>
#include <limits> // Perlu untuk pressEnter
#include <string>
using namespace std;

// Fungsi helper untuk jeda (sudah diperbaiki)
void pressEnter() {
    cout << "\n...Tekan Enter untuk melanjutkan perjalanan..." << endl;
    // Membersihkan buffer input sebelum cin.get()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    LogList LogTarnished; 
    createLog(LogTarnished);
    address P, Prev; 

    cout << "=================================================" << endl;
    cout << "       CATATAN PERJALANAN DI LAND OF SHADOW      " << endl;
    cout << "=================================================\n" << endl;

    // === TAHAP 1: INSERT (Menemukan Kenangan) ===
    cout << "--- TAHAP 1: MENAMBAH KENANGAN (INSERT) ---\n" << endl;
    cout << "Log Awal:" << endl;
    printLog(LogTarnished); // Mencetak "[...Log Kenangan kosong...]"

    cout << "\nAKSI: insertMemoryFirst(\"Scadutree Fragment\")" << endl;
    P = alokasiMemory({"Scadutree Fragment", "Item", "Gravesite Plain", 0});
    insertMemoryFirst(LogTarnished, P);

    cout << "\nAKSI: insertMemoryLast(\"Divine Beast Dancing Lion\")" << endl;
    P = alokasiMemory({"Divine Beast Dancing Lion", "Boss", "Belurat", 80000});
    insertMemoryLast(LogTarnished, P);

    cout << "\nAKSI: insertMemoryLast(\"Rellana, Twin Moon Knight\")" << endl;
    P = alokasiMemory({"Rellana, Twin Moon Knight", "Boss", "Shadow Keep", 120000});
    insertMemoryLast(LogTarnished, P);
    
    cout << "\nAKSI: insertMemoryAfter(..., \"Miquella's Cross\", ...setelah \"Divine Beast\")" << endl;
    Prev = findMemoryByName(LogTarnished, "Divine Beast Dancing Lion");
    P = alokasiMemory({"Miquella's Cross", "NPC", "Scadutree Base", 0});
    insertMemoryAfter(LogTarnished, P, Prev);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\n--- TAHAP 1 SELESAI ---" << endl;
    cout << "Total Kenangan: " << nbList(LogTarnished) << endl;
    pressEnter();

    // === TAHAP 2: UPDATE (Mengkoreksi Kenangan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 2: MENGUBAH KENANGAN (UPDATE)     " << endl;
    cout << "=================================================\n" << endl;
    
    cout << "AKSI: updateMemoryFirst() pada \"Scadutree Fragment\"..." << endl;
    updateMemoryFirst(LogTarnished); // Ini akan interaktif meminta input baru

    cout << "AKSI: updateMemoryLast() pada \"Rellana\"..." << endl;
    updateMemoryLast(LogTarnished); // Ini akan interaktif meminta input baru


    cout << "\nAKSI: updateMemoryAfter() pada node setelah \"Miquella's Cross\"..." << endl;
    Prev = findMemoryByName(LogTarnished, "Miquella's Cross"); 
    updateMemoryAfter(LogTarnished, Prev); // akan mengupdate "Rellana"
    printLog(LogTarnished); // Langsung cetak hasilnya
    
    
    cout << "\n--- TAHAP 2 SELESAI ---" << endl;
    pressEnter();

    // === TAHAP 3: SEARCHING (Mengingat Kembali) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 3: MENCARI KENANGAN (SEARCH)      " << endl;
    cout << "=================================================\n" << endl;

    cout << "AKSI: printMemoriesByType(\"Boss\")" << endl;
    printMemoriesByType(LogTarnished, "Boss");

    cout << "\nAKSI: findMemoryByName(\"Messmer the Impaler\")" << endl;
    P = findMemoryByName(LogTarnished, "Messmer the Impaler");
    if (P == nil) {
        cout << "[Kenangan 'Messmer the Impaler' belum ditemukan...]\n" << endl;
    } else {
        cout << "[Ya, kenangan 'Messmer' ada di Log.]\n" << endl;
    }
    
    cout << "\n--- TAHAP 3 SELESAI ---" << endl;
    pressEnter();

    // === TAHAP 4: DELETE (Melupakan Kenangan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 4: MENGHAPUS KENANGAN (DELETE)    " << endl;
    cout << "=================================================\n" << endl;
    cout << "Kondisi List Awal (setelah di-update):" << endl;
    printLog(LogTarnished);

    cout << "\nAKSI: deleteMemoryFirst()" << endl;
    deleteMemoryFirst(LogTarnished);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\nAKSI: deleteMemoryLast()" << endl;
    deleteMemoryLast(LogTarnished);
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\nAKSI: deleteMemoryAfter(..., ...setelah \"Divine Beast\")" << endl;
    Prev = findMemoryByName(LogTarnished, "Divine Beast Dancing Lion"); 
    deleteMemoryAfter(LogTarnished, Prev); // Hapus "Miquella's Cross"
    printLog(LogTarnished); // Langsung cetak hasilnya

    cout << "\n--- TAHAP 4 SELESAI ---" << endl;
    cout << "Total Kenangan Tersisa: " << nbList(LogTarnished) << endl;
    pressEnter();

    // === TAHAP 5: CLEANUP (Akhir Perjalanan) ===
    cout << "=================================================" << endl;
    cout << "       TAHAP 5: MENGHAPUS SEMUA (DELETELIST)   " << endl;
    cout << "=================================================\n" << endl;
    
    cout << "AKSI: deleteList()" << endl;
    deleteList(LogTarnished);
    printLog(LogTarnished);
    cout << "Total Kenangan Tersisa: " << nbList(LogTarnished) << endl;

    cout << "\n=================================================" << endl;
    cout << "            SHADOW OF THE ERDTREE - END            " << endl;
    cout << "=================================================" << endl;

    return 0;
}
```

#### Output:
#### 1. tahapan insert hasil
<img width="1170" height="823" alt="image" src="https://github.com/user-attachments/assets/59eadb94-cddf-4554-a684-f85083875825" />

#### 2. Tahapan update 
<img width="1184" height="741" alt="image" src="https://github.com/user-attachments/assets/11360c96-8b7a-42ab-a96a-59b4c425737a" />

#### 3. tahapan searching
<img width="1170" height="823" alt="image" src="https://github.com/user-attachments/assets/af2a7c71-57b7-4b99-b600-abba7bc95f62" />

#### 4. Tahapan Deleate
<img width="1170" height="823" alt="image" src="https://github.com/user-attachments/assets/8909e040-a20a-484e-a2f0-8773aa4f4a00" />
<img width="1170" height="823" alt="image" src="https://github.com/user-attachments/assets/d8c17bb5-2b50-4832-9923-3624e5663118" />
<img width="1170" height="823" alt="image" src="https://github.com/user-attachments/assets/bc9bb0f1-e76d-4afa-a421-e88f9ef93adc" />

#### Full code screenshot:
#### 1. FULL BAGIAN .h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/51c8dc0a-6d00-4cfd-90d2-2b3789fb4a39" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/e0b20d5a-0fa8-43bf-a27a-791992663d40" />


   
#### 2. FULL BAGIAN .cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/1ce212f9-3b13-42f7-807b-5180790a4f5e" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/fc82b5bf-1aab-43ad-9dd9-60bd100c7bc7" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ebeef109-75e5-44ac-a13b-bb6b2b9052e8" />

   
#### 3. FULL BAGIAN main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/61fc7b15-4ac8-46ed-b157-c4d769438d0b" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/be325df7-085b-452b-b1d1-d1a541cd8d94" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/edd088f2-7ff0-4222-8260-77bc008f40bf" />






### 2. Latihan modul 2,3,4
<img width="566" height="740" alt="image" src="https://github.com/user-attachments/assets/709112b7-b4bf-444a-8865-6ff6eb86991c" />
<img width="566" height="528" alt="image" src="https://github.com/user-attachments/assets/17196caa-26c1-44ce-a877-1c9f6c54c845" />

### 2.1 Program Singlylist.h
```h
// implementasi latihan no 2
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;    
#define nil NULL

typedef  int infotype;
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void  insertFirst(List &L, address P);

//implementasi latihan no 3
address findElm(List L, infotype x);

// implementasi latihan no 4
int sumInfo(List L);

#endif
```

### 2.2 Program Singlylist.cpp
```cpp
// Implementasi file Singly Linked List (SLL)
#include "Singlylist.h"
#include <iostream>
using namespace std;
#define nil NULL

void CreateList(List &L) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    L.first = nil;
}
address alokasi(infotype x) {
    /* Mengembalikan address hasil alokasi node baru
       Jika alokasi gagal, kembalikan Nil */
    address P = new ElmList;
    if (P != nil) {
        P -> info = x;
        P -> next = nil;
    }
    return P;
}
void dealokasi(address &P){
/* I.S. P terdefinisi
       F.S. memori yang digunakan P dikembalikan */
    delete P;
}
void printInfo(List L){
    /* I.S. List mungkin kosong
       F.S. Menampilkan info semua elemen list */
    address P = L.first;
    while (P != nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}
void  insertFirst(List &L, address P){
    /* I.S. sembarang, P sudah dialokasikan
       F.S. P menjadi elemen pertama list */
    if (L.first == nil) {
        L.first =  P;
    }
    else {
        P -> next = L.first;
        L.first = P;
    }
}

// implementasi latihan no 3
address findElm(List L, infotype x) {
    /* Mencari apakah ada elemen list dengan P->info = x */
    address P = L.first;
    while (P != nil) {
        if ( P -> info == x) {
            return P; // ketemu, kembalikan addressnya
        }
        else {
            P = P -> next; // pindah ke node selanjutnya
        }
    }
    // jika tidak ada
    return nil;
}

// implementasi latihan no 4
int sumInfo(List L) {
    /* Mengembalikan total penjumlahan info dari semua elemen */
    int total = 0;
    address P = L.first;
    while (P != nil) {
        total += P -> info;
        P = P -> next;
    }
    return total;
}
```

### 2.3 Program main.cpp
```cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    // implementasi latihan no 2
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);
    P1 = alokasi(2);
    insertFirst(L,P1);
    P2 = alokasi(0);
    insertFirst(L,P2);
    P3 = alokasi(8);
    insertFirst(L,P3);
    P4 = alokasi(12);
    insertFirst(L,P4);
    P5 = alokasi(9);
    insertFirst(L,P5);
    cout << "Hasil latihan 2: " << endl;
    printInfo(L);

    // implementasi latihan no 3
    cout << "Hasil latihan 3: " << endl;
    address P_cari = findElm(L, 8);
    if (P_cari != nil) {
        cout << P_cari -> info << " ditemukan dalam list." << endl;
    }
    else {
        cout << "tidak ditemukan dalam list." << endl;
    }
    cout << endl;

    // implementasi latihan no 4
    cout << "Hasil latihan 4: " << endl;
    int total = sumInfo(L);
    cout << "Total penjumlahan elemen dalam list: " << total << endl;

return 0;

}
```

#### Output

#### 1. Output 2
<img width="572" height="259" alt="image" src="https://github.com/user-attachments/assets/eb92b28f-dcd3-47bd-9890-7cab5852c588" />

#### 2. Output 3
<img width="570" height="264" alt="image" src="https://github.com/user-attachments/assets/3aa915f9-fbf6-4736-8326-6110b8841235" />

#### 3. output 4
<img width="576" height="410" alt="image" src="https://github.com/user-attachments/assets/ddf05ce2-033e-490e-993e-33b4e5e9c5f0" />

#### FULL CODE SCREENSHOT:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f91c0022-c0c4-4f36-bb17-3bae28d3d44a" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/bfad9d55-9374-4466-8323-a3ae7528e0ff" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2767a62a-608d-4204-b411-eea69e375460" />





## Kesimpulan
Berdasarkan praktikum modul 5 yang telah saya dapatkan bahwa modul kali ini hanya melanjutkan ADT Singly Linked List dari modul sebelumya. Modul kali ini lebih berfokus pada implementasi dua operasi baru pada SLL, yaitu <code>Update dan Searching</code>. Disini saya berhasil mengimplementasikan dan juga membuat 3 variasi update seperti <code>updateFirst. updateLast, updateAfter</code> yang digunakan untuk mengubah info dari node tanpa mengubah pointer nextnya.

Selain itu juga saya belajar mengimplementasikan tiga metode searching yaitu <code>FindNodeByData, FindNodeByAddress, FindNodeByRange</code> dengan prinsip traversal(penelusuran) dari first(awal) hingga nil(akhir) untuk menemukan node berdasarkan pencarian tertentu. Kesimpulan yang didapat menurut saya juga yaitu mampu menerapkan searching dan juga update pada ADT SLL ini, intinya fondasi dasar praktikum kali ini ialah harus mengerti ADT dan SLL basic(bagian pertama) agar dapat melanjutkan materi modul selanjutnya.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.









