#include <bits/stdc++.h>
using namespace std;

template <class eleType>
void minHeapify(vector<eleType>& v, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int min = i;
  if (l < n && v[l] < v[min]) min = l;
  if (r < n && v[r] < v[min]) min = r;
  if (min != i) {
    swap(v[i], v[min]);
    minHeapify(v, n, min);
  }
}

template <class eleType>
void buildMinHeap(vector<eleType>& v) {
  for (int i = v.size() / 2 - 1; i >= 0; i--) {
    minHeapify(v, v.size(), i);
  }
}
