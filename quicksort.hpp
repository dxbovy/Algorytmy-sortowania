#pragma once

class Quicksort {
public:
  Quicksort();
  ~Quicksort();

  void sort(int *tablica);
  void divideTable();
  void selectPivot();
  void swap();

private:
};
