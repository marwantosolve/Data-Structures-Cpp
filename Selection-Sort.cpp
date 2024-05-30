#include <bits/stdc++.h>
using namespace std;

// Not a stable sort
// Time Complexity : O(n^2)
// Space Complexity : O(1)
template <typename T>
void selectionSort(T arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
  return;
}