// This is the implementation of Max Binary Heap as an ADT
// It is a separate Non linear data structure
// It's also didn't mention in the book in this way
// He only mentioned build heap from a vector and heap sort
// You can find that in Heap-Sort folder in Sorting Algorithms
// Sort Items in Descending Order as they inserted

#include <bits/stdc++.h>
using namespace std;

template <typename eleType>
class MaxBinaryHeap {
 private:
  int capacity{1000};
  eleType *array{};
  int size{};

  int left(int node) {
    int p = 2 * node + 1;
    if (p >= size) return -1;
    return p;
  }

  int right(int node) {
    int p = 2 * node + 2;
    return p >= size ? -1 : p;
  }

  int parent(int node) { return node == 0 ? -1 : (node - 1) / 2; }

  void heapify_up(int child_pos) {
    int par_pos = parent(child_pos);
    if (child_pos == 0 || array[par_pos] > array[child_pos]) return;
    swap(array[child_pos], array[par_pos]);
    heapify_up(par_pos);
  }

  void heapify_down(int parent_pos) {
    int child_pos = left(parent_pos);
    int right_child = right(parent_pos);
    if (child_pos == -1) return;
    if (right_child != -1 && array[right_child] > array[child_pos])
      child_pos = right_child;
    if (array[parent_pos] < array[child_pos]) {
      swap(array[parent_pos], array[child_pos]);
      heapify_down(child_pos);
    }
  }

  void heapify() {
    for (int i = size / 2 - 1; i >= 0; --i) heapify_down(i);
  }

 public:
  MaxBinaryHeap() {
    array = new eleType[capacity]{};
    size = 0;
  }

  MaxBinaryHeap(const vector<eleType> &v) {
    assert((int)v.size() <= capacity);
    array = new eleType[capacity]{};
    size = v.size();
    for (int i = 0; i < (int)v.size(); ++i) array[i] = v[i];
    heapify();
  }

  ~MaxBinaryHeap() {
    delete[] array;
    array = nullptr;
  }

  eleType top() {
    assert(!isempty());
    return array[0];
  }

  void push(eleType key) {
    assert(size + 1 <= capacity);
    array[size++] = key;
    heapify_up(size - 1);
  }

  void pop() {
    assert(!isempty());
    array[0] = array[--size];
    heapify_down(0);
  }

  bool isempty() { return size == 0; }
};