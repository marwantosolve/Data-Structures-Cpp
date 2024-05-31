#include "../Non Linear Data Structures/HEAP/Max-Heap.cpp"
#include "../Non Linear Data Structures/HEAP/Min-Heap.cpp"

// Not a Stable sort
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

// Min Heap -> Dcscending
template <class eleType>
void minHeapSort(vector<eleType>& v) {
  int n = v.size();
  buildMinHeap(v, n);
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    minHeapify(v, i, 0);
  }
}

// Max Heap -> Acscending
template <class eleType>
void maxHeapSort(vector<eleType>& v) {
  int n = v.size();
  buildMaxHeap(v, n);
  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    maxHeapify(v, i, 0);
  }
}