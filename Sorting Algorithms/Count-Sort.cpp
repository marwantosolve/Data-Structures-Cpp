#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n + k)
// Space Complexity : O(n + k)
template <typename T>
void countSort(vector<T>& v) {
  int maxVal = *max_element(v.begin(), v.end());
  vector<int> count(maxVal + 1, 0);
  for (int i = 0; i < v.size(); i++) {
    count[v[i]]++;
  }
  for (int i = 1; i <= maxVal; i++) {
    count[i] += count[i - 1];
  }
  vector<T> output(v.size());
  for (int i = 0; i < v.size(); i++) {
    output[count[v[i]] - 1] = v[i];
    count[v[i]]--;
  }
  v = output;
  return;
}
