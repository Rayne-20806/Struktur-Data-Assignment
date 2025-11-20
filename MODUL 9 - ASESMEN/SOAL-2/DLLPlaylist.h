#ifndef DLLPlaylist_H
#define DLLPlaylist_H

#include <iostream>
#include <string>
using namespace std;
#define nil NULL

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};
typedef struct Node *address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};


//deklarasikan fungsi dan procedure primitif
bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address &P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

// Fungsi Update & View
void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);
void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

#endif

