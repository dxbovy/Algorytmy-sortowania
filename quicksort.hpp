#pragma once

template <typename T> class Quicksort {
public:
  Quicksort();
  ~Quicksort();

  void sort(T *tablica, int l, int r);

protected:
  int divideTable(T *tablica, int l, int r);
  void swap(T *tablica, int i1, int i2);

private:
  int selectPivot(int l, int r);
};

template <typename T> Quicksort<T>::Quicksort() {}

template <typename T> Quicksort<T>::~Quicksort() {}

template <typename T> void Quicksort<T>::sort(T *tablica, int l, int r) {
  if (l < r) {
    int i = divideTable(tablica, l, r);
    sort(tablica, l, i - 1);
    sort(tablica, i + 1, r);
  }
}

template <typename T> int Quicksort<T>::divideTable(T *tablica, int l, int r) {
  int divideIndex = selectPivot(l, r);
  T divideValue = tablica[divideIndex];

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

template <typename T> int Quicksort<T>::selectPivot(int l, int r) {
  return l + (r - l) / 2;
}

template <typename T> void Quicksort<T>::swap(T *tablica, int i1, int i2) {
  if (i1 != i2) {
    T temp = tablica[i1];
    tablica[i1] = tablica[i2];
    tablica[i2] = temp;
  }
}
