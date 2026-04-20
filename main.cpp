#include "introsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;

struct enquiry {
  string name;
  double sortedPercentage;
  bool sortedBackwards;
};

template <typename T> bool isSorted(T tablica) {
  for (int i = 0; i < (sizeof(tablica) / sizeof(T)) - 1; i++) {
    if (tablica[i] > tablica[i + 1]) {
      return false;
    }
  }
  return true;
}

template <typename T>
void fillArray(T *tablica, int size, double sortedPercentage = 0,
               bool sortedBackwards = false) {
  for (int i = 0; i < size; i++) {
    tablica[i] = abs((rand() * rand()) % 10000000);
  }
  if (sortedBackwards == true) {
    sort(tablica, tablica + size, greater<int>());
  } else {
    int offset = size * (sortedPercentage / 100.0);
    sort(tablica, tablica + offset);
  }
}

int main() {
  srand(time(NULL));
  int sizes[] = {10000, 50000, 100000, 500000, 1000000};
  int samples = 100;

  ofstream file("output.csv");
  file << "Algorytm;Rozmiar;Scenariusz;Średni_czas";

  enquiry scenario[]{{"Wszystkie elemnty losowe", 0, false},
                     {"25% początkowych elementów posortowane", 25, false},
                     {"50% początkowych elementów posortowane", 50, false},
                     {"75% początkowych elementów posortowane", 75, false},
                     {"95% początkowych elementów posortowane", 95, false},
                     {"99% początkowych elementów posortowane", 99, false},
                     {"99.7% początkowych elementów posortowane", 99.7, false},
                     {"Wszystkie elementy posortowane odwrotnie", 0, true}};

  Quicksort<int> qs;
  Mergesort<int> ms;
  Introsort<int> is;

  for (int i = 0; i < 5; i++) {
    int size = sizes[i];
    int *array = new int[size];
    int *array_cp = new int[size];
    for (int j = 0; j < sizeof(scenario) / sizeof(scenario[0]); j++) {
      cout << "Testowanie dla rozmiaru " << size << endl;
      double QsTime = 0, MsTime = 0, IsTime = 0;

      for (int k = 0; k < samples; k++) {
        fillArray(array, size, scenario[j].sortedPercentage,
                  scenario[j].sortedBackwards);

        // QUICKSORT
        copy(array, array + size, array_cp);
        auto startQs = high_resolution_clock::now();
        qs.sort(array_cp, 0, size - 1);
        auto endQs = high_resolution_clock::now();
        QsTime += duration<double, milli>(endQs - startQs).count();
        if (!isSorted(array_cp))
          cout << "Quicksort nie jest posortowany";

        // MERGESORT
        copy(array, array + size, array_cp);
        auto startMs = high_resolution_clock::now();
        ms.sort(array_cp, 0, size - 1);
        auto endMs = high_resolution_clock::now();
        MsTime += duration<double, milli>(endMs - startMs).count();
        if (!isSorted(array_cp))
          cout << "Mergesort nie jest posortowany";

        // INTROSORT
        copy(array, array + size, array_cp);
        auto startIs = high_resolution_clock::now();
        is.sort(array_cp, 0, size - 1);
        auto endIs = high_resolution_clock::now();
        IsTime += duration<double, milli>(endIs - startIs).count();
        if (!isSorted(array_cp))
          cout << "Introsortsort nie jest posortowany";
      }

      file << "Quicksort;" << size << ";" << scenario[j].name << ";"
           << QsTime / samples << "\n";
      file << "Mergesort;" << size << ";" << scenario[j].name << ";"
           << MsTime / samples << "\n";
      file << "Introsort;" << size << ";" << scenario[j].name << ";"
           << IsTime / samples << "\n";
    }

    delete[] array;
    delete[] array_cp;
  }
  return 0;
}
