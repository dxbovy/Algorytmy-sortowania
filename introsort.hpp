#pragma once
#include "quicksort.hpp"
#include <cmath>

template <typename T> class Introsort : public Quicksort<T> {
public:
  void sort(T *tablica, int l, int r);

private:
  void introsort(T *tablica, int l, int r, int maxDepth);
  void heapsort(T *tablica, int l, int r);
  void heapify(T *tablica, int l, int r, int i);
};

template <typename T> void Introsort<T>::sort(T *tablica, int l, int r) {
  int size = r - l + 1;
  if (size > 1) {
    int maxDepth = 2 * std::log2(size);
    introsort(tablica, l, r, maxDepth);
  }
}

template <typename T>
void Introsort<T>::introsort(T *tablica, int l, int r, int maxDepth) {
  if (r - l <= 0)
    return;

  if (maxDepth == 0) {
    heapsort(tablica, l, r);
    return;
  }

  int i = this->divideTable(tablica, l, r);
  introsort(tablica, l, i - 1, maxDepth - 1);
  introsort(tablica, i + 1, r, maxDepth - 1);
}

template <typename T> void Introsort<T>::heapsort(T *tablica, int l, int r) {
  int n = r - l + 1;

  for (int i = l + n / 2 - 1; i >= l; i--) {
    heapify(tablica, l, r, i);
  }

  for (int i = r; i > l; i--) {
    this->swap(tablica, l, i);
    heapify(tablica, l, i - 1, l);
  }
}

template <typename T>
void Introsort<T>::heapify(T *tablica, int l, int r, int i) {
  int largest = i;
  int left = 2 * (i - l) + 1 + l;
  int right = 2 * (i - l) + 2 + l;

  if (left <= r && tablica[left] > tablica[largest])
    largest = left;
  if (right <= r && tablica[right] > tablica[largest])
    largest = right;
  if (largest != i) {
    this->swap(tablica, i, largest);
    heapify(tablica, l, r, largest);
  }
}
