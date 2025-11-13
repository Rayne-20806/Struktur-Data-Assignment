#ifndef STACK
#define STACK
#define nil NULL

#include <iostream>
#include <string>
using namespace std;


const int MAX_SLOTS = 20; //max kapasitas tas atau lebih tepat array
struct Item {
    string nama; 
    int id;
};
typedef Item infotype; // infotype sekarang adalah struct dari item
struct Stack {
    infotype info[MAX_SLOTS]; // array berisi 20 jumlahnya
    int top; //tumpukan atas atau top
};

// buat fungsi atau prosedur primitif sesuai soal yang ada
void CreateStack(Stack &S); 
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// tambah bagian ini opsional namun penting
bool isEmpty(Stack S);
bool isFull(Stack S);
infotype createItem(string nama, int id);

//ini untuk soal no 2
void pushAscending(Stack &S, infotype x);

// tambahan baru untuk soal no 3
void getInputStream(Stack &S);

#endif