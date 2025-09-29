#include <iostream>
using namespace std;

int main() {
     // 6. do while
     int i = 0;
     int j = 20;
     while (i <= 10) {
          cout << i << "-";
          i++;
     }
     cout << endl;

     do {
          cout << j << "-";
          j++;
     } while (j <= -2000);
}