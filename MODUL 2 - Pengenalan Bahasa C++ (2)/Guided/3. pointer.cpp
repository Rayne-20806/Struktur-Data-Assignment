#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
}

int main() {
     int a = 20, b = 30;
     int *ptr;
     ptr = &a;

     cout << "Value of a(nilai dari a): " << a << endl;
     cout << "Address of a(alamat dari a): " << &a << endl;
     cout << "Value stored in ptr (address of a): " << ptr << endl;
     cout << "Valuee pointed to by ptr (value of a): " << *ptr << endl;
     cout << endl;

     tukar(&a, &b);
     cout << "After swapping, value of a= " << a << " and value of b= " << b << endl;
     return 0;
}