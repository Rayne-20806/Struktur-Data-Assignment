#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX -1;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t: ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl; 
    } else {
        // Logika Print yang Universal (Linear & Circular)
        
        // Kasus 1: Linear (Head <= Tail)
        if (Q.head <= Q.tail) {
            // PERBAIKAN DI SINI: i <= Q.tail (bukan Q.head)
            for (int i = Q.head; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        } 
        // Kasus 2: Circular (Head > Tail)
        else {
            // Cetak dari Head sampai ujung array (MAX)
            for (int i = Q.head; i < MAX; i++) {
                cout << Q.info[i] << " ";
            }
            // Lanjut cetak dari awal array (0) sampai Tail
            for (int i = 0; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
        cout << endl;
    }
}

// soal 1
// Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
void enqueue1(Queue &Q, infotype x) {
    if (isFullQueue(Q) == true) {
        cout << "Queuenya penuh!" << endl;
    } else {
        // kondisi jika queue kosong atau tidak ada;
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else { //  jika isi queue ada minimal 1
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}
int dequeue1(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
    } else {
        val = Q.info[Q.head]; //ambil data di head (pasti selalu 0)

        // kondisi jika 1 elemen
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            // geser elemen agar maju
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i+1];
            }
            Q.tail--; //tail mundur
        }
    }
    return val;
}

// Soal 2: Alternatif 2 head dan tail bergerak
void enqueue2(Queue &Q, infotype x) {
    // Sama persis dengan enqueue1 (Cuma beda di dequeue)
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh (atau Penuh Semu)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}
int dequeue2(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
    } else {
        val = Q.info[Q.head];
        
        // Kondisi jika tinggal 1 elemen
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            // HEAD MAJU (Tanpa Geser)
            Q.head++; 
        }
    }
    return val;
}

// Soal 3: Alternatif 3 head dan tail berputar (Circular)
// fungsi tambahan
bool isFullCircular(Queue Q) {
    // Penuh jika:
    // 1. Head di 0 dan Tail di MAX-1 (Normal Penuh)
    // 2. Tail persis di belakang Head (Circular Penuh)
    return ((Q.head == 0 && Q.tail == MAX - 1) || (Q.tail == Q.head - 1));
}
void enqueue3(Queue &Q, infotype x) {
    if (isFullCircular(Q)) {
        cout << "Antrean Circular Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            // Rumus Circular untuk Tail adalah (Tail + 1) % MAX
            // Jika Tail di MAX-1 akan jadi 0.
            if (Q.tail == MAX - 1) {
                Q.tail = 0;
            } else {
                Q.tail++;
            }
            Q.info[Q.tail] = x;
        }
    }
}
int dequeue3(Queue &Q) {
    infotype val = -1;
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
    } else {
        val = Q.info[Q.head];
        
        // kondisi jika tinggal 1 elemen
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            // Rumus Circular untuk Head
            // Jika Head di MAX-1, dia akan jadi 0.
            if (Q.head == MAX - 1) {
                Q.head = 0;
            } else {
                Q.head++;
            }
        }
    }
    return val;
}