<h1 align="center">Laporan Praktikum Modul GRAPH (14)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
### Pengertian Graph
Graph merupakan hompunan yang tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda dan Common Lab merupakan node atau vertec. Jalan yang menghubungkan kedua node tersebut disebut sebagai edge, berikut contoh gambarnya agar jelas.

<img width="365" height="111" alt="image" src="https://github.com/user-attachments/assets/84b0cf19-a015-4d6a-b78f-e8175f05526e" />

### Jenis-Jenis Graph
Graph memiliki berbagai jenis seperti berikut ini:
### 1.  Graph Berarah (Directed Graph).
Merupakan graph dimana tiap node memiliki edge atau garis penghubung yang ada arahnya, dimana setiap node akan mengarah ke node yang dihubungkan.

<img width="429" height="140" alt="image" src="https://github.com/user-attachments/assets/f52be011-43a8-4cf7-aa3e-2d5b3c4c53d8" />

#### A. Representasi Graph
Pada dasarnya representasi dari graph berarah sama dengan graph tak berarah. Perbedaannya apabila graph tak-berarah terdapat node A dan node B yang terhubung, secara otomatis terbentuk panah bolak balik dari A ke B dan B ke A. Pada graph berarah node A terhubung dengan node B, belum tentu node B terhubung dengan node A. Pada graph berarah kita bisa merepresentasikan dalam multi linked list sebagai contoh berikut ini,

<img width="646" height="293" alt="image" src="https://github.com/user-attachments/assets/6086d651-6932-4055-a90f-36b88828e4c4" />

<img width="646" height="243" alt="image" src="https://github.com/user-attachments/assets/e44951c1-8582-4a52-a734-8e8ca5aaa04a" />

#### B. Topological Sort
Diberikan urutan partial dari elemen suatu himpunan, dikehendaki agar elemen yang terurut parsial tersebut mempunyai keterurutan linear. Contoh dari keturunan parsial banyak dijumpai dalam kehidupan sehari-hari, misalnya: 
<ol>
  <li>
    Dalam suatu kurikulum, suatu mata pelajaran mempunyai prerequisite mata pelajaran lain.
Urutan linear adalah urutan untuk seluruh mata pelajaran dalam kurikulum
  </li>
  <li>
     Dalam suatu proyek, suatu pekerjaan harus dikerjakan lebih dulu dari pekerjaan lain (misalnya
membuat fondasi harus sebelum dinding, membuat dinding harus sebelum pintu. Namun
pintu dapat dikerjakan bersamaan dengan jendela, dsb.
  </li>
  <li>
     Dalam sebuah program Pascal, pemanggilan prosedur harus sedemikian rupa, sehingga
peletakan prosedur pada teks program harus seuai dengan urutan (partial) pemanggilan.
  </li>
</ol>

<img width="588" height="424" alt="image" src="https://github.com/user-attachments/assets/f3f07b04-7db6-46f5-9c7a-6b14dd09ebf6" />

### Graph Tidak Berarah (Undirected Graph)
Merupakan graph yang dimana setiap node memiliki edge yang dihubungkan ke node lain tanpa adanya arah atau tanda panah, berikut contohnya.

<img width="353" height="95" alt="image" src="https://github.com/user-attachments/assets/2c55564d-6b98-4016-ba2f-8181cb299c30" />

Selain arah, beban atau nilai sering ditambahkan pada edge . Misalnya nilai yang merepresentasikan
panjang, atau biaya transportasi, dan lain-lain. Hal mendasar lain yang perlu diketahui adalah, suatu
node A dikatakan bertetangga dengan node B jika antara node A dan node B dihubungkan langsung
dengan sebuah edge.

Dari gambar contoh graph pada halaman sebelumnya dapat disimpulkan bahwa: A bertetangga
dengan B, B bertetangga dengan C, A tidak bertetangga dengan C, B tidak bertetangga dengan D.
Masalah ketetanggaan suatu node dengan node yang lain harus benar-benar
diperhatikan dalam implementasi pada program. Ketetanggaan dapat diartikan sebagai
keterhubungan antar node yang nantinya informasi ini dibutuhkan untuk melakukan beberapa proses
STRUKTUR DATA 107
seperti : mencari lintasan terpendek dari suatu node ke node yang lain, pengubahan graph menjadi
tree (untuk perancangan jaringan) dan lain-lain.

#### Representasi Graph.
Dari definisi graph dapat disimpulkan bahwa graph dapat direpresentasikan dengan matrik ketetanggaan (Adjacency Matrices), yaitu matrik yang menyatakan keterhubungan antar node dalam graph. Implementasi matrik ketetanggaan dalam bahasa pemrograman dapat berupa array 2 dimensi dan multi linked list.

<img width="629" height="179" alt="image" src="https://github.com/user-attachments/assets/03641b3c-38d7-47c5-80f3-dc4a88da29d7" />

<img width="629" height="327" alt="image" src="https://github.com/user-attachments/assets/c6544455-6203-4543-84ec-869de2c711ba" />

#### Metode Penelusuran Graph
Yang pertama ada Breadth First Search (BFS), cara kerja algoritma ini adalah dengan mengunjungi root (depth 0) kemudian ke depth 1, 2, dan seterusnya. Kunjungan pada masing-masing level dimulai dari kiri ke kanan. Selanjutnya ada Depth First Search (DFS), cara kerja algoritma ini adalah dengan mengunjungi root, kemudian rekursid ke subtree node tersebut.


  



## Guided 


## 1. GRAPH

## 1.1 graph.h
```h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

// ----- DEFINISI TYPE DATA DAN STRUCTURE -----

// tipe data info untuk node graph seperti a, b, c,
typedef char infoGraph;

// Pointer untuk node dan edge
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;       // Menyimpan data node (misal: char/int)
    bool visited;        // Penanda untuk traversal (BFS/DFS), apakah node sudah dikunjungi?
    adrEdge firstEdge;   // Pointer ke edge pertama (adjacency list)
    adrNode Next;        // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  // Pointer yang menuju ke node tujuan
    adrEdge Next;        // Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;       // Pointer ke node pertama dalam list graph
};

// ----- PROTOTYPE FUNGSI DAN PROSEDUR GRAF -----

void CreateGraph(Graph &G);                                   // Prosedur untuk mengeset first dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);                              // Alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);                         // Alokasi edge baru

void InsertNode(Graph &G, infoGraph data);                        // Menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);                        // Mencari node berdasarkan info-nya

void ConnectNode(Graph &G, infoGraph infoAwal, infoGraph infoAkhir);  // Menyambungkan dua node (Edge) → Undirected Graph
void DisconnectNode(Graph &G, infoGraph infoAwal, infoGraph infoAkhir); // Memutuskan hubungan dua node

void DeleteNode(Graph &G, infoGraph data);                        // Menghapus node dan semua edge yang menunjuk ke node tersebut

void PrintInfoGraph(Graph G);                                    // Menampilkan isi graph (Adjacency List)
void ResetVisited(Graph &G);                                     // Reset status visited sebelum traversal

void PrintBFS(Graph G, infoGraph startInfo);                      // Traversal Breadth First Search (Queue)
void PrintDFS(Graph G, infoGraph startInfo);                      // Traversal Depth First Search (Stack)

#endif

```

## 1.2 graph.cpp
```cpp
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```


## 1.3 main.cpp
```cpp
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```
Program ini merupakan guided yang diajari langsung oleh asisten praktikum struktur data. Ini merupakan implementasi graph dalam struktur data yang dimana seperti biasa kita menggunakan 3 file karena ADT.
<ol>
  <li>
    File <code>graph.h</code>. File ini mendefinisikan ADT Graph yang menggunakan Adjacency List atau Multi Linked List. Struktur data ini terdiri dari dua elemen utama yaitu ElmNode sebagai simpul atau vertex dan ElmEdge sebagai garis atau edger. Setiap ElmNode memiliki pointer firstEdge yang menunjuk ke daftar tetangganya, ini memungkinkan representasi graf yang lebih dinamis dan hemat memori dibandingkan dengan matriks array. Selain itu juga kita mendeklarasikan beberapa fungsi ataupun prosedur primitif yang nantinya akan digunakan di file graph.cpp
  </li>
  <li>
    File <code>graph.cpp</code>. File ii berisi semua implementasi dari berbagai fungsi atau prosedur untuk graf. 
    Manajemen Graf: Fungsi CreateGraph, InsertNode, dan ConnectNode digunakan untuk membangun struktur graf. ConnectNode secara otomatis membuat hubungan dua arah (undirected) dengan menambahkan edge pada kedua node yang terhubung. 
    Operasi Penghapusan (DeleteNode): Algoritma ini bekerja dalam tiga tahap: (1) Menghapus semua edge dari node lain yang mengarah ke node target (DisconnectNode), (2) Menghapus semua edge yang keluar dari node target, dan (3) Menghapus node target itu sendiri dari daftar vertex.
    Traversal: Implementasi algoritma BFS (Breadth First Search) menggunakan Queue untuk penelusuran melebar per level, dan DFS (Depth First Search) menggunakan Stack untuk penelusuran mendalam.
  </li>
  <li>
    File <code>main.cpp</code>. File ini digunakan untuk menguji keseluruhan program yang ada.
  </li>
</ol>



## Unguided 


### 1. Soal Pertama, Buat ADT Graph yang tidak berarah
<img width="799" height="707" alt="image" src="https://github.com/user-attachments/assets/5f7a22c9-c3b1-4f26-8824-8c073708e014" />



### 1.1 graph1.h
```h
#ifndef GRAPH1_H
#define GRAPH1_H
#include <iostream>
using namespace std;
#define nil NULL

// SOAL NO 1

// Tipe data untuk info node
typedef char infotype;

// pointer ke node dan edge
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infotype info; // Nama node
    int visited; // Status kunjungan (0/1) buat traversal
    adrEdge firstEdge; // Pointer ke edge pertama
    adrNode nextNode; // Pointer ke node berikutnya dalam list graph
};

struct ElmEdge {
    adrNode Node; // Menunjuk ke node tujuan
    adrEdge nextEdge; // Pointer ke edge berikutnya
};

struct Graph {
    adrNode First; // awal dari list graph
};

// -- Fungsi atau prosedur prototipe -- //

// buat graph kosong
void createGraph(Graph &G);
adrNode alokasiNode(infotype x); // Tambahan helper
adrEdge alokasiEdge(adrNode tujuan); // Tambahan helper

// tambah node baru
void InsertNode(Graph &G, infotype x);

// menghubungkan dua node dengan edge
void ConnectNode(Graph &G, infotype N1, infotype N2);

// cari node berdasarkan info
adrNode FindNode(Graph G, infotype x);

// menampilkan graph format adjacency list
void PrintInfoGraph(Graph G);

#endif
```

### 1.2 graph1.cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

// SOAL NO 1

void createGraph(Graph &G) {
    // inisialisasi graph kosong
    G.First = nil;
}

// alokasi node baru
adrNode alokasiNode(infotype x) {
    adrNode P = new ElmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = nil;
    P -> nextNode = nil;
    return P;
}

// alokasi edge baru 
adrEdge alokasiEdge(adrNode tujuan) {
    adrEdge P = new ElmEdge;
    P -> Node = tujuan;
    P -> nextEdge = nil;
    return P;
}

// cari node berdasarkan info 
adrNode FindNode(Graph G, infotype x) {
    adrNode P = G.First;
    while (P != nil) {
        if (P -> info == x) {
            return P;
        }   
        P = P -> nextNode; 
    }
    return nil;
}

//menambahkan node baru dalam graph
void InsertNode (Graph &G, infotype x) {
    // jika graph kosong
    adrNode P = alokasiNode(x);
    if (G.First == nil) {
        G.First = P;
    }else {
        // Insert di akhir list node
        adrNode last = G.First;
        while (last->nextNode != nil) {
            last = last->nextNode;
        }
        last->nextNode = P;
    }
}

// menghubungkan dua node N1 dan N2 
void ConnectNode(Graph &G, infotype N1, infotype N2) {
    adrNode P1 = FindNode(G, N1);
    adrNode P2 = FindNode(G, N2);

    if (P1 != nil && P2 != nil) {
        // 1. Hubungkan P1 -> P2
        adrEdge E1 = alokasiEdge(P2);
        E1->nextEdge = P1->firstEdge; // Insert First di list edge
        P1->firstEdge = E1;

        // 2. Hubungkan P2 -> P1 (Karena Undirected)
        adrEdge E2 = alokasiEdge(P1);
        E2->nextEdge = P2->firstEdge; // Insert First di list edge
        P2->firstEdge = E2;
    } else {
        cout << "Salah satu node tidak ditemukan!" << endl;
    }
}

// Menampilkan Graph (Adjacency List)
void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != nil) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != nil) {
            cout << " -> " << E->Node->info;
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}
```

### 1.3 main.cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

int main() {
    // --- soal no 1
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // 2. Connect Node (Sesuai Gambar 14-14)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H'); // Di gambar G ke H juga terhubung

    // 3. Tampilkan Graph
    cout << "=== ISI GRAPH (ADJACENCY LIST) ===" << endl;
    PrintInfoGraph(G);

    return 0;
}
```


#### Output:
<img width="1642" height="352" alt="image" src="https://github.com/user-attachments/assets/37cb4a66-b365-4a5d-bf15-343a7563a292" />

Program  diatas kita disuruh untuk membuat ADT Graph tidak berarah.
<ol>
  <li>
    File <code>graph1.h</code>. File ini mendefinisikan ADT  Graph tak berarah. Struktur data menggunakan representasi Adjacency List (Multi Linked List). Terdapat 2 struktur utama yaitu ElmNode yang merepresentasikan simpul atau vertex dengan informasi karakter dan pointer ke edge pertamanya, serta ElmEdge sebagai garis penghubung antar node atau Edge.
  </li>

  <li>
    File <code>graph1.cpp</code>. File ini berisi dari implementasi berbagai fungsi atau prosedur seperti berikut ini.
    <code>InsertNode:</code> Menambahkan node baru ke dalam list graph. Menggunakan metode insert last agar urutan node (A, B, C...) tetap terjaga saat dicetak.
    <code>ConnectNode:</code> Menghubungkan dua node. Karena graf ini tidak berarah (undirected), fungsi ini membuat dua edge sekaligus: dari N1 ke N2, dan dari N2 ke N1. Edge baru ditambahkan di awal list edge (insert first) demi efisiensi.
    <code>PrintInfoGraph:</code> Menelusuri setiap node dalam graph, lalu untuk setiap node, menelusuri list edge-nya untuk menampilkan node mana saja yang bertetangga dengannya.
  </li>

  <li>
    File <code>main.cpp</code>. File ini akan mencoba apakah 2 file yang kita buat berfungsi atau tidak, ini merupakan program utama yang nantinya akan mensimulasikan cara pembentukan graf sesuai soal no 1 yang ada. (contoh: A terhubung ke B dan C, B terhubung ke D dan E, dst hingga semua bermuara di H). Hasil akhirnya adalah representasi Adjacency List yang menunjukkan struktur keterhubungan antar node tersebut.
  </li>
</ol>


#### Full code screenshot:

#### Code graph1.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ce8034b6-419f-4c65-a626-ab2a29b87e2d" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/109b6cd4-8093-46cd-aa44-6f16b269538e" />


#### code graph1.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/74776f4a-d5c3-41cb-9d2d-7837f68ea2ef" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2007a8a6-2e6f-4092-acb1-3d3a6f363e7c" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b8cb73f3-4b7c-453d-967e-4549c9ac34ee" />


#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/7458a236-b047-46ae-bc75-0aa2c75e23b2" />





### 2. Soal dua, Lanjutan dari no 1 namun disuruh membuat Penelusuran DFS
<img width="495" height="31" alt="image" src="https://github.com/user-attachments/assets/a73f5b8c-85ba-4dbb-aaac-e75dca0181cc" />



### 2.1 grap1.h
```h
#ifndef GRAPH1_H
#define GRAPH1_H
#include <iostream>
using namespace std;
#define nil NULL

// SOAL NO 1

// Tipe data untuk info node
typedef char infotype;

// pointer ke node dan edge
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infotype info; // Nama node
    int visited; // Status kunjungan (0/1) buat traversal
    adrEdge firstEdge; // Pointer ke edge pertama
    adrNode nextNode; // Pointer ke node berikutnya dalam list graph
};

struct ElmEdge {
    adrNode Node; // Menunjuk ke node tujuan
    adrEdge nextEdge; // Pointer ke edge berikutnya
};

struct Graph {
    adrNode First; // awal dari list graph
};

// -- Fungsi atau prosedur prototipe -- //

// buat graph kosong
void createGraph(Graph &G);
adrNode alokasiNode(infotype x); // Tambahan helper
adrEdge alokasiEdge(adrNode tujuan); // Tambahan helper

// tambah node baru
void InsertNode(Graph &G, infotype x);

// menghubungkan dua node dengan edge
void ConnectNode(Graph &G, infotype N1, infotype N2);

// cari node berdasarkan info
adrNode FindNode(Graph G, infotype x);

// menampilkan graph format adjacency list
void PrintInfoGraph(Graph G);


// SOAL NO 2: DFS 
// Reset status visited sebelum traversal
void ResetVisited(Graph &G);

// Traversal Depth First Search (DFS)
void PrintDFS(Graph G, adrNode N); // N adalah node awal

#endif
```

### 2.2 graph1.cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

// SOAL NO 1

void createGraph(Graph &G) {
    // inisialisasi graph kosong
    G.First = nil;
}

// alokasi node baru
adrNode alokasiNode(infotype x) {
    adrNode P = new ElmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = nil;
    P -> nextNode = nil;
    return P;
}

// alokasi edge baru 
adrEdge alokasiEdge(adrNode tujuan) {
    adrEdge P = new ElmEdge;
    P -> Node = tujuan;
    P -> nextEdge = nil;
    return P;
}

// cari node berdasarkan info 
adrNode FindNode(Graph G, infotype x) {
    adrNode P = G.First;
    while (P != nil) {
        if (P -> info == x) {
            return P;
        }   
        P = P -> nextNode; 
    }
    return nil;
}

//menambahkan node baru dalam graph
void InsertNode (Graph &G, infotype x) {
    // jika graph kosong
    adrNode P = alokasiNode(x);
    if (G.First == nil) {
        G.First = P;
    }else {
        // Insert di akhir list node
        adrNode last = G.First;
        while (last->nextNode != nil) {
            last = last->nextNode;
        }
        last->nextNode = P;
    }
}

// menghubungkan dua node N1 dan N2 
void ConnectNode(Graph &G, infotype N1, infotype N2) {
    adrNode P1 = FindNode(G, N1);
    adrNode P2 = FindNode(G, N2);

    if (P1 != nil && P2 != nil) {
        // 1. Hubungkan P1 -> P2
        adrEdge E1 = alokasiEdge(P2);
        E1->nextEdge = P1->firstEdge; // Insert First di list edge
        P1->firstEdge = E1;

        // 2. Hubungkan P2 -> P1 (Karena Undirected)
        adrEdge E2 = alokasiEdge(P1);
        E2->nextEdge = P2->firstEdge; // Insert First di list edge
        P2->firstEdge = E2;
    } else {
        cout << "Salah satu node tidak ditemukan!" << endl;
    }
}

// Menampilkan Graph (Adjacency List)
void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != nil) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != nil) {
            cout << " -> " << E->Node->info;
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

// SOAL NO 2 : DFS

#include <stack> // untuk DFS

// Reset status visited semua node jadi 0 atau belum dikunjungi
void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != nil) {
        P -> visited = 0;
        P = P -> nextNode;
    }
}

// Prosedur menampilkan hasil penelusuran DFS
void PrintDFS(Graph G, adrNode N) {
    // Pastikan status visited bersih dulu
    ResetVisited(G);
    
    if (N == nil) return; // Kalau node awal kosong, stop

    stack<adrNode> S; // Buat stack penampung node
    
    // Masukkan node awal ke stack
    S.push(N);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        // Ambil node paling atas dari stack
        adrNode curr = S.top();
        S.pop();

        // Jika belum dikunjungi, proses node ini
        if (curr -> visited == 0) {
            curr -> visited = 1; // Tandai sudah dikunjungi
            cout << curr->info << " "; // Cetak

            // Masukkan semua tetangga yang belum dikunjungi ke stack
            adrEdge E = curr -> firstEdge;
            while (E != nil) {
                if (E -> Node -> visited == 0) {
                    S.push(E -> Node);
                }
                E = E -> nextEdge;
            }
        }
    }
    cout << endl;
}
```

### 2.3 main.cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

int main() {
    // --- soal no 1
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // 2. Connect Node (Sesuai Gambar 14-14)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H'); // Di gambar G ke H juga terhubung

    // 3. Tampilkan Graph
    cout << "=== ISI GRAPH (ADJACENCY LIST) ===" << endl;
    PrintInfoGraph(G);


    //  SOAL NO 2: DFS 
    // Kita coba DFS mulai dari Node 'A'
    adrNode startNode = FindNode(G, 'A');
    
    cout << "\n=== HASIL TRAVERSAL DFS ===" << endl;
    PrintDFS(G, startNode);

    return 0;
}
```


#### Output:
<img width="1645" height="695" alt="image" src="https://github.com/user-attachments/assets/437454b6-a6f0-440f-9c4a-202fcff1463f" />

<ol>
  <li>
    DFS adalah algoritma penelusuran graf yang memprioritaskan kedalaman suatu graph. Algoritma nya bekerja dengan cara mengunjungi simpul lalu tetangganya, dan menelusuri tetangga tersebut hingga mencapai ujung atau daun atau simpul yang sudah dikunjungi sebelum kembali ke simpul sebelumnya
  </li>
  <li>
    Implementasi dengan Stack. Dalam kode ini, DFS diimplementasikan menggunakan struktur data Stack (Tumpukan). Stack dipilih karena sifatnya LIFO , yang cocok untuk menyimpan simpul-simpul yang akan dikunjungi. Simpul yang terakhir dimasukkan ke stack (tetangga terbaru) akan menjadi simpul pertama yang diproses selanjutnya, menciptakan efek penelusuran yang "mendalam".
  </li>

  <li>
    PrintDFS. Prosedur PrintDFS dimulai dengan mereset status visited semua node menjadi 0. Kemudian, node awal dimasukkan ke stack. Selama stack tidak kosong, program akan mengambil node teratas, menandainya sebagai visited (1), mencetaknya, lalu memasukkan semua tetangga node tersebut yang belum dikunjungi ke dalam stack. Proses ini berulang hingga stack kosong, yang berarti seluruh node yang terhubung telah dikunjungi.
  </li>
</ol>



#### Full code screenshot:

#### Code .h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/cbb3d01c-dbe3-4ecb-b96f-a5f9145fb095" />



#### code .cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d8d8241e-2013-4839-81bb-27f544f0bc15" />

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d57179af-0fca-49a9-977c-d78f14256d2d" />



#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/af4b1bbe-6bfe-475e-8ad2-92501f011122" />




### 3. Soal ketiga masih menggunakan kode 1 dan 2.
<img width="530" height="70" alt="image" src="https://github.com/user-attachments/assets/fc4009c9-50b9-4d2d-b86c-b18ca4d01a09" />



### 3.1 .h
```h
#ifndef GRAPH1_H
#define GRAPH1_H
#include <iostream>
using namespace std;
#define nil NULL

// SOAL NO 1

// Tipe data untuk info node
typedef char infotype;

// pointer ke node dan edge
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infotype info; // Nama node
    int visited; // Status kunjungan (0/1) buat traversal
    adrEdge firstEdge; // Pointer ke edge pertama
    adrNode nextNode; // Pointer ke node berikutnya dalam list graph
};

struct ElmEdge {
    adrNode Node; // Menunjuk ke node tujuan
    adrEdge nextEdge; // Pointer ke edge berikutnya
};

struct Graph {
    adrNode First; // awal dari list graph
};

// -- Fungsi atau prosedur prototipe -- //

// buat graph kosong
void createGraph(Graph &G);
adrNode alokasiNode(infotype x); // Tambahan helper
adrEdge alokasiEdge(adrNode tujuan); // Tambahan helper

// tambah node baru
void InsertNode(Graph &G, infotype x);

// menghubungkan dua node dengan edge
void ConnectNode(Graph &G, infotype N1, infotype N2);

// cari node berdasarkan info
adrNode FindNode(Graph G, infotype x);

// menampilkan graph format adjacency list
void PrintInfoGraph(Graph G);


// SOAL NO 2: DFS 
// Reset status visited sebelum traversal
void ResetVisited(Graph &G);

// Traversal Depth First Search (DFS)
void PrintDFS(Graph G, adrNode N); // N adalah node awal


// SOAL NO 3: BFS
 // Traversal Breadth First Search (BFS)
void PrintBFS(Graph G, adrNode N); // N adalah node awal

#endif
```

### 3.2 .cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

// SOAL NO 1

void createGraph(Graph &G) {
    // inisialisasi graph kosong
    G.First = nil;
}

// alokasi node baru
adrNode alokasiNode(infotype x) {
    adrNode P = new ElmNode;
    P -> info = x;
    P -> visited = 0;
    P -> firstEdge = nil;
    P -> nextNode = nil;
    return P;
}

// alokasi edge baru 
adrEdge alokasiEdge(adrNode tujuan) {
    adrEdge P = new ElmEdge;
    P -> Node = tujuan;
    P -> nextEdge = nil;
    return P;
}

// cari node berdasarkan info 
adrNode FindNode(Graph G, infotype x) {
    adrNode P = G.First;
    while (P != nil) {
        if (P -> info == x) {
            return P;
        }   
        P = P -> nextNode; 
    }
    return nil;
}

//menambahkan node baru dalam graph
void InsertNode (Graph &G, infotype x) {
    // jika graph kosong
    adrNode P = alokasiNode(x);
    if (G.First == nil) {
        G.First = P;
    }else {
        // Insert di akhir list node
        adrNode last = G.First;
        while (last->nextNode != nil) {
            last = last->nextNode;
        }
        last->nextNode = P;
    }
}

// menghubungkan dua node N1 dan N2 
void ConnectNode(Graph &G, infotype N1, infotype N2) {
    adrNode P1 = FindNode(G, N1);
    adrNode P2 = FindNode(G, N2);

    if (P1 != nil && P2 != nil) {
        // 1. Hubungkan P1 -> P2
        adrEdge E1 = alokasiEdge(P2);
        E1->nextEdge = P1->firstEdge; // Insert First di list edge
        P1->firstEdge = E1;

        // 2. Hubungkan P2 -> P1 (Karena Undirected)
        adrEdge E2 = alokasiEdge(P1);
        E2->nextEdge = P2->firstEdge; // Insert First di list edge
        P2->firstEdge = E2;
    } else {
        cout << "Salah satu node tidak ditemukan!" << endl;
    }
}

// Menampilkan Graph (Adjacency List)
void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != nil) {
        cout << "Node " << P->info << ":";
        adrEdge E = P->firstEdge;
        while (E != nil) {
            cout << " -> " << E->Node->info;
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

// SOAL NO 2 : DFS

#include <stack> // untuk DFS

// Reset status visited semua node jadi 0 atau belum dikunjungi
void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != nil) {
        P -> visited = 0;
        P = P -> nextNode;
    }
}

// Prosedur menampilkan hasil penelusuran DFS
void PrintDFS(Graph G, adrNode N) {
    // Pastikan status visited bersih dulu
    ResetVisited(G);
    
    if (N == nil) return; // Kalau node awal kosong, stop

    stack<adrNode> S; // Buat stack penampung node
    
    // Masukkan node awal ke stack
    S.push(N);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        // Ambil node paling atas dari stack
        adrNode curr = S.top();
        S.pop();

        // Jika belum dikunjungi, proses node ini
        if (curr -> visited == 0) {
            curr -> visited = 1; // Tandai sudah dikunjungi
            cout << curr->info << " "; // Cetak

            // Masukkan semua tetangga yang belum dikunjungi ke stack
            adrEdge E = curr -> firstEdge;
            while (E != nil) {
                if (E -> Node -> visited == 0) {
                    S.push(E -> Node);
                }
                E = E -> nextEdge;
            }
        }
    }
    cout << endl;
}

// SOAL NO 3 : BFS
#include <queue> // untuk BFS

// Prosedur menampilkan hasil penelusuran BFS
void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    if (N == nil) return; // Kalau node awal kosong, stop
    queue<adrNode> Q; // Buat queue penampung node

    // Masukkan node awal ke queue dan tandai visited
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        // Ambil node paling depan dari queue
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";

        // Masukkan semua tetangga yang belum dikunjungi ke queue
        adrEdge E = curr->firstEdge;
        while (E != nil) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1; 
                Q.push(E->Node);
            }
            E = E->nextEdge;
        }
    }
    cout << endl;
}
```

### 3.3 main.cpp
```cpp
#include "graph1.h"
#include <iostream>
using namespace std;

int main() {
    // --- soal no 1
    Graph G;
    createGraph(G);

    // 1. Insert Node (A sampai H)
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // 2. Connect Node (Sesuai Gambar 14-14)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H'); // Di gambar G ke H juga terhubung

    // 3. Tampilkan Graph
    cout << "=== ISI GRAPH (ADJACENCY LIST) ===" << endl;
    PrintInfoGraph(G);


    //  SOAL NO 2: DFS 
    // Kita coba DFS mulai dari Node 'A'
    adrNode startNode = FindNode(G, 'A');
    
    cout << "\n=== HASIL TRAVERSAL DFS ===" << endl;
    PrintDFS(G, startNode);


    // SOAL NO 3: BFS
    cout << "\n=== HASIL TRAVERSAL BFS ===" << endl;
    PrintBFS(G, startNode);

    return 0;
}
```


#### Output:
<img width="1588" height="724" alt="image" src="https://github.com/user-attachments/assets/5ea7a790-6c7a-488e-8105-4e9f5390e848" />


BFS merupakan algoritma penelusuran graf yang memperioritaskan tetangga terdekat. Algoritma ini mengunjugi simpul awal lalu mengunjungi semua simpul tetangga yang terhubung langsung dengannya, sebelum melanjutkan ke tetangga dari tetangga tersebut (level berikutnya). Ini digunakan dengan implementasi QUEUE atau antrian yang bersifat FIFO. Dengan adanya QUEUE memastikan bahwa simpul yang ditemukan lebih dulu (tetangga dekat) akan diproses terlebih dahulu.


#### Full code screenshot:

#### Code graph1.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/7c8f36b7-d525-4498-a6f7-8f18278795d4" />



#### code graph1.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/924407ba-3bf7-490b-88be-199a71525345" />



#### code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/3d9295f4-cd6b-4fbd-9d34-3308de6e5165" />




## Kesimpulan
Pada praktikum akhir modul 14 ini, saya telah mempelajari dan mengimplementasikan struktur data Graph dengan menggunakan representasi Adjacency List. Graph merupakan struktur non linear yang terdiri dari kumpulan node (vertex) dan edge yang saling terhubung satu sama lain. Memang harus butuh latihan dan pemahaman yang baik agar lebih mengerti materi ini. Melalui latihan ini, saya berhasil menerapkan operasi manipulasi graf tak berarah (undirected), serta dua algoritma penelusuran utama: BFS (Breadth First Search) yang memanfaatkan Queue untuk penelusuran melebar , dan DFS (Depth First Search) yang memanfaatkan Stack untuk penelusuran mendalam



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.













