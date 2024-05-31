#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n) (Best case)
// Time Complexity : O(n^2) (Avrg, Worst case)
// Space Complexity : O(1)

template <typename T>
void bubbleSort(vector<T>& v) {
  bool swapped;
  for (int i = 0; i < v.size() - 1; i++) {
    swapped = false;
    for (int j = 0; j < v.size() - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
  return;
}

template <typename T>
void bubbleSortRec(vector<T>& v) {
  if (v.size() == 1) return;
  bool swapped = false;
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] > v[i + 1]) {
      swap(v[i], v[i + 1]);
      swapped = true;
    }
  }
  if (!swapped) return;
  bubbleSortRec(v);
}