#include "Stack-ADT.cpp"

template <class Type>
class stackType : public stackADT<Type> {
 public:
  const stackType<Type>& operator=(const stackType<Type>&);

  void initializeStack();

  bool isEmptyStack() const;

  bool isFullStack() const;

  void push(const Type& newItem);

  Type top() const;

  void pop();

  stackType(int stackSize = 100);

  stackType(const stackType<Type>& otherStack);

  ~stackType();

 private:
  int maxStackSize;
  int stackTop;
  Type* list;
  void copyStack(const stackType<Type>& otherStack);
};

template <class Type>
void stackType<Type>::initializeStack() {
  stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const {
  return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const {
  return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem) {
  if (!isFullStack()) {
    list[stackTop] = newItem;
    stackTop++;
  } else
    cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::top() const {
  assert(stackTop != 0);
  return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop() {
  if (!isEmptyStack())
    stackTop--;
  else
    cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack) {
  delete[] list;
  maxStackSize = otherStack.maxStackSize;
  stackTop = otherStack.stackTop;
  list = new Type[maxStackSize];
  for (int j = 0; j < stackTop; j++) list[j] = otherStack.list[j];
}

template <class Type>
stackType<Type>::stackType(int stackSize) {
  if (stackSize <= 0) {
    cout << "Size of the array to hold the stack must be positive.\n";
    cout << "Creating an array of size 100.\n";
    maxStackSize = 100;
  } else
    maxStackSize = stackSize;
  stackTop = 0;
  list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType() {
  delete[] list;
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
  list = NULL;
  copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=(
    const stackType<Type>& otherStack) {
  if (this != &otherStack) copyStack(otherStack);
  return *this;
}