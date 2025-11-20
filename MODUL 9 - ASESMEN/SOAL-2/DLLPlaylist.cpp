#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

//Penerapan semua implementasi fungsi dan prosedur.

// Cek list kosong
bool isEmpty(List L) {
    return (L.head == nil && L.tail == nil);
}

// Buat list kosong
void createList(List &L) {
    L.head = nil;
    L.tail = nil;
}

// Alokasi node baru
address allocate(Song S) {
    address newNode = new Node;
    newNode->info = S;
    newNode->prev = nil;
    newNode->next = nil;
    return newNode;
}

// Dealokasi memori
void deallocate(address &P) {
    delete P;
}

// Insert First
void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

// Insert Last
void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        insertFirst(L, S);
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

// Insert After
void insertAfter(List &L, address Q, Song S) {
    if (Q != nil) {
        address P = allocate(S);
        if (Q == L.tail) {
            insertLast(L, S);
        } else {
            P->next = Q->next;
            P->prev = Q;
            Q->next->prev = P;
            Q->next = P;
        }
    }
}

// Insert Before
void insertBefore(List &L, address Q, Song S) {
    if (Q != nil) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;
            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

// Delete First
void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;
        if (L.head == L.tail) {
            L.head = nil;
            L.tail = nil;
        } else {
            L.head = L.head->next;
            L.head->prev = nil;
        }
        deallocate(P);
    }
}

// Delete Last
void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;
        if (L.head == L.tail) {
            deleteFirst(L, S);
        } else {
            L.tail = L.tail->prev;
            L.tail->next = nil;
            deallocate(P);
        }
    }
}

// Delete After
void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nil && Q->next != nil) {
        address P = Q->next;
        S = P->info;
        if (P == L.tail) {
            deleteLast(L, S);
        } else {
            Q->next = P->next;
            P->next->prev = Q;
            deallocate(P);
        }
    }
}

// Delete Before
void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nil && Q->prev != nil) {
        address P = Q->prev;
        S = P->info;
        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            Q->prev = P->prev;
            P->prev->next = Q;
            deallocate(P);
        }
    }
}

// Update data pada posisi tertentu (Input User)
void updateAtPosition(List &L, int posisi) {
    address P = L.head; int i = 1;
    while (P != nil && i < posisi) {
        P = P->next;
        i++;
    }

    if (P != nil) {
        cout << "\nUpdate Data Posisi " << posisi << endl;
        cout << "Title Baru       : "; 
        cin.ignore(); 
        getline(cin, P->info.Title);
        cout << "Artist Baru      : "; 
        getline(cin, P->info.Artist);
        cout << "Duration (sec)   : "; cin >> P->info.DurationSec;
        cout << "PlayCount Baru   : "; cin >> P->info.PlayCount;
        cout << "Rating Baru      : "; cin >> P->info.Rating;
        cout << "Data berhasil diupdate" << endl;
    } else {
        cout << "Posisi tidak ditemukan" << endl;
    }
}

// Update data node SEBELUM Q
void updateBefore(List &L, address Q) {
    if (Q != nil && Q->prev != nil) {
        address P = Q->prev;
        cout << "\nUpdate Data SEBELUM Node Terpilih" << endl;
        cout << "Title Baru       : "; 
        cin.ignore(); 
        getline(cin, P->info.Title);
        cout << "Artist Baru      : "; 
        getline(cin, P->info.Artist);
        cout << "Duration (sec)   : "; cin >> P->info.DurationSec;
        cout << "PlayCount Baru   : "; cin >> P->info.PlayCount;
        cout << "Rating Baru      : "; cin >> P->info.Rating;
        cout << "Data berhasil diupdate" << endl;
    } else {
        cout << "Tidak ada node sebelum node ini!" << endl;
    }
}

// Menampilkan List + Popularity Score
void viewList(List L) {
    cout << "\nPLAYLIST" << endl;
    if (isEmpty(L)) {
        cout << "Playlist Kosong." << endl;
    } else {
        address P = L.head;
        int i = 1;
        while (P != nil) {
            // Rumus Turunan (Wajib digunakan untuk output & searching) PopularityScore = 0.8 * PlayCount + 20.0 * Rating
            float popularity = 0.8 * P->info.PlayCount + 20.0 * P->info.Rating;

            cout << i << ". " << P->info.Title << " - " << P->info.Artist << endl;
            cout << "   Duration: " << P->info.DurationSec << "s | Plays: " << P->info.PlayCount 
                 << " | Rating: " << P->info.Rating << endl;
            cout << "   Popularity Score: " << popularity << endl;
            P = P->next;
            i++;
        }
    }
    cout << endl;
}

// Searching berdasarkan range Popularity Score
void searchByPopularityRange(List L, float minScore, float maxScore) {
    cout << "\nSEARCH RESULT (Popularity: " << minScore << " - " << maxScore << ")" << endl;
    address P = L.head;
    int i = 1;
    bool found = false;
    while (P != NULL) {
        float popularity = 0.8 * P->info.PlayCount + 20.0 * P->info.Rating;
        if (popularity >= minScore && popularity <= maxScore) {
            cout << "Posisi " << i << ": " << P->info.Title << " (Score: " << popularity << ")" << endl;
            found = true;
        }
        P = P->next;
        i++;
    }
    if (!found) cout << "Tidak ada lagu dalam range tersebut" << endl;
}

