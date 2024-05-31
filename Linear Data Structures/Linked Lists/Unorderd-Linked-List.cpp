#include "Linked-List-Type.cpp"

template <class Type>
class unorderedLinkedList : public linkedListType<Type> {
 public:
  bool search(const Type& searchItem) const;

  void insertFirst(const Type& newItem);

  void insertLast(const Type& newItem);

  void deleteNode(const Type& deleteItem);
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
  nodeType<Type>* current;
  bool found = false;
  current = this->first;
  while (current != NULL && !found)
    if (current->info == searchItem)
      found = true;
    else
      current = current->link;
  return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
  nodeType<Type>* newNode;
  newNode = new nodeType<Type>;
  newNode->info = newItem;
  newNode->link = this->first;
  this->first = newNode;
  this->count++;
  if (this->last == NULL) this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
  nodeType<Type>* newNode;
  newNode = new nodeType<Type>;
  newNode->info = newItem;
  newNode->link = NULL;
  if (this->first == NULL) {
    this->first = newNode;
    this->last = newNode;
    this->count++;
  } else {
    this->last->link = newNode;
    this->last = newNode;

    this->count++;
  }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
  nodeType<Type>* current;
  nodeType<Type>* trailCurrent;
  bool found;
  if (this->first == NULL)
    cout << "Cannot delete from an empty list." << endl;
  else {
    if (this->first->info == deleteItem) {
      current = this->first;
      this->first = this->first->link;
      this->count--;
      if (this->first == NULL) this->last = NULL;
      delete current;
    } else {
      found = false;
      trailCurrent = this->first;

      current = this->first->link;

      while (current != NULL && !found) {
        if (current->info != deleteItem) {
          trailCurrent = current;
          current = current->link;
        } else
          found = true;
      }
      if (found) {
        trailCurrent->link = current->link;
        this->count--;
        if (this->last == current) this->last = trailCurrent;
        delete current;
      } else
        cout << "The item to be deleted is not in " << "the list." << endl;
    }
  }
}
