#include <bits/stdc++.h>
using namespace std;

template <typename T>
void merge(vector<T>& v, int left, int right, int mid) {
  vector<T> l(v.begin() + left, v.begin() + mid + 1);
  vector<T> r(v.begin() + mid + 1, v.begin() + right + 1);
  int i = 0, j = 0, k = left;
  while (i < l.size() && j < r.size()) {
    if (l[i] <= r[j]) {
      v[k++] = l[i++];
    } else {
      v[k++] = r[j++];
    }
  }
  while (i < l.size()) v[k++] = l[i++];
  while (j < r.size()) v[k++] = r[j++];
  return;
}
// Stable sort
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

template <typename T>
void mergeSort(vector<T>& v, int left, int right) {
  if (left >= right) return;
  int mid = left + (right - left) / 2;
  mergeSort(v, left, mid);
  mergeSort(v, mid + 1, right);
  merge(v, left, right, mid);
  return;
}
