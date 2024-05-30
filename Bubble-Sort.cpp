#include <bits/stdc++.h>
using namespace std;

// Stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
template <typename T>
void bubbleSort(T arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
  return;
}