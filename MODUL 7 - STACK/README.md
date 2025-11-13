# <h1 align="center">Laporan Praktikum Modul Stack (7)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
## STACK Representasi List
Stack merupakan salah satu benuk sruktur daa dimana prinsip operasi yang digunakan seperti tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebuh dahulu adalah elemen yang paling atas. Stack menganut prinsip LIFO (Last-in First-Out) yang sudah dijelaskan seperti sebelumnya. Memang seperti Single linked list namun stack memiliki aturan ketat yang berbeda seperti SLL bisa menambah elemen dimana saja, kalau stack penyisipan (push/mendorong) dan penghapusan(pop) hanya boleh dilakukan pada satu ujung yaitu TOP (bagian paling atas)

Berikut ini komponen-komponen stack:

<img width="689" height="214" alt="image" src="https://github.com/user-attachments/assets/2dbc713f-52f3-4696-a0aa-8b4ce48295cb" />

<ol>
    <li>
        <code>TOP</code>, ini bagian paling atas untuk elemen stack.
    </li>
    <li>
        <code>INFO</code>, isi data dari stack.
    </li>
    <li>
        <code>NEXT</code>, merupakan pointer yang digunakan untuk menyambungkan elemen terakhir sisip dengan elemen sebelumnya.
    </li>
</ol>
Pada gambar tersebut bisa dilihat bahwa Elemen 3 merupakan elemen pertama yang disisip, kemudian elemen 2, dan seterusnya, ini juga sama menganut FILO(Firs-in Last-out). Kemudian ada beberapa operasi-operasi stack sesuai dengan aturan yang ketat dan berbeda dengan SLL yang memiliki banyak operasi:
<ol>
    <li>
        <code>Operasi Push</code>, ini merupakan penyisipan elemen-elemen pada tumpukan data. Fungsi ini sama seperti insertFirst pada list biasa.
    </li>
        <img width="600" height="175" alt="image" src="https://github.com/user-attachments/assets/11dc2c18-54e5-413a-9bf5-d9e1b2e066bb" />
    <li>
        <code>Operasi Pop</code>, merupakan operasi pengambilan data dalam list. Operasi ini hampir mirip dengan deleteFirst dala list linear, karena elemen pertama yang  pertama kali akan di akses adalah elemen paling atas atau elemen awal saja.
    </li>
    <img width="580" height="97" alt="image" src="https://github.com/user-attachments/assets/ced9309f-57df-47de-bb02-d35d180794bf" />
</ol>

Kemudian pembahasan selanjutnya mengenai primitif-primitif yang ada dalam stack, sama seperti dasarnya pada list lainnya, namun primitif stack lebih sedikin karena dalam stack hanya melakukan operasi-operasi terhadap elemen paling atas(TOP).
<ol>
    <li>
        createStack()
    </li>
    <li>
        isEmpty()
    </li>
    <li>
        alokasi()
    </li>
    <li>
        dealokasi()
    </li>
    <li>
        Fungsi-fungsi pencarian
    </li>
    <li>
        dan fungsi primitif lainnya
    </li>
</ol>

## Stack representasi Array
Pada prinsinpnya, representasi menggunakan tabel atau array sama halnya menggunakan poiner, perbedaannya yaitu terletak pada pendeklarasian struktur datanya. Mneggunakan array berindeks dan jumlah tumpukan yang terbatas.

<img width="547" height="151" alt="image" src="https://github.com/user-attachments/assets/720616a7-b8da-46a4-9ba0-ff59668ee96a" />

Operasi-operasi stack tabel atau array masih sama pada dasarnya yaiu Push(penyisipan) dan Pop(pengambilan data atau hapus)


## Guided 


## 1. Stack Versi Linked List
## 1.1 stack.h
```h
#ifndef STACK
#define STACK
#include <iostream>
using namespace std;
#define Nil NULL

typedef struct node* address;
struct node {
    int dataAngka;
    address next;   
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int angka);

#endif
```

## 1.2 stack.cpp
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;

        int dataYangdiHapus = nodeHapus -> dataAngka;
        dealokasi(nodeHapus);
        cout << "node " <<  dataYangdiHapus << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```


## 1.3 main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program di atas merupakan cara merepresentasikan Stack dalam bentuk ADT atau abstract data type. Untuk itu buat 3 file seperti biasa:
<ol>
    <li>
        <code>stack.h</code>, merupakan ADT yang menyimpan sruct node, struct stack, dan function ataupun prosedur primitif lainnya. Pada kode ini memiliki function dan prosedur seperti <code>isEmpty, createStack, alokasi, dealokasi, push, pop, update, view, searchData</code>
    </li>
    <li>
        <code>stack.cpp</code>, disini tempat mengimplementasikan semua function dan prosedur.
    </li>
    <li>
        <code>main.cpp</code>, ini merupakan program main atau utama yang nantinya seluruh function ataupun prosedur di running disini
    </li>
</ol>


## 2. Stack Versi Array 
## 1.1 stack.h
```h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

## 1.2 stack.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```


## 1.3 main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Sama seperti no 1 sebelumnya, yang menjadi beda ialah stack ini menggunakan representasi Array bukan list, yang dimana array penggunaannya sangat terbatas karena harus dideklarassikan terlebih dahulu berapa ukuran tumpukan(node) pada stack tersebut. Program ini juga memiliki 3 file yaitu:
<ol>
    <li>
        <code>stack.h</code>, ini berisi deklarasi struct-struct dan juga function ataupun prosedur primitif sama seperti no 1 sebelummya.
    </li>
    <li>
        <code>stack.cpp</code>, berisi implementasi dari function ataupun prosedur yang sudah di deklarasikan di file .h.
    </li>
    <li>
        <code>main.cpp</code>, merupakan program utaman yang nantinya digunakan untuk menjalankan program stack array ADT ini.
    </li>
</ol>


## Unguided 

### 1. Soal Pertama, buatlah ADT Stack array, namun ada modifikasi kreatif
<img width="574" height="531" alt="image" src="https://github.com/user-attachments/assets/fe5a1cf0-4e1d-497d-b25f-0b1fa172c0d2" />

### 1.1 stack.h
```h
#ifndef STACK
#define STACK
#define nil NULL

#include <iostream>
#include <string>
using namespace std;


const int MAX_SLOTS = 20; //max kapasitas tas atau lebih tepat array
struct Item {
    string nama; 
    int id;
};
typedef Item infotype; // infotype sekarang adalah struct dari item
struct Stack {
    infotype info[MAX_SLOTS]; // array berisi 20 jumlahnya
    int top; //tumpukan atas atau top
};

// buat fungsi atau prosedur primitif sesuai soal yang ada
void CreateStack(Stack &S); 
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// tambah bagian ini opsional namun penting
bool isEmpty(Stack S);
bool isFull(Stack S);
infotype createItem(string nama, int id);

#endif
```

### 1.2 stack.cpp
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

// implementasi berbagai function or prosedur tadi
bool isEmpty(Stack S) {
    return S.top == -1;
};
bool isFull(Stack S) {
    return S.top == MAX_SLOTS -1;
};
infotype createItem(string nama, int id) {
    Item newItem;
    newItem.nama = nama;
    newItem.id = id;
    return newItem;
}

// implementasi 
void CreateStack(Stack &S) {
    S.top = -1; //terbentuk stack kosong dengan top = -1
}

void Push(Stack &S, infotype x) {
    //cek apakah sudah penuh atau belum 
    if (isFull(S)) {
        cout << "Tas penuh! tidak bisa menambah item" << endl;
    } else { // kondisi jika belum penuh
        S.top++;// naikan top 
        S.info[S.top] = x; // tambah item atau isi di posisi top baru
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Tas kosong, tidak ada yang bisa di ambil" << endl;
        return {"Error", -1};
    } else {
        infotype itemDiambil = S.info[S.top]; // ambil item di top atas
        S.top--; //kurangi top ke bawah
        return itemDiambil; // kembalikan item
    }
}

void printInfo(Stack S) {
    cout << "[TOP] -> ";
    if (isEmpty(S)) {
        cout << "Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) { // Mulai ambil dari top atas kemudian kurangi ke bawah hingga 0
            cout << "(" << S.info[i].id << ": " << S.info[i].nama << ") ->"; 
        }
        cout << "[BOTTOM]" << endl;
    }
}

void balikStack(Stack &S) {
    // butuh tas cadangan untuk membalik stack dari bawah ke top
    Stack tempStack;
    CreateStack(tempStack);

    // pindahkan item semua dari S ke tempstack, otomatis akan membalik urutan
    while (!isEmpty(S)) {
        Push(tempStack, pop(S));
    }
    S = tempStack;
}
```

### 1.3 main.cpp
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "petualangan baru dimulai!! membuat tas kosong" << endl;
    Stack tasPlayer;
    CreateStack(tasPlayer);
    infotype itemYangDiPop; //digunakan sebagai penampung item yang dibuang

    cout << "Menumukan health potion (ID:3)" << endl;
    // digunakan untuk push elemen(S, 3);
    Push(tasPlayer, createItem("Health Potion", 3));

    // push (S, 4;)
    cout << "Menemukan Mana Potion (ID:4)" << endl;
    Push(tasPlayer, createItem("Mana Potion", 4));
    
    // Push(S, 8);
    cout << "Menemukan Iron Sword (ID:8)" << endl;
    Push(tasPlayer, createItem("Iron Sword", 8));
    
    // pop(S);
    itemYangDiPop = pop(tasPlayer);
    cout << "Membuang item teratas: " << itemYangDiPop.nama << endl;
    
    // Push(S, 2);
    cout << "Menemukan Leather Shield (ID:2)" << endl;
    Push(tasPlayer, createItem("Leather Shield", 2));
    
    // Push(S, 3);
    cout << "Menemukan Health Potion lagi (ID:3)" << endl;
    Push(tasPlayer, createItem("Health Potion", 3));
    
    // pop(S);
    itemYangDiPop = pop(tasPlayer);
    cout << "Membuang item teratas: " << itemYangDiPop.nama << endl;

    // Push(S, 9);
    cout << "Menemukan Golden Rune (ID:9)" << endl;
    Push(tasPlayer, createItem("Golden Rune", 9));

    // printInfo(S);
    cout << "\n--- Isi Tas Saat Ini ---" << endl;
    printInfo(tasPlayer);
    
    // cout<<"balik stack"<<endl;
    cout << "\n...Tasnya tumpah! Isinya terbalik!..." << endl;
    
    // balikStack(S);
    balikStack(tasPlayer);
    
    // printInfo(S);
    cout << "--- Isi Tas Setelah Dibalik ---" << endl;
    printInfo(tasPlayer);

    return 0;
}

```

#### Output:
<img width="1567" height="425" alt="image" src="https://github.com/user-attachments/assets/045e79ff-85fe-4b76-b4ad-2474c891d6c1" />

Pada soal 1, disuruh mengimplementasikan ADT Stack menggunakan representasi array(tabel) sesuai dengan modul.
<ol>
    <li>
        <code>stack.h</code>, mendefinisikan struct stack dan juga fungsi-fungsi ataupun prosedur primitif seperti <code>CreateStack, Push, pop, printInfo, balikStack, isEmpty, isFull, createItem</code>
    </li>
    <li>
        <code>stack.cpp</code>, berguna untuk mengimplementasikan setiap fungsi-fungsi yang ada
    </li>
    <li>
        <code>main.cpp</code>, program main ini mensimulasikan alur LIFO (Last In First Out) sesuai soal . Dengan melakukan serangkaian Push dan pop untuk memverifikasi bahwa item yang terakhir masuk (Push(S, 9)) adalah yang berada di [TOP], menghasilkan output [TOP] 9 2 4 3. Terakhir,  memanggil balikStack yang menghasilkan output terbalik, [TOP] 3 4 2 9
    </li>
</ol>


#### Full code screenshot:

#### 1. code stack.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d783affc-ee0d-484a-89fa-4395b8c64893" />

#### 2. code stack.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f9953515-8638-41d8-b81a-79951712ad2c" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/28727c5a-20a4-4027-80aa-4fe8aa8263ba" />

#### 3. code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/86cda8e6-b7a9-435a-a8fc-9c25d256a2c5" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/0786fe5c-1848-4b89-a90b-d62f9d16c966" />





### 2. Soal 2
<img width="625" height="512" alt="image" src="https://github.com/user-attachments/assets/64e278d6-6f78-4231-bd8f-9f93e93ca55b" />


### 2.1 stack.h
```h
#ifndef STACK
#define STACK
#define nil NULL

#include <iostream>
#include <string>
using namespace std;


const int MAX_SLOTS = 20; //max kapasitas tas atau lebih tepat array
struct Item {
    string nama; 
    int id;
};
typedef Item infotype; // infotype sekarang adalah struct dari item
struct Stack {
    infotype info[MAX_SLOTS]; // array berisi 20 jumlahnya
    int top; //tumpukan atas atau top
};

// buat fungsi atau prosedur primitif sesuai soal yang ada
void CreateStack(Stack &S); 
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// tambah bagian ini opsional namun penting
bool isEmpty(Stack S);
bool isFull(Stack S);
infotype createItem(string nama, int id);

//ini untuk soal no 2
void pushAscending(Stack &S, infotype x);

#endif
```

### 2.2 Program stack.cpp
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

// implementasi berbagai function or prosedur tadi
bool isEmpty(Stack S) {
    return S.top == -1;
};
bool isFull(Stack S) {
    return S.top == MAX_SLOTS -1;
};
infotype createItem(string nama, int id) {
    Item newItem;
    newItem.nama = nama;
    newItem.id = id;
    return newItem;
}

// implementasi 
void CreateStack(Stack &S) {
    S.top = -1; //terbentuk stack kosong dengan top = -1
}

void Push(Stack &S, infotype x) {
    //cek apakah sudah penuh atau belum 
    if (isFull(S)) {
        cout << "Tas penuh! tidak bisa menambah item" << endl;
    } else { // kondisi jika belum penuh
        S.top++;// naikan top 
        S.info[S.top] = x; // tambah item atau isi di posisi top baru
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Tas kosong, tidak ada yang bisa di ambil" << endl;
        return {"Error", -1};
    } else {
        infotype itemDiambil = S.info[S.top]; // ambil item di top atas
        S.top--; //kurangi top ke bawah
        return itemDiambil; // kembalikan item
    }
}

void printInfo(Stack S) {
    cout << "[TOP] -> ";
    if (isEmpty(S)) {
        cout << "Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) { // Mulai ambil dari top atas kemudian kurangi ke bawah hingga 0
            cout << "(" << S.info[i].id << ": " << S.info[i].nama << ") ->"; 
        }
        cout << "[BOTTOM]" << endl;
    }
}

void balikStack(Stack &S) {
    // butuh tas cadangan untuk membalik stack dari bawah ke top
    Stack tempStack;
    CreateStack(tempStack);

    // pindahkan item semua dari S ke tempstack, otomatis akan membalik urutan
    while (!isEmpty(S)) {
        Push(tempStack, pop(S));
    }
    S = tempStack;
}

// untuk soal no 2
void pushAscending(Stack &S, infotype x) {
    // buat tas sementara
    Stack Temp;
    CreateStack(Temp);

    // selama isi atau S tidak kosong dan TOP > ID item baru,, Logika pengurutan (Descending)
    while (!isEmpty(S) && S.info[S.top].id > x.id) {
        // Pindahkan item yg lebih besar ke stack sementara
        Push(Temp, pop(S));
    }
    
    // Masukkan item baru (x) di posisi yang tepat
    Push(S, x);
    
    // Kembalikan semua item dari stack sementara
    while (!isEmpty(Temp)) {
        Push(S, pop(Temp));
    }
}
```

### 2.3 Program main.cpp
```cpp
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

    //====Ini soal no 2=====
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    //  pakai 'createItem' untuk mencocokkan logic soal dengan infotype 'Item' kita
    // pushAscending(S, 3);
    pushAscending(S, createItem("Health Potion", 3));
    // pushAscending(S, 4);
    pushAscending(S, createItem("Mana Potion", 4));
    // pushAscending(S, 8);
    pushAscending(S, createItem("Iron Sword", 8));
    // pushAscending(S, 2);
    pushAscending(S, createItem("Leather Shield", 2));
    // pushAscending(S, 3);
    pushAscending(S, createItem("Health Potion", 3)); // Ini ID 3 yang kedua
    // pushAscending(S, 9);
    pushAscending(S, createItem("Golden Rune", 9));

    // printInfo(S);
    cout << "--- Isi Tas (Harusnya 9 8 4 3 3 2) ---" << endl;
    printInfo(S);

    // cout<<"balik stack"<<endl;
    cout << "\nbalik stack" << endl;

    // balikStack(S);
    balikStack(S);

    // printInfo(S);
    cout << "--- Isi Tas Setelah Dibalik (Harusnya 2 3 3 4 8 9) ---" << endl;
    printInfo(S);

    return 0;
}

```

#### Output
<img width="1682" height="579" alt="image" src="https://github.com/user-attachments/assets/9bfc45b6-8e43-4ed4-8be3-7a067f565f1e" />

Untuk soal no 2, masih menggunakan codingan dari soal no 1 karena ini merupakan lanjutan, hanya saja tambahkan <code>pushAscending</code> pada file .h kemudian implementasikan di file <code>stack.cpp</code>, yang nantinya pada main.cpp atau program utama akan mengeksekusi operasi push ascending tersebut.

#### Screenshot program

#### 2.1. code stack.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/a4e4f46f-e849-4adf-b898-f26a240f4703" />

#### 2.2. code stack.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ca4a03c6-aed1-4015-968c-ee4eb56dead2" />

#### 2.3. code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f8ebff4c-2062-411a-a7bd-be2197698552" />





### 3. Lanjutan dari soal no 2, tambahkan prosedur sesuai ketentuan soal
<img width="584" height="285" alt="image" src="https://github.com/user-attachments/assets/334b589f-4980-44f3-a56d-75eadbed2a82" />

### 3.1 stack.h
```h
#ifndef STACK
#define STACK
#define nil NULL

#include <iostream>
#include <string>
using namespace std;


const int MAX_SLOTS = 20; //max kapasitas tas atau lebih tepat array
struct Item {
    string nama; 
    int id;
};
typedef Item infotype; // infotype sekarang adalah struct dari item
struct Stack {
    infotype info[MAX_SLOTS]; // array berisi 20 jumlahnya
    int top; //tumpukan atas atau top
};

// buat fungsi atau prosedur primitif sesuai soal yang ada
void CreateStack(Stack &S); 
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// tambah bagian ini opsional namun penting
bool isEmpty(Stack S);
bool isFull(Stack S);
infotype createItem(string nama, int id);

//ini untuk soal no 2
void pushAscending(Stack &S, infotype x);

// tambahan baru untuk soal no 3
void getInputStream(Stack &S);

#endif
```

### 3.2 stack.cpp
```cpp
#include "stack.h"
#include <iostream>
using namespace std;

// implementasi berbagai function or prosedur tadi
bool isEmpty(Stack S) {
    return S.top == -1;
};
bool isFull(Stack S) {
    return S.top == MAX_SLOTS -1;
};
infotype createItem(string nama, int id) {
    Item newItem;
    newItem.nama = nama;
    newItem.id = id;
    return newItem;
}

// implementasi 
void CreateStack(Stack &S) {
    S.top = -1; //terbentuk stack kosong dengan top = -1
}

void Push(Stack &S, infotype x) {
    //cek apakah sudah penuh atau belum 
    if (isFull(S)) {
        cout << "Tas penuh! tidak bisa menambah item" << endl;
    } else { // kondisi jika belum penuh
        S.top++;// naikan top 
        S.info[S.top] = x; // tambah item atau isi di posisi top baru
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Tas kosong, tidak ada yang bisa di ambil" << endl;
        return {"Error", -1};
    } else {
        infotype itemDiambil = S.info[S.top]; // ambil item di top atas
        S.top--; //kurangi top ke bawah
        return itemDiambil; // kembalikan item
    }
}

void printInfo(Stack S) {
    cout << "[TOP] -> ";
    if (isEmpty(S)) {
        cout << "Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) { // Mulai ambil dari top atas kemudian kurangi ke bawah hingga 0
            cout << "(" << S.info[i].id << ": " << S.info[i].nama << ") ->"; 
        }
        cout << "[BOTTOM]" << endl;
    }
}

void balikStack(Stack &S) {
    // butuh tas cadangan untuk membalik stack dari bawah ke top
    Stack tempStack;
    CreateStack(tempStack);

    // pindahkan item semua dari S ke tempstack, otomatis akan membalik urutan
    while (!isEmpty(S)) {
        Push(tempStack, pop(S));
    }
    S = tempStack;
}

// untuk soal no 2
void pushAscending(Stack &S, infotype x) {
    // buat tas sementara
    Stack Temp;
    CreateStack(Temp);

    // selama isi atau S tidak kosong dan TOP > ID item baru,, Logika pengurutan (Descending)
    while (!isEmpty(S) && S.info[S.top].id > x.id) {
        // Pindahkan item yg lebih besar ke stack sementara
        Push(Temp, pop(S));
    }
    
    // Masukkan item baru (x) di posisi yang tepat
    Push(S, x);
    
    // Kembalikan semua item dari stack sementara
    while (!isEmpty(Temp)) {
        Push(S, pop(Temp));
    }
}

// untuk soal 3
void getInputStream(Stack &S) {
    cout << "Masukkan ID Item (angka 0-9), tekan Enter jika selesai:" << endl;
    
    char c; // Penampung karakter
    
    // Loop ini akan terus jalan, mengambil 1 KARAKTER setiap kalinya  Sampai karakter yang diambil adalah '\n'
    while ( (c = cin.get()) != '\n' ) {
        
        // Cek apakah karakter itu adalah angka (bukan spasi/huruf)
        if (c >= '0' && c <= '9') {
            
            // 1. Ubah karakter '4' menjadi angka 4
            int id_num = c - '0'; 
            
            // 2. Buat nama item otomatis (biar kreatif)
            string item_name = "Rune Fragment " + to_string(id_num); 
            
            // 3. Push item ini ke stack
            Push(S, createItem(item_name, id_num));
            cout << "  -> Menambahkan (" << id_num << ": " << item_name << ") ke tas." << endl;
        }
        // Jika user ngetik spasi atau huruf, abaikan saja
    }
    cout << "[Input selesai!]" << endl;
}
```

### 3.3 main.cpp
```cpp
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

```

#### Output
<img width="1565" height="589" alt="image" src="https://github.com/user-attachments/assets/0d08df9c-f57c-4688-a552-003a2b857043" />

Pada latihan 3, menambahkan prosedur getInputStream(Stack &S). Prosedur ini ditambahkan ke file stack.h (sebagai prototype) dan stack.cpp (sebagai implementasi). Logika utamanya adalah membaca input dari keyboard secara per karakter menggunakan cin.get() dalam sebuah loop while.

Loop ini akan terus berjalan, mengambil setiap karakter ('4', '7', '2', dst.)  hingga user menekan tombol Enter (karakter \n). Setiap karakter angka yang valid dikonversi menjadi int (misal, '4' menjadi 4) dan di-Push ke dalam stack. Karena Push menerapkan LIFO (Last In First Out), input 4729601 menghasilkan stack dengan urutan [TOP] 1 0 6 9 2 7 4. File main.cpp diubah untuk memanggil getInputStream(S) dan memverifikasi hasilny


#### Screenshoot code

#### 3.1 code stack.h
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/c800d526-a378-49d3-a498-bc957b1eb600" />

#### 3.2 code stack.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6a9e3cfd-3d14-48ed-8958-e0d5649db9fd" />



#### 3.3 code main.cpp
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/cd1bab45-b97b-4cc4-8456-337f44581009" />








## Kesimpulan
Pada praktikum Modul 7, saya berhasil memahami bagaimana cara mengimplemenasikan struktur data stack atau tumpukan. Ada 2 cara stack bagaimana cara merepresentasikannya:
<ol>
    <li>
        Representasi pointer, ini seperti SLL namun TOP adalah first.
    </li>
    <li>
        Representasi array atau tabel. menggunakan array statis dan penanda indeks top.
    </li>
</ol>

Intinya praktikum kali ini difokuskan pada implementasi bagaimana cara menerapkan stack dengan konsep LIFO (Last-in First-out) atau FILO(First-in Last-out). Selain itu juga saya belajar dan memahami bagaiaman operasi-operasi yang ada pada stack, baik menggunakan Stack list ataupun stack array(tabel). Dengan adanya latihan modul mampu meningkatkan pemahaman lebih mendalam lagi terkait stack(tumpukan).



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.











