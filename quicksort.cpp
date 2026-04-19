#include "quicksort.hpp"

Quicksort::Quicksort() {}

Quicksort::~Quicksort() {}

void Quicksort::sort(int *tablica, int l, int r) {
  if (l < r) {
    int i = divideTable(tablica, l, r);
    sort(tablica, l, i - 1);
    sort(tablica, i + 1, r);
  }
}

int Quicksort::divideTable(int *tablica, int l, int r) {
  int divideIndex = selectPivot(l, r);
  int divideValue = tablica[divideIndex];
  swap(tablica, divideIndex, r);

  int currentPosition = l;
  for (int i = l; i < r; i++) {
    if (tablica[i] < divideValue) {
      swap(tablica, i, currentPosition);
      currentPosition++;
    }
  }
  swap(tablica, currentPosition, r);
  return currentPosition;
}

int Quicksort::selectPivot(int l, int r) { return (l + (r - l) / 2); }

void Quicksort::swap(int *tablica, int i1, int i2) {
  if (i1 != i2) {
    int temp = tablica[i1];
    tablica[i1] = tablica[i2];
    tablica[i2] = temp;
  }
}
