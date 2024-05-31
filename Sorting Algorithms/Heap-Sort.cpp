#include "../Non Linear Data Structures/HEAP/Max-Heap.cpp"
#include "../Non Linear Data Structures/HEAP/Min-Heap.cpp"

template <class eleType>
void minHeapSort(vector<eleType>& v) {
  buildMinHeap(v);
  for (int i = v.size() - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    minHeapify(v, i, 0);
  }
}

template <class eleType>
void maxHeapSort(vector<eleType>& v) {
  buildMaxHeap(v);
  for (int i = v.size() - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    maxHeapify(v, i, 0);
  }
}
