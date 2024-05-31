#include <bits/stdc++.h>
using namespace std;

template <class eleType>
void maxHeapify(vector<eleType>& v, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int max = i;
  if (l < n && v[l] > v[max]) max = l;
  if (r < n && v[r] > v[max]) max = r;
  if (max != i) {
    swap(v[i], v[max]);
    maxHeapify(v, n, max);
  }
}

template <class eleType>
void buildMaxHeap(vector<eleType>& v) {
  for (int i = v.size() / 2 - 1; i >= 0; i--) {
    maxHeapify(v, v.size(), i);
  }
}