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