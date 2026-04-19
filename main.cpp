#include "introsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include <iostream>
using namespace std;

int main() {
  int tablica[30] = {47, 12, 89, 5,  66, 23, 91, 34, 78, 19,
                     55, 3,  98, 41, 10, 72, 28, 83, 60, 15,
                     37, 94, 6,  51, 82, 22, 68, 45, 11, 77};

  Introsort<int> ms;

  ms.sort(tablica, 0, 29);

  for (int i = 0; i < 30; i++) {
    cout << tablica[i] << " ";
  }
  return 0;
}
