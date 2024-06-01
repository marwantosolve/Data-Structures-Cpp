#include <bits/stdc++.h>
using namespace std;

template <class eleType>
void minHeapify(vector<eleType>& v, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int minn = i;
  if (l < n && v[l] < v[minn]) minn = l;
  if (r < n && v[r] < v[minn]) minn = r;
  if (minn != i) {
    swap(v[i], v[minn]);
    minHeapify(v, n, minn);
  }
}

template <class eleType>
void buildMinHeap(vector<eleType>& v, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    minHeapify(v, n, i);
  }
}
