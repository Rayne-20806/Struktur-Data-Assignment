#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    //===ini soal no 1===
    // cout << "petualangan baru dimulai!! membuat tas kosong" << endl;
    // Stack tasPlayer;
    // CreateStack(tasPlayer);
    // infotype itemYangDiPop; //digunakan sebagai penampung item yang dibuang

    // cout << "Menumukan health potion (ID:3)" << endl;
    // // digunakan untuk push elemen(S, 3);
    // Push(tasPlayer, createItem("Health Potion", 3));

    // // push (S, 4;)
    // cout << "Menemukan Mana Potion (ID:4)" << endl;
    // Push(tasPlayer, createItem("Mana Potion", 4));
    
    // // Push(S, 8);
    // cout << "Menemukan Iron Sword (ID:8)" << endl;
    // Push(tasPlayer, createItem("Iron Sword", 8));
    
    // // pop(S);
    // itemYangDiPop = pop(tasPlayer);
    // cout << "Membuang item teratas: " << itemYangDiPop.nama << endl;
    
    // // Push(S, 2);
    // cout << "Menemukan Leather Shield (ID:2)" << endl;
    // Push(tasPlayer, createItem("Leather Shield", 2));
    
    // // Push(S, 3);
    // cout << "Menemukan Health Potion lagi (ID:3)" << endl;
    // Push(tasPlayer, createItem("Health Potion", 3));
    
    // // pop(S);
    // itemYangDiPop = pop(tasPlayer);
    // cout << "Membuang item teratas: " << itemYangDiPop.nama << endl;

    // // Push(S, 9);
    // cout << "Menemukan Golden Rune (ID:9)" << endl;
    // Push(tasPlayer, createItem("Golden Rune", 9));

    // // printInfo(S);
    // cout << "\n--- Isi Tas Saat Ini ---" << endl;
    // printInfo(tasPlayer);
    
    // // cout<<"balik stack"<<endl;
    // cout << "\n...Tasnya tumpah! Isinya terbalik!..." << endl;
    
    // // balikStack(S);
    // balikStack(tasPlayer);
    
    // // printInfo(S);
    // cout << "--- Isi Tas Setelah Dibalik ---" << endl;
    // printInfo(tasPlayer);

    // //====Ini soal no 2=====
    // cout << "Hello world!" << endl;
    // Stack S;
    // CreateStack(S);

    // //  pakai 'createItem' untuk mencocokkan logic soal dengan infotype 'Item' kita
    // // pushAscending(S, 3);
    // pushAscending(S, createItem("Health Potion", 3));
    // // pushAscending(S, 4);
    // pushAscending(S, createItem("Mana Potion", 4));
    // // pushAscending(S, 8);
    // pushAscending(S, createItem("Iron Sword", 8));
    // // pushAscending(S, 2);
    // pushAscending(S, createItem("Leather Shield", 2));
    // // pushAscending(S, 3);
    // pushAscending(S, createItem("Health Potion", 3)); // Ini ID 3 yang kedua
    // // pushAscending(S, 9);
    // pushAscending(S, createItem("Golden Rune", 9));

    // // printInfo(S);
    // cout << "--- Isi Tas (Harusnya 9 8 4 3 3 2) ---" << endl;
    // printInfo(S);

    // // cout<<"balik stack"<<endl;
    // cout << "\nbalik stack" << endl;

    // // balikStack(S);
    // balikStack(S);

    // // printInfo(S);
    // cout << "--- Isi Tas Setelah Dibalik (Harusnya 2 3 3 4 8 9) ---" << endl;
    // printInfo(S);

    //========== untuk soal 3===========
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    // Panggil fungsi baru kita
    getInputStream(S);

    // printInfo(S);
    cout << "\n--- Isi Tas Saat Ini ---" << endl;
    printInfo(S);
    
    // cout<<"balik stack"<<endl;
    cout << "\nbalik stack" << endl;
    
    // balikStack(S);
    balikStack(S);
    
    // printInfo(S);
    cout << "--- Isi Tas Setelah Dibalik ---" << endl;
    printInfo(S);
    return 0;
}
