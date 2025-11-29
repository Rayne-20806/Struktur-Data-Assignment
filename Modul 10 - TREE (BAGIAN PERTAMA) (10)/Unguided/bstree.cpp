#include "bstree.h"
using namespace std;

// === SOAL NO 1===
address alokasi(infotype x) {
    address P = new Node;
    P -> info = x;
    P -> left = Nil;
    P -> right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    //jika tree kosong
    if  (root == Nil) {
        root = alokasi(x);
    } else {
        // jika tidak kosong, maka bandingkan nilai x
        if (x < root -> info) {
            insertNode(root -> left, x); // masuk ke subtree kiri
        } else if (x > root -> info) {
            insertNode(root -> right, x); // masuk ke subtree kanan
        }
        // jika x == root -> info maka idak lakukan apa-apa karena tidak ada duplikasi
    }
}

// ini rekursif untuk mencari node dengan nilai x
address findNode(infotype x, address root) {
    // jika tree kosong
    if (root == Nil) {
        return Nil;
    } 
    if (root -> info == x) {
        return root; //ketemu node dengan nilai x di root
    }
    // jika tidak ketemu, coba cari di kiri dan kanan
    if (x < root -> info) {
        return findNode(x, root -> left); // cari di bagian kiri
    } else {
        return findNode(x, root -> right); // cari dibagian kanan
    }
}

//cetak isi InOrder
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root -> left);
        cout << root -> info << " - ";
        printInorder(root -> right);
    }
}


// === SOAL NO 2 === 
int hitungJumlahNode(address root) {
    // jika tree kosong
    if (root == Nil) {
        return 0; 
    } 
    return 1 + hitungJumlahNode(root ->left) + hitungJumlahNode(root -> right);
}

int hitungTotalInfo(address root, int start) {
    // jika tree kosong
    if (root == Nil ) {
        return start; 
    }
    return  root -> info + hitungTotalInfo(root->left, 0) + hitungTotalInfo(root->right, 0);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start; 
    }
    // Cari kedalaman maksimal antara kiri dan kanan
    // start + 1 artinya turun satu level
    int kedalamanKiri = hitungKedalaman(root->left, start + 1);
    int kedalamanKanan = hitungKedalaman(root->right, start + 1);

    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}

// === SOAL NO 3 ===
void preOrder(address root) {
    if(root != Nil) {
        cout << root -> info << " - ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void inOrder(address root) {
    if (root != Nil) {
        inOrder(root -> left);
        cout << root -> info << " - ";
        inOrder(root -> right);
    }
}

void postOrder(address root) {
    if (root != Nil) {
        postOrder(root -> left);
        postOrder(root -> right);
        cout << root -> info << " - ";    }
}