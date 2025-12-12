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