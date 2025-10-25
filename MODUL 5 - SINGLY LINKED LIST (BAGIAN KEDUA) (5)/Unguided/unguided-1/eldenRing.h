#ifndef ERDTREE_LOG_H
#define ERDTREE_LOG_H
#define nil NULL

#include <iostream>
#include <string>
using namespace std;

// 1. definisi tipe data
// ini kenangan yang disimpan di dalam log
struct Memory {
    string name; // nama kenangan (misal: "Messmer the impaler")
    string type; // tipe(Boss, Lokasi, NPC)
    string location; // Lokas ditemukannya 
    int runeReward; // jumlah rune yang didapat
};

typedef Memory infotype;
typedef struct Node *address;

// 2. definisi Node dan List, gerbong
struct Node {
    infotype isiData; // isi data kenangan
    address next; // pointer ke kenangan selanjutnya
};
struct LogList {
    address first;
};

//3. berbagai fungsi dan prosedur pada singly linked list
// prosedur dan fungsi utama
void createLog(LogList &Log);
address alokasiMemory(infotype data);
void dealokasiMemory(address &P);
void printLog(LogList Log);
bool isEmpty(LogList Log);
int nbList(LogList Log);

// prosedur untuk menambahkan kenangan
void insertMemoryFirst(LogList &Log, address P);
void insertMemoryLast(LogList &Log, address P);
void insertMemoryAfter(LogList &Log, address P, address Prev);

// prosedur untuk menghapus kenangan
void deleteMemoryFirst(LogList &Log);
void deleteMemoryLast(LogList &Log);
void deleteMemoryAfter(LogList &Log, address Prev);
void deleteList(LogList &Log); // Hapus semua kenangan

// prosedur untuk memperbarui kenangan
void updateMemoryFirst(LogList &Log);
void updateMemoryLast(LogList &Log);
void updateMemoryAfter(LogList &Log, address Prev);

// fungsi untuk mencari kenangan
address findMemoryByName(LogList Log, string name);
address findMemoryBefore(LogList Log, string name);
void printMemoriesByType(LogList Log, string type);


#endif //ERDTREE_LOG_H