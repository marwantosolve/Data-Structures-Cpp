#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(nk)
// Space Complexity : O(n + k)
template <typename T>
void radixSort(vector<T>& v) {
  int n = v.size();
  vector<int> count(10, 0);
  vector<T> temp(n);

  auto getDigit = [](T num) {
    if constexpr (is_integer_v<T>) {
      return num / pow(10, floor(log10(num)) + 1);
    } else {
      return 0;
    }
  };

  for (int exp = 1; n > 0 && find(v.begin(), v.end(), true) != v.end();
       exp *= 10) {
    fill(count.begin(), count.end(), 0);
    for (int i = 0; i < n; i++) {
      count[getDigit(v[i]) + 1]++;
    }

    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
      temp[count[getDigit(v[i]) + 1] - 1] = v[i];
      count[getDigit(v[i]) + 1]--;
    }

    v = temp;
  }

  return;
}