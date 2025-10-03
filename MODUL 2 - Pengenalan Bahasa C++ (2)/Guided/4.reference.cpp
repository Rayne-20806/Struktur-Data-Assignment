#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
     int temp;
     temp = x;
     x = y;
     y = temp;
}

int main() {
     int a = 20, b = 30;
     int& ref = a; // reference variable

     cout << "Nilai dari a: " << a << endl;
     cout << "Alamat dari a (&a): " << &a << endl;
     cout << "Nilai dari ref (reference variable): " << ref << endl;
     cout << "Alamat dari ref (&ref): " << &ref << endl;    

     // mengubah nila a melalui reference variable
     ref = 50;
     cout << "\nsetelah ref = 50;" << endl;
     cout << "Nilai dari a: " << a << endl;
     cout << "Nilai dari ref: " << ref << endl;

     tukar (a,b);
     cout << "Setelah menukar, nilai a = " << a << " dan nilai b= " << b << endl;

     return 0;
}