#pragma once

template <typename T> class Mergesort {
public:
  Mergesort();
  ~Mergesort();
  void sort(T *tablica, int l, int r);

private:
  void merge(T *tablica, int start, int middle, int end);
};

template <typename T> Mergesort<T>::Mergesort() {}

template <typename T> Mergesort<T>::~Mergesort() {}

template <typename T> void Mergesort<T>::sort(T *tablica, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    sort(tablica, l, m);
    sort(tablica, m + 1, r);
    merge(tablica, l, m, r);
  }
}

template <typename T>
void Mergesort<T>::merge(T *tablica, int start, int middle, int end) {
  int sizeOfLeft = middle - start + 1;
  int sizeOfRight = end - middle;
  T L[sizeOfLeft];
  T R[sizeOfRight];
  for (int i = 0; i < sizeOfLeft; i++)
    L[i] = tablica[start + i];
  for (int i = 0; i < sizeOfRight; i++)
    R[i] = tablica[middle + 1 + i];

  int i = 0;
  int j = 0;
  int k = start;

  while (i < sizeOfLeft && j < sizeOfRight) {
    if (L[i] <= R[j]) {
      tablica[k] = L[i];
      i++;
    } else {
      tablica[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < sizeOfLeft) {
    tablica[k] = L[i];
    i++;
    k++;
  }

  while (j < sizeOfRight) {
    tablica[k] = R[j];
    j++;
    k++;
  }
}
