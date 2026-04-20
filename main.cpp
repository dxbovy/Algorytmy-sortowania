#include "introsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;
using namespace std::chrono;

struct enquiry {
  int numOfElements;
  double sortedPercentage;
  bool sortedBackwards;
};

template <typename T> bool isSorted(T tablica) {
  for (int i = 0; i < sizeof(tablica) / sizeof(T); i++) {
    if (tablica[i] > tablica[i + 1]) {
      return false;
    }
  }
  return true;
}

template <typename T>
void fillArray(T *tablica, int size, double sortedPercentage = 0,
               bool sortedBackwards) {
  for (int i = 0; i < size; i++) {
    tablica[i] = rand() * rand();
  }
  if (sortedBackwards == true) {
    T temp;
    sort(tablica, tablica + (size - 1));
    for (int i = 0; i < size / 2; i++) {
      temp = tablica[i];
      tablica[i] = tablica[size - 1 - i];
      tablica[size - 1 - i] = temp;
    }
  } else {
    sort(tablica, tablica+((size-1) * (sortedPercentage/100));
  }
}

int main() {
  srand(420);
  int sizes[5] = {10000, 50000, 100000, 50000, 1000000};
  double percentages[6] = {
    25,
  } for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 5; j++) {
      int tablica[sizes[j]];
      fillArray<int>(tablica, sizes[j], 0, true);

      for (int k = 0; k < sizes[j]; k++) {
        cout << tablica[k] << " ";
      }
    }
  }
  return 0;
}
