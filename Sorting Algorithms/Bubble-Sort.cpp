#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
template <typename T>
void bubbleSort(vector<T>& v) {
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = 0; j < v.size() - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  return;
}