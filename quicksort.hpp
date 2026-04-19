#pragma once

class Quicksort {
public:
  Quicksort();
  ~Quicksort();

  void sort(int *tablica, int l, int r);

private:
  int divideTable(int *tablica, int l, int r);
  int selectPivot(int l, int r);
  void swap(int *tablica, int i1, int i2);
  int pivot;
};
