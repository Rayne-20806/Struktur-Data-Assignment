<h1 align="center">Laporan Praktikum Modul MULTI LINKED LIST (13)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
## Teori Multi Linked List
Multi Linked List atau MLL merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama lain. Tiap elemen dalam multi link list dapat membentuk list sendiri. Biasanya ada yang sebagai list induk dan list anak. Beriku contoh gambar multi link list agar lebih jelas.

<img width="833" height="593" alt="image" src="https://github.com/user-attachments/assets/6d6a5cc1-d672-4fc1-9c1a-20849273f2bc" />



Dalam contoh diatas merupakan implementasi multi linked list yang dimana terdapat dua buah list yaitu list pegawai sebagai parent list dan list anak sebagai child.

## Operasi-Operasi dasar MLL
Pada materi kali ini, selain kita membahas apa itu multi linked list beserta contoh gambar bagaimana multi linked list di implementasikan, selanjutnya kita akan membahas apa saja operasi-operasi dasar yang ada pada MLL:
<ol>
  <li>
    Insert Anak. Dalam penambahan elemen anak atau child harus diketahui terlebih dahulu elemen induknya
  </li>

  <img width="675" height="792" alt="image" src="https://github.com/user-attachments/assets/9cea470c-b1a8-4a90-9d35-a051967a6c35" />


  <li>
    Insert induk atau parent. Untuk insert elemen induk sama dengan konsep pada Single Linked List, Doubly linked list, dan juga Circuler Linked List
  </li>
  <li>
    Delete Anak. Sama dengan insert anak untuk delete anak maka harus diketahui terlebih dahulu elemen induknya. Berikut ini gambar ilustrasinya untuk delete last pada induk peg 1:
  </li>

  <img width="546" height="411" alt="image" src="https://github.com/user-attachments/assets/b1e49348-b4c6-4099-a694-b8486b692180" />

  <li>
    Delete Induk. Untuk delete elemen induk maka saat dihapus maka seluruh anak dengan induk tersebut juga harus dihapus, berikut gambar ilustrasinya jika kita menghapus elemen induk maka elemen anaknya akan terhapus semuanya yang tersambung dengan elemen induk yang akan dihapus.
  </li>

  <img width="579" height="447" alt="image" src="https://github.com/user-attachments/assets/1b217b5a-7896-4de2-8d6a-4b49a9380e50" />



</ol>






## Guided 


## 1. Multi Linked List
## 1.1 mll.h
```h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

## 1.2 mll.cpp
```cpp
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```


## 1.3 main.cpp
```cpp
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

<ol>
  <li>
    File <code>mll.h</code>. File ini berisi Abstract Data Type atau ADT Multi Link List. Struktur data ini terdiri dari dua jenis node atau elemen yaitu nodeParent untuk kategori makanan dan nodeChild untuk data makanan. Keunikan dari struktur multi link list ialah setiap nodeParent bisa memiliki komponen listAnak didalamnya yang memungkinkan bahwa satu kategori makanan bisa memiliki banyak menu. Pada file ini juga mendeklarasikan fungsi atau prosedur primitif seperti manajemen memori(alokasi dan dealokasi), manajemen list, operasi list seperti insert, delete, find dan juga update, serta pencetakan list
  </li>

  <li>
    File <code>mll.cpp</code>. File ini berisi semua implementasi logika dari seluruh fungsi atau prosedur yang sudah dideklarasikan pada file .h.
  </li>

  <li>
    File <code>main.cpp</code>. File ini merupakan program utama dalam menjalankan file ADT yang sudah kita buat. Program ini akan melakukan inisialisasi list, membuat 3 kategori makanan (Makanan Berat, Minuman), dan memasukkan beberapa menu ke dalam kategori yang sesuai. Selanjutnya program akan menguji validitas fungsi update (mengubah nama/harga menu), find/pencarian, dan delete yang digunakan untuk menghapus menu spesifik dan menghapus kategori beserta seluruh isinya. Program ini juga akan menampilkan hasil MLL pada bagian akhir.
  </li>
</ol>


## Unguided 

### 2. Soal dua
<img width="512" height="56" alt="image" src="https://github.com/user-attachments/assets/26675828-1356-4e95-91d4-af5dc5224ee9" />


### 2.1 multilist.h
```h
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;
#define Nil NULL

// definisi tipe data dan ADT multilist
typedef int infotypeinduk;
typedef int infotypeanak;
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

// struktu Elemen untuk anak
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};
struct listanak {
    address_anak first;
    address_anak last;
};

// struktur Elemen untuk induk
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak; // list anak ada di induknya
    address next;
    address prev;
};
struct listinduk {
    address first;
    address last;
};

//deklarasikan fungsi atau prosedur primiif

// Cek Kosong
bool ListEmpty(listinduk L);
bool ListEmptyAnak(listanak L);

// Create List
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

// Manajemen Memori
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

// Pencarian
address findElm(listinduk L, infotypeinduk X);
address_anak findElmAnak(listanak Lanak, infotypeanak X); // Saya rapikan namanya

// Penambahan Elemen Induk
void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

// Penambahan Elemen Anak
void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

// Penghapusan Elemen Induk
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X); // Hapus berdasarkan nilai

// Penghapusan Elemen Anak
void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X); // Hapus berdasarkan nilai

// Cetak
void printInfo(listinduk L);
void printInfoAnak(listanak Lanak);

#endif
```

### 2.2 multilist.cpp
```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

// penerapan fungsi atau prosedur


// CEK KOSONG
bool ListEmpty(listinduk L) {
    return L.first == Nil;
}

bool ListEmptyAnak(listanak L) {
    return L.first == Nil;
}

// CREATE LIST 
void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

// --- ALOKASI ---
address alokasi(infotypeinduk P) {
    address newNode = new elemen_list_induk;
    newNode->info = P;
    newNode->next = Nil;
    newNode->prev = Nil;
    CreateListAnak(newNode->lanak); // Inisialisasi list anak di dalamnya
    return newNode;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak newNode = new elemen_list_anak;
    newNode->info = P;
    newNode->next = Nil;
    newNode->prev = Nil;
    return newNode;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

// --- PENCARIAN ---
address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

address_anak findElmAnak(listanak Lanak, infotypeanak X) {
    address_anak P = Lanak.first;
    while (P != Nil) {
        if (P->info == X) return P;
        P = P->next;
    }
    return Nil;
}

// --- INSERT INDUK ---
void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec) {
    if (Prec != Nil) {
        if (Prec == L.last) {
            insertLast(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

// --- INSERT ANAK ---
void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
    if (Prec != Nil) {
        if (Prec == L.last) {
            insertLastAnak(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

// --- DELETE INDUK ---
void delFirst(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void delLast(listinduk &L, address &P) {
    if (!ListEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void delAfter(listinduk &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        if (Prec->next == L.last) {
            delLast(L, P);
        } else {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delP(listinduk &L, infotypeinduk X) {
    address P = findElm(L, X);
    if (P != Nil) {
        address temp;
        if (P == L.first) delFirst(L, temp);
        else if (P == L.last) delLast(L, temp);
        else delAfter(L, temp, P->prev);
        dealokasi(temp);
    }
}

// --- DELETE ANAK ---
void delFirstAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void delLastAnak(listanak &L, address_anak &P) {
    if (!ListEmptyAnak(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        if (Prec->next == L.last) {
            delLastAnak(L, P);
        } else {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void delPAnak(listanak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X);
    if (P != Nil) {
        address_anak temp;
        if (P == L.first) delFirstAnak(L, temp);
        else if (P == L.last) delLastAnak(L, temp);
        else delAfterAnak(L, temp, P->prev);
        dealokasiAnak(temp);
    }
}

// --- CETAK ---
void printInfo(listinduk L) {
    cout << "\n[ISI MULTI LIST]" << endl;
    if (ListEmpty(L)) {
        cout << "List Kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Induk: " << P->info << endl;
            printInfoAnak(P->lanak); // Cetak anaknya
            P = P->next;
            cout << "-----------------" << endl;
        }
    }
}

void printInfoAnak(listanak Lanak) {
    if (ListEmptyAnak(Lanak)) {
        cout << "   (Tidak ada anak)" << endl;
    } else {
        address_anak P = Lanak.first;
        while (P != Nil) {
            cout << "   -> Anak: " << P->info << endl;
            P = P->next;
        }
    }
}
```

### 2.3 main.cpp
```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Buat List Induk
    listinduk L;
    CreateList(L);
    cout << "=== PROGRAM MULTI LIST ANGKA ===" << endl;

    // 2. Insert Induk (1, 2, 3)
    address Induk1 = alokasi(1);
    insertFirst(L, Induk1);
    
    address Induk2 = alokasi(2);
    insertLast(L, Induk2);
    
    address Induk3 = alokasi(3);
    insertLast(L, Induk3);

    // 3. Insert Anak ke Induk 1 (Anak: 10, 20)
    insertLastAnak(Induk1->lanak, alokasiAnak(10));
    insertLastAnak(Induk1->lanak, alokasiAnak(20));

    // 4. Insert Anak ke Induk 2 (Anak: 50)
    insertLastAnak(Induk2->lanak, alokasiAnak(50));

    // 5. Insert Anak ke Induk 3 (Anak: 99, 100)
    insertLastAnak(Induk3->lanak, alokasiAnak(99));
    insertLastAnak(Induk3->lanak, alokasiAnak(100));

    // 6. Cetak
    printInfo(L);

    // 7. Hapus Anak 50 dari Induk 2
    cout << "\n>> Menghapus Anak 50 dari Induk 2..." << endl;
    delPAnak(Induk2->lanak, 50);
    printInfo(L);

    return 0;
}
```


#### Output:

<img width="1672" height="737" alt="image" src="https://github.com/user-attachments/assets/7d28af95-aeef-41f1-9aec-ba15a6b39120" />

Program ini dibuat dengan mengimplementasikan multi link list, kita disuruh untuk membuat program 46 dari halaman 5-8.
<ol>
  <li>
    File <code>multilist.h</code>. File ini berisi implementasi ADT Multi link list yang terdiri dari dua struktur utama yaitu listinduk dan listanak. Karena ini Multi Link List maka setiap elemen listInduk memiliki komponen khusus lanak yang merupakan sebuah listanak. Sehingga 1 elemen induk bisa memiliki banyak elemen anak. Program ini mengimplementasikan juga Doubly Linked list karena memiliki prev. File ini juga mendeklarasikan banyak fungsi dan prosedur primitif seperti manajemen list, manajemen memory, operasi insert, operasi delete, pencarian elemen, dan cetak elemen.
  </li>

  <li>
    File <code>multilist.cpp</code>. File ini berisi dari semua implementasi dari fungsi atau prosedur yang sudah dideklarasikan pada file .h. Manajemen memori seperti alokasi untuk induk secara otomatis memanggil CreateListAnak untuk menginisialisasi list anaknya agar bisa digunakan. Operasi list terdapat dua yaitu fungsi insert dan delete (satu set untuk induk, satu set untuk anak). Logika insert dan delete masih sama seperti doubly link list dengan mengubah pointer next dan prev. Operasi Cetak,  fungsi printInfo menggunakan nested loop (looping bersarang) di mana loop luar menelusuri setiap elemen induk, dan di dalamnya dipanggil printInfoAnak untuk menelusuri dan mencetak seluruh elemen anak yang dimiliki induk tersebut.
  </li>
  <li>
    File <code>main.cpp</code>. File ini merupakan program utama untuk menguji dari ADT. program ini membuat list induk kosong.
  </li>

</ol>

#### Full code screenshot:

#### Code multilist.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a369132f-932c-49cb-b63c-638e74320961" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/84140b0c-197b-41c4-9df4-b4fe3df675f9" />



#### code multilist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6c7e481a-d2a9-4da2-874e-5ce125c5dec6" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/da69d340-138a-4ce5-a0ec-1f09d9a393ee" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/002b60c4-8543-44e1-ac69-c0da9d5918f7" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/75aacfc2-a601-4362-a14f-16f334b7cf42" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/412fcf6c-7b21-4198-a30e-d1d16f1c17b0" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d9f988f7-93af-4d21-8b6d-1a351e443e05" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/27e74f45-50be-4502-ab94-00b633cdc255" />



#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/07b9ed00-865d-4996-a8da-b6decf637c79" />



### 2. Soal ketiga

<img width="884" height="699" alt="image" src="https://github.com/user-attachments/assets/ec4224fe-45fd-4f56-bc1b-5256dd56fff7" />

<img width="884" height="791" alt="image" src="https://github.com/user-attachments/assets/6d323344-edbc-4376-945c-93b0c7e30310" />

<img width="889" height="623" alt="image" src="https://github.com/user-attachments/assets/bede812e-747a-49d2-b1f5-deccbd7e3518" />


### 3.1 circularlist.h
```h
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
```

### 3.2 circularlist.cpp
```cpp
#include "circularlist.h"
#include <iostream>
using namespace std;

// implementasi fungsi atau prosedur primitif untuk circular double link list
void CreateList(List &L){
    L.First = nil;
}

address alokasi(infotype x) {
    // buat node baru kemudian isi info dengan x dan next dengan nil
    address P = new ElmList;
    P -> info = x;
    P -> next = nil;
    return P;
}

void dealokasi(address P) {
    // hapus node yang ditunjuk P
    delete P;
}

void insertFirst(List &L, address P) {
    // jika list kosong
    if (L.First == nil) {
        L.First = P;
        P -> next = P; // circular dan menunjuk ke dirinya sendiri
    } else { // jika list tidak kosong
        address Last = L.First;
        // cari last node
        while (Last -> next != L.First) {
            Last = Last -> next;
        }
        P -> next = L.First;
        Last -> next = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    // jika list kosong
    if (L.First == nil) {
        insertFirst(L, P); 
    } else {
        // jika list tidak kosong
        address Last = L.First;
        // cari last node
        while (Last -> next != L.First) {
            Last = Last -> next;
        }
        Last -> next = P;
        P -> next = L.First; // circular kembali ke first
    }
}

void insertAfter(List &L, address Prec, address P){
    if (Prec != nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P){
    if (L.First != nil) {
        P = L.First;
        // jika hanya ada satu elemen
        if (P -> next == L.First) {
            L.First = nil;
        } else { 
            // jika lebih dari satu elemen
            address Last = L.First;
            while (Last->next != L.First) {
                Last = Last->next;
            }
            L.First = P->next;
            Last->next = L.First;
        }

    }
}



void deleteLast(List &L, address &P){
    // jika list tidak kosong
    if (L.First != NULL) {
        address Last = L.First;
        address PrecLast = NULL;
        
        // Cari Last dan Sebelum Last (PrecLast)
        while (Last->next != L.First) {
            PrecLast = Last;
            Last = Last->next;
        }
        
        P = Last;
        if (PrecLast == NULL) { // Jika cuma 1 elemen
            L.First = NULL;
        } else {
            PrecLast->next = L.First;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P){
    if (Prec != nil && Prec -> next != L.First) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next = nil;
    } else if (Prec != nil && Prec -> next == L.First) {
        deleteFirst(L, P);
    }
}

// Pencarian berdasarkan NIM
address findElm(List L, infotype x){
    if (L.First == nil) {
        return nil;
    } else {
        address P = L.First;
        do {
            if (P -> info.Nim == x.Nim) {
                return P;
            }
            P = P -> next;
        } while (P != L.First);
        return nil;
    }
}

void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List Kosong" << endl;
    } else {
        address P = L.First;
        int i = 1;
        do {
            cout << "Data ke-" << i << endl;
            cout << "Nama : " << P->info.Nama << endl;
            cout << "NIM  : " << P->info.Nim << endl;
            cout << "L/P  : " << P->info.Jenis_Kelamin << endl;
            cout << "IPK  : " << P->info.IPK << endl;
            cout << "--------------------" << endl;
            P = P->next;
            i++;
        } while (P != L.First);
    }
}
```

### 3.3 main.cpp
```cpp
#include "circularlist.h"
#include <iostream>
using namespace std;

// fungsi bantuan untuk buat data mahasiswa
address createData(string nama, string nim, char jk, float ipk) {
    infotype mhs;
    mhs.Nama = nama;
    mhs.Nim = nim;
    mhs.Jenis_Kelamin = jk;
    mhs.IPK = ipk;
    return alokasi(mhs);
}

int main() {
     List L;
    address P1 = nil;
    address P2 = nil;
    infotype x; // variabel bantuan untuk searching (findElm)

    CreateList(L);

    cout << "coba insert first, last, dan after" << endl;

    // 1. Insert First (Danu)
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    // 2. Insert Last (Fahmi)
    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    // 3. Insert Last (Bobi)
    P1 = createData("Bobi", "02", 'l', 3.71);
    insertLast(L, P1); 

    // 4. Insert First (Ali)
    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    // 5. Insert First (Gita)
    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    // --- INSERT AFTER ---

    // 6. Insert Cindi (03) setelah Gita (07)
    x.Nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    // 7. Insert Hilmi (08) setelah Bobi (02)
    x.Nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    // 8. Insert Eli (05) setelah Danu (04)
    x.Nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}
```


#### Output:

<img width="1700" height="877" alt="image" src="https://github.com/user-attachments/assets/d0ddff5a-64e1-4487-bf26-32aaa1a999b9" />

Program ini mengimplementasikan circular linked list dimana elemen akhir akan menyambung kembali dengan elemen awal pada list. Program ini juga tentang bagaimana kita membuat ADT MLL dengan tema mahasiswa.

<ol>
  <li>
    File <code>circularlist.h</code>. File ini mendefinisikan struktur data Circular Single Linked List. Berbeda dengan list linear biasa, elemen akhir atau last pada list ini memiliki pointer next yang akan kembali menunjuk ke elemen pertama atau first, sehingga tidak ada nilai null pada next. Didalamnya juga mendefinisikan struktur data Mahasiswa yang berisi Nama, Nim, Jenis Kelamin, IPK yang digunakan sebagai tipe data info. File ini juga mendeklrasikan prototype fungsi primitif manajemen list, operasi insert list, operasi pencarian list, operasi cetak list.
  </li>

  <li>
    File <code>circularlist.cpp</code>. Ini berisi seluruh logika pada implementasi fungsi ataupun prosedur yang sudah dideklarasikan pada file .h. Seperti Operasi insert logikanya mungkin akan lebih komplek dibanding SLL karena memerlukan traversal atau penelusuran hingga elemen akhir untuk memperbarui pointer nextnya agar tetep menunjuk ke elemen pertama. Operasi delete ini meskipun kita mendeklarasikan pada file .h dan menerapkan logikanya pada file circular.cpp tapi operasi delete ini tidak dipakai karena sesuai ketentuan soal, namun penghapusan elemen memerlukan penyesuaian pointer elemen terakhir jika elemen pertama dihapus. Operasi print digunakan untuk menampilkan list yang sudah di buat.
  </li>

  <li>
    File <code>main.cpp</code>. File ini akan menguji keseluruhan program yang sudah kita buat pada 2 file sebelumnya, contohnya akan melakukan insertFirst(Ali.Danu) untuk tambah di awal, InsertLast(Fahmi, Bobi, Gita) untuk tambah di akhir, dan insertAfter(Cindi, Helmi, Eli) yang didahului oleh fungsi findElm untuk mencari lokasi penyisipan berdasarkan NIM mereka. Hasil akhirnya ditampilkan menggunakan printInfo untuk memverifikasi bahwa data tersusun sesuai logika Circular List, di mana urutan elemen saling terhubung tanpa putus.
  </li>
</ol>


#### Full code screenshot:

#### Code circularlist.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/7dc58913-a50b-4e9b-9c52-329269f897dd" />


#### code circularlist.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/24819d19-2841-49b1-a42e-e0006ede5cfb" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/bbdf3016-aa14-45fc-a839-c73d821623d8" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6cadc71d-d325-4f94-9a6e-f9f40e3a6fdb" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/78e8de4f-bc0c-4fc4-86b2-549ac1d83b6e" />


#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d5c449b6-254c-4e9c-a3fc-b8718c6ff6ae" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/227473cf-610b-4ffc-b602-d68a3f58a135" />



## Kesimpulan
Berdasarkan praktikum yang dilaksanakan pada hari ini, Saya mempelajari materi baru terkait pengembangan struktur data linked list yang lebih kompleks daripada linked list sebelumnya yang sudah saya pelajari, yaitu Multi Linked LIst dan juga Circular Linked List (List melingkar atau bundar atau bulat bentuknya). Pada Multi Linked List saya memahami juga terkait representasi data hierarkis one to many yang dimana setiap node atau elemen induk bisa memiliki linked list anaknya sendiri atau jika tidak ada ya tidak masalah. Selanjutnya Circular Linked List dimana sebuah pointer elemen terakhir akan kembali menunjuk ke elemen pertama sehingga membentuk siklus bulat atau tertutup tanpa adanya nilai NULL. Melalui latihan ini saya mendapat pemahaman baru dan juga bentuk code code serta visualisasi yang jelas terkait dengan materi modul 13 kali ini.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.













