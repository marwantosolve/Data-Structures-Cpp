#include <bits/stdc++.h>
using namespace std;

// Not a stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
template <typename T>
void shellSort(vector<T>& v) {
  int n = v.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      T temp = v[i];
      int j;
      for (j = i; j >= gap && v[j - gap] > temp; j -= gap) v[j] = v[j - gap];
      v[j] = temp;
    }
  }
}
