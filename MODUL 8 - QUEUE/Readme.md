# <h1 align="center">Laporan Praktikum Modul QUEUE (8)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### QUEUE Representasi dengan List
Dibaca kyu, merupakan struktur data yang dapat dikatakan seperti sebuah antrean. Misalkan antrean pada loket pembelian tiket kereta api. Orang yang akan mendapatkan pelayanan yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian struktur Queue dalam C dapat menggunakan tipe data array dan linked list.

Berikut contoh gambar struktur Queue dalam Linked List

<img width="795" height="291" alt="image" src="https://github.com/user-attachments/assets/2260c0a9-3dd2-49c1-a5c8-104529c58296" />

Operasi Queue memiliki dua operasi utama yaitu operasi penyisipan (Insert/Enqueue) dan operasi pengambilan (Delete/Dequeue).
<ol>
  <li>
    Insert(Enqueue), Operasi penyisipan dilakukan pada akhir(tail), ya ini seperti insertLast kalau di Linked List
  </li>
  
  <img width="838" height="229" alt="image" src="https://github.com/user-attachments/assets/ba712241-dece-4683-adba-5388b88b2630" />

  <li>
    Delete(Dequeue), operasi delete dilakukan pada awal(head), ini seperti deleteFirst, karena di queue delete atau mengambil akan lebih memilih elemen yang ditunjuk oleh head(FIFO Atau First In Last Out).
  </li>

  <img width="849" height="176" alt="image" src="https://github.com/user-attachments/assets/3da847a8-d2dc-45dd-8179-49b809d2b9c8" />
  
</ol>

### QUEUE Representasi Tabel
Pada dasarnya representasi queue menggunakan tabel sama halnya dengan menggunakan pointer. Perbedaan yang mendasar adalah pada management memori serta keterbatasan jumlah antreannya. Berikut perbedaan antara tabel dan pointer :

<img width="785" height="117" alt="image" src="https://github.com/user-attachments/assets/a7b843be-2bae-403e-8419-044629aeccbc" />

<img width="911" height="432" alt="image" src="https://github.com/user-attachments/assets/323c33d5-8825-4028-ba0b-7c3b3dfd0a3e" />





## Guided 


## 1. QUEUE Versi Linked List
## 1.1 queue.h
```h
// guided 1 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

## 1.2 queue.cpp
```cpp
// guided 1 queue.cpp
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```


## 1.3 main.cpp
```cpp
// guided 1 main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}



```

Program guided 1 mengimplementasikan QUEUE menggunakan pendekatan linked list yang dimana sifatnya itu dinamis, berbeda dengan array karena tidak memiliki batasan ukuran elemen (isFull selalu false). Dalam file queue.h, didefinisikan struct Node yang menyimpan data nama bertipe string serta pointer next, dan struct queue yang menyimpan pointer head dan tail untuk melacak ujung antrean. Logika operasi di queue.cpp menerapkan prinsip FIFO (First In First Out): fungsi enQueue menambahkan node baru pada posisi tail (belakang), sedangkan deQueue menghapus node dari posisi head (depan). Pada main.cpp, program mendemonstrasikan alur kerja dengan memasukkan 6 nama ke antrean, lalu menghapus 4 nama pertama, dan diakhiri dengan pengosongan antrean melalui clearQueue.


## 2. Queue Versi Array(tabel)
## 2.1 queue.h
```h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

## 2.2 queue.cpp
```cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}

```


## 2.3 main.cpp
```cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

```
Program Guided 2 ini merupakan implementasi struktur data Queue menggunakan pendekatan Array, yang berbeda dengan pendekatan Linked List pada Guided 1. Program ini unik karena menyediakan tiga alternatif implementasi untuk mekanisme antrean dalam satu file kode, meskipun dalam eksekusinya, hanya satu alternatif yang aktif (yang tidak dikomentari). Alternatif 1 menerapkan Queue Linear Statis, di mana pointer head tetap diam di indeks 0 dan elemen digeser maju setiap kali ada penghapusan (dequeue). Alternatif 2 menggunakan Queue Linear Dinamis, di mana head dan tail sama-sama bergerak maju seiring penambahan dan penghapusan elemen, tanpa pergeseran data, namun memiliki risiko pemborosan ruang di awal array. Alternatif 3, yang aktif dalam kode yang diberikan, adalah Queue Circular, di mana head dan tail bergerak melingkar menggunakan operasi modulus (%), memungkinkan pemanfaatan kembali ruang kosong di awal array secara efisien.
Secara struktur, program terdiri dari tiga file. File queue.h mendefinisikan ADT Queue yang berisi array nama berkapasitas 5 (MAKSIMAL), serta pointer head dan tail. File queue.cpp berisi logika operasi primitif seperti enQueue (menambah data) dan deQueue (menghapus data). Pada implementasi Circular yang aktif, fungsi isFull mengecek kepenuhan dengan logika (tail + 1) % MAKSIMAL == head, dan viewQueue menggunakan loop while dengan increment modulus untuk mencetak isi antrean secara berurutan. File main.cpp bertindak sebagai penguji dengan membuat antrean, memasukkan 6 nama (dhimas hingga Atha) di mana nama terakhir ("Atha") akan ditolak karena kapasitas penuh (5), menampilkan isi antrean, lalu melakukan penghapusan 4 elemen, dan menampilkan sisa antrean.



## Unguided 

### 1. Soal Pertama, kedua, dan ketiga di gabung
<img width="817" height="787" alt="image" src="https://github.com/user-attachments/assets/7d533c85-63a4-4103-af32-6c6282e7e1e5" />


### 1.1 queue.h
```h
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
```

### 1.2 queue.cpp
```cpp
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
```

### 1.3 main.cpp
```cpp
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

```

Program ini dibuat dengan mengimplementasikan QUEUE Array atau tabel dengan ADT, seperti biasa buat 3 file dalam satu folder terlebih dahulu dan kerjakan sesuai dengan ketentuan soal yang ada.
atihan 1 menerapkan mekanisme Queue Linear dengan Pergeseran (Alternatif 1), di mana Head selalu dipertahankan pada indeks 0; saat dequeue terjadi, seluruh elemen di belakang digeser maju satu posisi, yang menjaga kerapian namun kurang efisien secara komputasi. Latihan 2 menggunakan mekanisme Queue Linear Dinamis (Alternatif 2), di mana Head bergerak maju (Head++) saat penghapusan data tanpa pergeseran elemen, yang mempercepat proses namun menyisakan ruang memori tak terpakai di awal array (false full). Latihan 3 menerapkan mekanisme Circular Queue (Alternatif 3), solusi paling optimal di mana indeks Head dan Tail berputar kembali ke awal (menggunakan modulus) saat mencapai batas maksimum array, memanfaatkan ruang kosong secara efisien.

Program penguji (main.cpp) dibuat untuk menjalankan skenario urutan operasi yang sama persis untuk ketiga alternatif tersebut (Enqueue 5, 2, 7 -> Dequeue 2x -> Enqueue 4 -> Dequeue 2x), menghasilkan output tabel indeks Head - Tail dan isi data yang sesuai dengan referensi pada modul (Gambar 8-17), membuktikan bahwa ketiga logika tersebut berjalan dengan benar sesuai karakteristik masing-masing.




#### Output:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/4d6bbc1f-7e1d-466f-b6b9-d5b5c303f3e3" />



#### Full code screenshot:

#### Code queue.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f31e5b90-b9bc-4eb2-96b6-593160243f96" />

#### code queue.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/98cd6c2b-92e5-4db1-9a34-4e26440d9a8a" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f57f8391-f955-4f3a-93e4-22b39bfb7bbb" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/824e2c5f-e1b1-4120-8e86-9450efab5484" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b0916353-a3c3-4cf5-822d-55d0fd420a2a" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ad7a4933-5ac3-4a18-bd31-c84b79927c8b" />

#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/97ba341c-a3c2-4d00-903f-b5778fa4bb90" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/830ee4db-a530-441d-b1ba-681b77f4bf01" />














## Kesimpulan
Berdasarkan praktikum kali ini, Saya mempelajari bagaimana cara mengimplementasikan sebuah Queue dalam bentuk linked list ataupun array(tabel). Queue menganut prinsip FIFO(First in First Out) yang dimana first ditunjuk oleh head dan akhir berada ditail. Untuk implementasi Queue menggunakan representasi tabel (Array) ada 3 pendekatan yaitu:
<ol>
  <li>
    inear dengan Pergeseran (Shift): Memastikan Head selalu di awal, namun tidak efisien untuk data besar karena proses pergeseran saat dequeue
  </li>
<li>
  Linear Tanpa Pergeseran: Lebih cepat, namun menyisakan ruang memori yang tidak terpakai di depan antrean (wasted space) sehingga kapasitas array cepat penuh semu.
</li>
  <li>
    Circular Buffer: Solusi paling efisien untuk implementasi Queue berbasis array, karena memungkinkan penggunaan kembali (reuse) indeks memori yang sudah kosong secara memutar, memaksimalkan kapasitas array yang tersedia.
  </li>
</ol>



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.











