#include <iostream>
using namespace std;

// prosedur untuk menukar nilai menggunakan pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z ;
    *z = temp;
}
// prosedur untuk menukar nilai menggunakan reference
void tukarReference(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 1, b = 2, c = 3;
    cout << "Sebelum menukar (Pointer): a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "Setelah menukar (Pointer): a = " << a << ", b = " << b << ", c = " << c << endl;

    int a2 = 1, b2 = 2, c2 = 3;
    cout << "Sebelum menukar (Reference): a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;
    tukarReference(a2, b2, c2);
    cout << "Setelah menukar (Reference): a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    return 0;
}