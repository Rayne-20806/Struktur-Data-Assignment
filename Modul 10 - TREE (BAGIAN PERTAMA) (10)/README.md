# <h1 align="center">Laporan Praktikum Modul TREE (BAGIAN PERTAMA) (10)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### 1. Konsep Rekursif
Rekursif adalah suatu proses pengulangan sesuatu dengan cara kesamaan diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek besar. Berikut manfaat dengan menggunakan sub program: 
<ol>
  <li>
    meningkatkan readibility, yaitu mempermudah pembacaan program
  </li>
  <li>
      Meningkatkan modularity, memecah sesuatu yang besar menjadi modul-modul yang lebih kecil
  </li>
  <li>
    Meningkatkan reusability, yaitu sub program dapat dipakai berulang kali dengan hanya memanggil sub program tersebut tanpa menuliskan perintah-perintah yang semestinya diulang-ulang
  </li>
</ol>

<img width="688" height="498" alt="image" src="https://github.com/user-attachments/assets/a240c402-ad79-4b9c-9639-2fd3dad318a9"/>


### 2. Kriteria Rekursif
Dengan melihat sifa sub program rekursif diatas, maka sub program rekursif harus memiliki: Kondisi yang menyebabkan pemanggilan dirinya berhenti (special condition) dan Pemanggilan diri sub program (jika special condition tidak terpenuhi.

Secara umum bentuk dari sub program rekursif memiliki statemen kondisional:
<ol>
  <li>
    If kondisi khusus tidak dipenuhi
  </li>
  <li>
    then panggil diri sendiri dengan parameter yang sesuai
  </li>
  <li>
    else lakukan instruksi yang akan dieksekusi bila kondisi khusus dipenuhi
  </li>
</ol>


### 3. Kekurangan Rekursif
Konsep penggunaan yang terlihat mudah karena fungsi rekursif dapat menyederhanakan solusi dari
suatu permasalahan, sehingga sering kali menghasilkan bentuk algoritma dan program yang lebih
singkat dan lebih mudah dimengerti.
Kendati demikian, penggunaan rekursif memiliki beberapa kekurangan antara lain:
<ol>
  <li>
    Memerlukan memori yang lebih banyak untuk menyimpan activation record dan variabel lokal.
  </li>

  <li>
    Memerlukan waktu yang lebih banyak untuk menangani activation record.
  </li>
</ol>

Secara umum gunakan penyelesaian rekursif hanya jika: Penyelesaian sulit dilaksanakan secara iteratif, efisiennsi dengan cara rekursif sudah memadai, efisiensi bukan masalah dibandingkan dengan kejelasan logika program.

### 4. Tree dan Pengertian dari Tree
Pada modul sebelumnya kita sudah belajar dan mengenal jenis struktur data yang linear, seperti : list, stack, dan queue. Adapun jenis struktur data yang kita pelajari adalah Tree (Struktur data non linear.

Berikut ini anatomi dari suatu Tree:
<img width="803" height="694" alt="image" src="https://github.com/user-attachments/assets/1bbccf7e-f90a-4755-a9cb-83b70934f24e" />

### 5. Jenis Jenis Tree.
#### 1. Orderen Tree
Yaitu pohon yang urutan anak-anaknya penting.

<img width="424" height="310" alt="image" src="https://github.com/user-attachments/assets/85098a3b-6143-410f-b9cd-2263c15c2027" />

#### 2. Binary Tree
Setiap node di Binary Tree hanya dapat mempunyai maksimum 2 children tanpa pengecualian.
<img width="592" height="742" alt="image" src="https://github.com/user-attachments/assets/009e7b82-7fc4-426f-a3b4-89e6410741e3" />

### 6. Operasi-Operasi dalam Binary Search Tree
<ol>
  <li>
    Insert, jika node yang akan diinsert lebih kecil, maka diinser pada left subtree, jika lebih besar maka insert pada Right Subtree.
  </li>
  <li>
    Update, Jika setelah diupdate posisi/lokasi node yang bersangkutan tidak sesuai dengan ketentuan, maka
harus dilakukan dengan proses REGENERASI agar tetap memenuhi kriteria Binary Search Tree.
  </li>
  <li>
    Search, Proses pencarian elemen pada binary tree dapat menggunakan algoritma rekursif binary search.
  </li>
  <li>
    delete
  </li>
  <li>
    most-left, Most-left node adalah node yang berada paling kiri dalam tree. Dalam konteks binary search tree
(BST), most-left node adalah node dengan nilai terkecil, yang dapat ditemukan dengan mengikuti
anak kiri (left child) dari root hingga mencapai node yang tidak memiliki anak kiri lagi
  </li>
  <img width="281" height="299" alt="image" src="https://github.com/user-attachments/assets/1e75792f-2998-4c98-b2a8-c19fd6d33009" />

  <li>
    most-right, Most-right node adalah node yang berada paling kanan dalam tree. Dalam konteks binary search
tree (BST), most-right node adalah node dengan nilai terbesar, yang dapat ditemukan dengan
mengikuti anak kanan (right child) dari root hingga mencapai node yang tidak memiliki anak kanan
lagi.
  </li>
  <img width="220" height="273" alt="image" src="https://github.com/user-attachments/assets/abd5e43b-22d5-4d83-a72e-250c35ed877e" />

</ol>





## Guided 


## 1. Binary Search Tree
## 1.1 bst.h
```h
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;
#define Nil NULL

typedef struct  BST *node;
struct  BST {
    int angka;
    node left;
    node right;
};
typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi (int angka);
void dealokasi (node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder (BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight (BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size (BinTree tree);
int height(BinTree tree);

#endif
```

## 1.2 bst.cpp
```cpp
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```


## 1.3 main.cpp
```cpp
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Program Guided ini adalah implementasi Binary Search Tree (BST). BST adalah jenis pohon biner dimana data yang lebih kecil dari root akan selalu berada di anak kiri, dan data yang lebih besar akan berada di anak kanan.
Berikut penjelasan singkat untuk file-file ADT pada Binary Search Tree ini:
<ol>
  <li>
    File bst.h, ini mendefinisikan Node. Setiap Node punya 3 bagian yaitu: angka(data integer), left(pointer ke anak kiri), right(pointer ke anak kanan). BinTree : merupakan alias untuk pointer node. Ini disebut sebagai pohon yang sebenarnya hanya pointer ke root.
    Kemudian setelah itu didalam file ini terdapat fungsi-fungsi primitif untuk Binary Search Tree seperti <code>insertNode, deleteNode, SearchByData, dan masih banyak lagi</code>
  </li>

  <li>
    file bst.cpp, disini merupakan seluruh implementasi dari fungsi-fungsi primitif untuk Binary Search Tree
  </li>
  <li>
    File main.cpp, Ini adalah program utama yang menggunakan menu switch-case agar interaktif. Program ini membuat variabel BinTree tree dan menginisialisasinya. User bisa memilih menu 1-11 untuk mencoba semua fitur yang sudah dibuat di bst.cpp, seperti menambah data, menghapus, mencari, dan melihat hasil traversal. Menu ini membuktikan bahwa semua fungsi ADT BST berjalan dengan benar sesuai konsep.
  </li>
</ol>


## Unguided 

### 1. Soal Pertama



### 1.1 .h
```h

```

### 1.2 .cpp
```cpp

```

### 1.3 main.cpp
```cpp


```






#### Output:




#### Full code screenshot:

#### Code .h


#### code .cpp


#### code main.cpp















## Kesimpulan




## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.












