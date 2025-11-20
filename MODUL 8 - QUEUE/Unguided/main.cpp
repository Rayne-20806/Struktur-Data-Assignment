#include "queue.h"
#include <iostream>
using namespace std;

// Fungsi helper agar main rapi dan bisa dipakai utk 3 soal
void runTest(int type) {
    Queue Q;
    CreateQueue(Q);

    cout << "--------------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "--------------------------------" << endl;

    // 1. Awal Kosong
    printInfo(Q);

    // 2. Enqueue 5
    if(type==1) enqueue1(Q, 5); else if(type==2) enqueue2(Q, 5); else enqueue3(Q, 5);
    printInfo(Q);

    // 3. Enqueue 2
    if(type==1) enqueue1(Q, 2); else if(type==2) enqueue2(Q, 2); else enqueue3(Q, 2);
    printInfo(Q);

    // 4. Enqueue 7
    if(type==1) enqueue1(Q, 7); else if(type==2) enqueue2(Q, 7); else enqueue3(Q, 7);
    printInfo(Q);

    // 5. Dequeue (Hapus 5)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 6. Dequeue (Hapus 2)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 7. Enqueue 4
    if(type==1) enqueue1(Q, 4); else if(type==2) enqueue2(Q, 4); else enqueue3(Q, 4);
    printInfo(Q);

    // 8. Dequeue (Hapus 7)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 9. Dequeue (Hapus 4 -> Kosong)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);
}

int main() {
    cout << "Hello world!" << endl;

    cout << "\n=== SOAL 1 (ALTERNATIF 1: GESER) ===" << endl;
    runTest(1); // Ini yang akan PERSIS gambar 8-17

    cout << "\n=== SOAL 2 (ALTERNATIF 2: HEAD MAJU) ===" << endl;
    runTest(2); // Head akan terus bertambah

    cout << "\n=== SOAL 3 (ALTERNATIF 3: CIRCULAR) ===" << endl;
    runTest(3);

    return 0;
}