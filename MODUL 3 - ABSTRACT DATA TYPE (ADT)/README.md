# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT) (3)</h1>
<p align="center">RYAN MUHAMAD SAPUTRA</p>

## Dasar Teori
Pada Modul kali ini membahas ADT atau Abstract Data Type. ADT adalah Type dan sekumpulan PRIMITIF (operasi dasar terhadap TYPE tersebut. 

</ol>

## Guided 

### 1. Mahasiswa.h

```h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct  mahasiswa {
    /* data */
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED


```
[Penjelasan Program]

## 2. Mahasiswa.cpp
```c++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m) {
    cout << "Input nim = ";
    cin >> (m).nim;
    cout << "Input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}

```
[Penjelasan Program]

## 3. Main.cpp
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
[Penjelasan Program]



## Unguided 

### 1. Program Data Mahasiswa
<img width="797" height="88" alt="image" src="https://github.com/user-attachments/assets/fb14e08f-d1b3-478f-8969-c3d86d1fad4f" />


```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:



### 2. Program Pelajaran Dengan Menggunakan ADTA
<img width="863" height="537" alt="image" src="https://github.com/user-attachments/assets/bf8de443-2abf-4418-bec2-d94c4ea1f3bd" />


```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:



### 3. Program dibuat dengan berbagai ketentuan
<img width="738" height="104" alt="image" src="https://github.com/user-attachments/assets/5362d46d-54c2-4dc7-ad7c-36a05851d48e" />
<img width="738" height="45" alt="image" src="https://github.com/user-attachments/assets/656825bc-3166-4117-80d6-5ffba717ae3b" />



```c++
#include <iostream>
using namespace std;


}
```

#### Output:
[SS OUTPUT]
[Penjelasan Program]


#### Full code screenshot:







## Kesimpulan



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.







