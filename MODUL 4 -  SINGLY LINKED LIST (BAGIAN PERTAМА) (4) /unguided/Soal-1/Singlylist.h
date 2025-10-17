#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List {
    address first;
};

// prosedur and function
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);


#endif