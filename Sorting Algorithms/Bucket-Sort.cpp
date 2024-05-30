#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n)
// Space Complexity : O(n)
template <typename T>
void bucketSort(vector<T>& v) {
  int n = v.size();
  vector<int> count(100, 0);
  vector<T> temp(n);
  double maxVal = *max_element(v.begin(), v.end());
  double minVal = *min_element(v.begin(), v.end());
  double range = maxVal - minVal + 1;

  for (int i = 0; i < n; i++) {
    count[(int)(v[i] * 100 / range)]++;
    temp[count[(int)(v[i] * 100 / range)] - 1] = v[i];
    count[(int)(v[i] * 100 / range)]--;
  }

  for (int i = 1; i <= 100; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    temp[count[(int)(v[i] * 100 / range)] - 1] = v[i];
    count[(int)(v[i] * 100 / range)]--;
  }

  v = temp;
  return;
}