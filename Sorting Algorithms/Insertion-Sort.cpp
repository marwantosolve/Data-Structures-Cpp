#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
template <typename T>
void insertionSort(vector<T>& v) {
  for (int i = 1; i < v.size(); i++) {
    T key = v[i];
    for (j = i; j > 0 && key > v[j - 1]; j--) {
      a[j] = a[j - 1];
    }
    v[j] = key;
  }
  return;
}