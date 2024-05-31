#include <bits/stdc++.h>
using namespace std;

template <class Type>
struct nodeType {
  Type info;
  nodeType<Type>* link;
};

template <class Type>
class circularLinkedListType {
 public:
  circularLinkedListType();
  ~circularLinkedListType();
  void initializeList();
  bool isEmptyList() const;
  void print() const;
  int length() const;
  void destroyList();
  Type front() const;
  Type back() const;
  bool search(const Type& searchItem) const;
  void insertFirst(const Type& newItem);
  void insertLast(const Type& newItem);
  void deleteNode(const Type& deleteItem);

 private:
  int count;
  nodeType<Type>* first;
  nodeType<Type>* last;
  void copyList(const circularLinkedListType<Type>& otherList);
};

template <class Type>
circularLinkedListType<Type>::circularLinkedListType() {
  first = NULL;
  last = NULL;
  count = 0;
}

template <class Type>
circularLinkedListType<Type>::~circularLinkedListType() {
  destroyList();
}

template <class Type>
void circularLinkedListType<Type>::initializeList() {
  destroyList();
}

template <class Type>
bool circularLinkedListType<Type>::isEmptyList() const {
  return (first == NULL);
}

template <class Type>
void circularLinkedListType<Type>::print() const {
  if (first != NULL) {
    nodeType<Type>* current = first;
    do {
      cout << current->info << " ";
      current = current->link;
    } while (current != first);
    cout << endl;
  }
}

template <class Type>
int circularLinkedListType<Type>::length() const {
  return count;
}

template <class Type>
Type circularLinkedListType<Type>::front() const {
  assert(first != NULL);
  return first->info;
}

template <class Type>
Type circularLinkedListType<Type>::back() const {
  assert(last != NULL);
  return last->info;
}

template <class Type>
bool circularLinkedListType<Type>::search(const Type& searchItem) const {
  if (first == NULL) return false;

  nodeType<Type>* current = first;
  do {
    if (current->info == searchItem) return true;
    current = current->link;
  } while (current != first);

  return false;
}

template <class Type>
void circularLinkedListType<Type>::insertFirst(const Type& newItem) {
  nodeType<Type>* newNode = new nodeType<Type>;
  newNode->info = newItem;
  if (first == NULL) {
    first = newNode;
    last = newNode;
    newNode->link = newNode;  // Circular link
  } else {
    newNode->link = first;
    first = newNode;
    last->link = first;
  }
  count++;
}

template <class Type>
void circularLinkedListType<Type>::insertLast(const Type& newItem) {
  nodeType<Type>* newNode = new nodeType<Type>;
  newNode->info = newItem;
  if (first == NULL) {
    first = newNode;
    last = newNode;
    newNode->link = newNode;  // Circular link
  } else {
    last->link = newNode;
    newNode->link = first;
    last = newNode;
  }
  count++;
}

template <class Type>
void circularLinkedListType<Type>::deleteNode(const Type& deleteItem) {
  if (first != NULL) {
    if (first->info == deleteItem) {
      if (first == last) {
        delete first;
        first = NULL;
        last = NULL;
      } else {
        nodeType<Type>* temp = first;
        first = first->link;
        last->link = first;
        delete temp;
      }
      count--;
    } else {
      nodeType<Type>* current = first;
      nodeType<Type>* trailCurrent = NULL;
      do {
        trailCurrent = current;
        current = current->link;
        if (current->info == deleteItem) {
          trailCurrent->link = current->link;
          if (current == last) {
            last = trailCurrent;
          }
          delete current;
          count--;
          break;
        }
      } while (current != first);
    }
  }
}

template <class Type>
void circularLinkedListType<Type>::destroyList() {
  if (first != NULL) {
    nodeType<Type>* temp;
    nodeType<Type>* current = first;
    do {
      temp = current;
      current = current->link;
      delete temp;
    } while (current != first);
    first = NULL;
    last = NULL;
    count = 0;
  }
}