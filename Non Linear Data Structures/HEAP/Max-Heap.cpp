#include <bits/stdc++.h>
using namespace std;

template <class eleType>
void maxHeapify(vector<eleType>& v, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int maxx = i;
  if (l < n && v[l] > v[maxx]) maxx = l;
  if (r < n && v[r] > v[maxx]) maxx = r;
  if (max != i) {
    swap(v[i], v[maxx]);
    maxHeapify(v, n, maxx);
  }
}

template <class eleType>
void buildMaxHeap(vector<eleType>& v, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(v, n, i);
  }
}