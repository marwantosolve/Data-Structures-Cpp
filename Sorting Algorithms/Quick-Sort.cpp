#include <bits/stdc++.h>
using namespace std;

template <typename T>
int partition(vector<T>& v, int left, int right) {
  int pivot = left;
  for (int i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      swap(v[i], v[++pivot]);
    }
  }
  swap(v[left], v[pivot]);
  return pivot;
}

// Not a Stable sort
// Time Complexity : O(nlogn)
// Space Complexity : O(logn)

template <typename T>
void quickSort(vector<T>& v, int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = partition(v.data(), left, right);
  quickSort(v, left, pivot - 1);
  quickSort(v, pivot + 1, right);
  return;
}