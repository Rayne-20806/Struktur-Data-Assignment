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
}