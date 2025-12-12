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
