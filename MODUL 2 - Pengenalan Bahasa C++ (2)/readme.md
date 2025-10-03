# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori

[penjelasan teori modul 2]

## Guided 

### 1. ArrayC++

```C++
#include <iostream>
using namespace std;

int main() {
     // 1. array 1 dimensi 
     int arr1D[5] = {10, 20, 30, 40, 50};
     cout << "Array 1 Dimensi: " << endl;
     for (int i = 0; i < 5; i++) {
          cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
     }
     cout << endl;

     // 2. array 2 dimensi
     int arr2D[2][3] = {
          {1, 2, 3},
          {4, 5, 6}
     };
     cout << "Array 2 Dimensi: " << endl;
     for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 3; j++) {
               cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << endl;
          }
     }
     cout << endl;

     // 3,  Array multidemensi (3d)
     int arr3D[2][2][3] = {
          {{1, 2, 3}, {4,5,6}},
          {{7,8,9}, {10,11,12}}
     };
     cout << "Array 3 Dimensi: " << endl;
     for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++){
               for (int k = 0; k < 3; k++) {
                    cout << "arr3D[" << i << "][" << j << "][" << k << "] = " << arr3D[i][j][k] << endl;
               }
          }
     }

     return 0;
}
}
```


## 2. Procedur
```c++
#include <iostream>
using namespace std;

void tulis (int x) {
     for (int i = 0; i < x; i++) {
          cout << "Baris ke -: " << i+1 << endl;
     }
}

int main() {
     // 2, prosedur adalah void function, prosedur tidak mengembalikan nilai atau return value
     int jumlah;
     cout << "Masukkan jumlah baris: ";
     cin >> jumlah;
     tulis(jumlah);

     return 0;
}
```

## 3. Pointer
```c++
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
```

## 4. Reference
``` c++
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
```


## Unguided 


### 1. ..............
<img width="422" height="189" alt="image" src="https://github.com/user-attachments/assets/087a2123-40e2-4ac0-b34d-4fed4b488895" />



```c++

```
#### Output:



#### Full code screenshot:






## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].
Setelah praktikum pertama dilaksanakan, saya dapat menyimpulkan bahwa praktikum ini telah membuat saya memahami dan mampu mengimplementasikan konsep-konsep basic dasar di C++ seperti deklarasi variabel, tipe data, konstanta, for loop, do-while, dan juga struktur. Selain itu juga bagaimana cara mengimport library di c++, cara running code, belajar syntax c++, menurut saya mengganti bahasa pemrograman tidak masalah karena pada dasarnya yang terpenting adalah memahami algoritma pemrograman dan juga cara kerjanya serta yang membedakan hanya syntax code nya saja, selebihnya algoritmanya menurut saya sama dan tidak ada bedanya

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
