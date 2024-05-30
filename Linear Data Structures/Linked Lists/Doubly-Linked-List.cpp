#include <bits/stdc++.h>
using namespace std;

template <class Type>
struct nodeType {
  Type info;
  nodeType<Type> *next;
  nodeType<Type> *back;
};

template <class Type>
class doublyLinkedList {
 public:
  const doublyLinkedList<Type> &operator=(const doublyLinkedList<Type> &);

  void initializeList();

  bool isEmptyList() const;

  void destroy();

  void print() const;

  void reversePrint() const;

  int length() const;

  Type front() const;

  Type back() const;

  bool search(const Type &searchItem) const;

  void insert(const Type &insertItem);

  void deleteNode(const Type &deleteItem);

  doublyLinkedList();

  doublyLinkedList(const doublyLinkedList<Type> &otherList);

  ~doublyLinkedList();

 protected:
  int count;
  nodeType<Type> *first;
  nodeType<Type> *last;

 private:
  void copyList(const doublyLinkedList<Type> &otherList);
};

template <class Type>
doublyLinkedList<Type>::doublyLinkedList() {
  first = NULL;
  last = NULL;
  count = 0;
}

template <class Type>
bool doublyLinkedList<Type>::isEmptyList() const {
  return (first == NULL);
}

template <class Type>
void doublyLinkedList<Type>::destroy() {
  nodeType<Type> *temp;
  while (first != NULL) {
    temp = first;
    first = first->next;
    delete temp;
  }
  last = NULL;
  count = 0;
}

template <class Type>
void doublyLinkedList<Type>::initializeList() {
  destroy();
}

template <class Type>
int doublyLinkedList<Type>::length() const {
  return count;
}

template <class Type>
void doublyLinkedList<Type>::print() const {
  nodeType<Type> *current;
  current = first;
  while (current != NULL) {
    cout << current->info << " ";
    current = current->next;
  }
}

template <class Type>
void doublyLinkedList<Type>::reversePrint() const {
  nodeType<Type> *current;
  current = last;
  while (current != NULL) {
    cout << current->info << " ";
    current = current->back;
  }
}

template <class Type>
bool doublyLinkedList<Type>::search(const Type &searchItem) const {
  bool found = false;
  nodeType<Type> *current;
  current = first;
  while (current != NULL && !found)
    if (current->info >= searchItem)
      found = true;
    else
      current = current->next;
  if (found) found = (current->info == searchItem);
  return found;
}

template <class Type>
Type doublyLinkedList<Type>::front() const {
  assert(first != NULL);
  return first->info;
}
template <class Type>
Type doublyLinkedList<Type>::back() const {
  assert(last != NULL);
  return last->info;
}

template <class Type>
void doublyLinkedList<Type>::insert(const Type &insertItem) {
  nodeType<Type> *current;
  nodeType<Type> *trailCurrent;
  nodeType<Type> *newNode;
  bool found;
  newNode = new nodeType<Type>;
  newNode->info = insertItem;
  newNode->next = NULL;
  newNode->back = NULL;
  if (first == NULL) {
    first = newNode;
    last = newNode;
    count++;
  } else {
    found = false;
    current = first;
    while (current != NULL && !found)
      if (current->info >= insertItem)
        found = true;
      else {
        trailCurrent = current;
        current = current->next;
      }
    if (current == first) {
      first->back = newNode;
      newNode->next = first;
      first = newNode;
      count++;
    } else {
      if (current != NULL) {
        trailCurrent->next = newNode;
        newNode->back = trailCurrent;
        newNode->next = current;
        current->back = newNode;
      } else {
        trailCurrent->next = newNode;
        newNode->back = trailCurrent;
        last = newNode;
      }
      count++;
    }
  }
}

template <class Type>
void doublyLinkedList<Type>::deleteNode(const Type &deleteItem) {
  nodeType<Type> *current;
  nodeType<Type> *trailCurrent;
  bool found;
  if (first == NULL)
    cout << "Cannot delete from an empty list." << endl;
  else if (first->info == deleteItem) {
    current = first;
    first = first->next;
    if (first != NULL)
      first->back = NULL;
    else
      last = NULL;
    count--;
    delete current;
  } else {
    found = false;
    current = first;
    while (current != NULL && !found)
      if (current->info >= deleteItem)
        found = true;
      else
        current = current->next;
    if (current == NULL)
      cout << "The item to be deleted is not in " << "the list." << endl;
    else if (current->info == deleteItem) {
      trailCurrent = current->back;
      trailCurrent->next = current->next;
      if (current->next != NULL) current->next->back = trailCurrent;
      if (current == last) last = trailCurrent;
      count--;
      delete current;
    } else
      cout << "The item to be deleted is not in list." endl;
  }
}