#include "bstree.h"
using namespace std;

int main() {
    // // === SOAL NO 1 ===
    // cout << "Hello World" << endl;
    // // digunakan untuk proses insert node ke BST
    // address root = Nil;
    // insertNode(root,1);
    // insertNode(root,2);
    // insertNode(root,6);
    // insertNode(root,4);
    // insertNode(root,5);
    // insertNode(root,3);
    // insertNode(root,6);// duplikat jadi tidak dimasukkan
    // insertNode(root,7);
    // // cetak isi atau menampilkan isi tree secara Inorder
    // printInorder(root);

    // cout << endl;

    // // === SOAL NO 2 ===
    // cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    // cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    // cout<<"total : "<<hitungTotalInfo(root, 0)<<endl;

    // === SOAL NO 3 ===
    address root = Nil;
    // root node
    insertNode(root, 6);
    // level 1, left and right
    insertNode(root, 4);
    insertNode(root, 7);
    // level 2, dibawah 4, left and right
    insertNode(root, 2);
    insertNode(root,5);
    // level 3, dibawah 2, left and right
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "\nTree telah dibuat sesuai dengan gambar soal"<< endl;

    // 1. PreOrder (MIDDLE, LEFT, RIGHT Cara bacanya)
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;

    // 2. InOrder (LEFT, MIDDLE, RIGHT Cara bacanya)
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;

    // 3. PostOrder (LEFT, RIGHT, MIDDLE Cara bacanya)
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;


    return 0;
}