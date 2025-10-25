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