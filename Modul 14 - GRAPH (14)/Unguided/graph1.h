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