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