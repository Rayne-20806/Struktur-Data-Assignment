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