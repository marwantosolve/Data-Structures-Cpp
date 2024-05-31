#include <bits/stdc++.h>
using namespace std;

// Not a stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)

template <typename T>
void selectionSort(vector<T>& v) {
  for (int i = 0; i < v.size() - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j] < v[minIndex]) {
        minIndex = j;
      }
    }
    swap(v[minIndex], v[i]);
  }
  return;
}
