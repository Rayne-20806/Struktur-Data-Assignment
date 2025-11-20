#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

// Definisika ADT pada Queue array
typedef int infotype;
const int MAX = 5;
struct Queue {
    infotype info[MAX];
    int head, tail;
};

// deklaraasi fungsi atau procedur primitif
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void printInfo(Queue Q);

// soal 1
// Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
void enqueue1(Queue &Q, infotype x);
int dequeue1(Queue &Q);

// Soal 2: Alternatif 2 head dan tail bergerak
void enqueue2(Queue &Q, infotype x);
int dequeue2(Queue &Q);

// Soal 3: Alternatif 3 head dan tail berputar (Circular)
bool isFullCircular(Queue Q);
void enqueue3(Queue &Q, infotype x);
int dequeue3(Queue &Q);


#endif