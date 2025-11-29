#ifndef BSTREE_H
#define BSTEE_H
#include <iostream>
using namespace std;
#define Nil NULL

// === SOAL NO 1 ===
//Definisikan ADT untuk Binary Search Tree
typedef int infotype;
typedef struct Node *address;
struct Node {
    infotype info;
    address left, right;
};

// deklarasikan fungsi-fungsi atau prosedur primitif
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

// === SOAL NO 2 ===
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

// === SOAL NO 3 ===
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);


#endif