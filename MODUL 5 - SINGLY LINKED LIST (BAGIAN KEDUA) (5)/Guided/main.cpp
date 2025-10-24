#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtbBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 314500);
   

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    //lanjutan  
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;



    
    cout << "--- ISIS LIST SETELAH DILAKUKAN UPDATE --- " << endl;
    cout << "(Memanggil updateFirst...)\n";
    updateFirst(List); // Ini akan mengupdate node "Jeruk"
    
    cout << "\n(Memanggil updateLast...)\n";
    updateLast(List);  // Ini akan mengupdate node "Durian"
    
    cout << "\n(Memanggil updateAfter nodeC 'pir'...)\n";
    updateAfter(List, nodeC); // Ini akan mengupdate node setelah "pir", yaitu "Semangka"

    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    
    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
}

//note: jika ingin hapus list maka lepas dulu pointer previousnya agar bisa hapus node
// Untuk Laprak Unguided....hindara Data Buah dan Data Mahasiswa
