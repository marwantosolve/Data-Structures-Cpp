#include <bits/stdc++.h>
using namespace std;

enum class order { preorder, inorder, postorder };

template <class T>
struct AVLNode {
  T val;
  int balance;
  AVLNode<T> *right;
  AVLNode<T> *left;
};

template <class T>
class AVL {
 private:
  AVLNode<T> *root;
  AVLNode<T> *createNode(T value);
  AVLNode<T> *insertIntoAVL(AVLNode<T> *no, T value);
  AVLNode<T> *removeFromAVL(AVLNode<T> *no, T value);
  AVLNode<T> *removeMin(AVLNode<T> *no);
  AVLNode<T> *rightRotate(AVLNode<T> *no);
  AVLNode<T> *leftRotate(AVLNode<T> *no);
  void preorder(AVLNode<T> *no);
  void inorder(AVLNode<T> *no);
  void postorder(AVLNode<T> *no);
  bool searchInAVL(AVLNode<T> *no, T value);
  bool destroyAVL(AVLNode<T> *no);
  int getHeight(AVLNode<T> *no);
  int getBalance(AVLNode<T> *no);

 public:
  AVL();
  AVL(T value);
  ~AVL();
  void printAVL(order o);
  void insert(T value);
  bool search(T value);
  void remove(T value);
  bool empty(void);
};

template <class T>
AVL<T>::AVL() {
  this->root = nullptr;
}

template <class T>
AVL<T>::AVL(T value) {
  this->root = createNode(value);
}

template <class T>
AVL<T>::~AVL() {
  while (!this->empty()) {
    this->root = removeFromAVL(this->root, this->root->val);
  }
}

template <class T>
bool AVL<T>::destroyAVL(AVLNode<T> *no) {
  if (no == nullptr) {
    return true;
  } else {
    return false;
  }
}

template <class T>
bool AVL<T>::empty(void) {
  return destroyAVL(this->root);
}

template <class T>
void AVL<T>::preorder(AVLNode<T> *no) {
  if (no == nullptr) {
    return;
  } else {
    cout << no->val << " ";
    preorder(no->left);
    preorder(no->right);
  }
}

template <class T>
void AVL<T>::inorder(AVLNode<T> *no) {
  if (no == nullptr) {
    return;
  } else {
    preorder(no->left);
    cout << no->val << " ";
    preorder(no->right);
  }
}

template <class T>
void AVL<T>::postorder(AVLNode<T> *no) {
  if (no == nullptr) {
    return;
  } else {
    preorder(no->left);
    preorder(no->right);
    cout << no->val << " ";
  }
}

template <class T>
int AVL<T>::getHeight(AVLNode<T> *no) {
  if (no == nullptr) {
    return 0;
  } else {
    return no->balance;
  }
}

template <class T>
int AVL<T>::getBalance(AVLNode<T> *no) {
  if (no == nullptr) {
    return 0;
  } else {
    return (getHeight(no->left) - getHeight(no->right));
  }
}

template <class T>
AVLNode<T> *AVL<T>::leftRotate(AVLNode<T> *no) {
  AVLNode<T> *no_dir = no->right;
  AVLNode<T> *no_sub_es = no_dir->left;
  no_dir->left = no;
  no->right = no_sub_es;
  no->balance = max(getHeight(no->left), getHeight(no->right)) + 1;
  no_dir->balance = max(getHeight(no_dir->left), getHeight(no_dir->right)) + 1;
  return no_dir;
}

template <class T>
AVLNode<T> *AVL<T>::rightRotate(AVLNode<T> *no) {
  AVLNode<T> *no_es = no->left;
  AVLNode<T> *no_sub_dir = no_es->right;
  no_es->right = no;
  no->left = no_sub_dir;
  no->balance = max(getHeight(no->left), getHeight(no->right)) + 1;
  no_es->balance = max(getHeight(no_es->left), getHeight(no_es->right)) + 1;
  return no_es;
}

template <class T>
AVLNode<T> *AVL<T>::insertIntoAVL(AVLNode<T> *no, T value) {
  if (no == nullptr) {
    return createNode(value);
  } else if (value < no->val) {
    no->left = insertIntoAVL(no->left, value);
  } else if (value > no->val) {
    no->right = insertIntoAVL(no->right, value);
  } else {
    return no;
  }
  no->balance = max(getHeight(no->left), getHeight(no->right)) + 1;
  int bf = getBalance(no);
  if (bf > 1 && value < no->left->val) {
    return rightRotate(no);
  }
  if (bf < -1 && value > no->right->val) {
    return leftRotate(no);
  }
  if (bf > 1 && value > no->left->val) {
    no->left = leftRotate(no->left);
    return rightRotate(no);
  }
  if (bf < -1 && value < no->right->val) {
    no->right = rightRotate(no->right);
    return leftRotate(no);
  }
  return no;
}

template <class T>
AVLNode<T> *AVL<T>::removeMin(AVLNode<T> *no) {
  AVLNode<T> *cur = no;
  while (cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}

template <class T>
AVLNode<T> *AVL<T>::removeFromAVL(AVLNode<T> *no, T value) {
  if (no == nullptr) {
    return no;
  } else if (value < no->val) {
    no->left = removeFromAVL(no->left, value);
  } else if (value > no->val) {
    no->right = removeFromAVL(no->right, value);
  } else {
    if (no->left == nullptr && no->right == nullptr) {
      AVLNode<T> *temp = no;
      no = nullptr;
      delete temp;
    } else if (no->left == nullptr) {
      AVLNode<T> *temp = no->right;
      *no = *temp;
      delete temp;
    } else if (no->right == nullptr) {
      AVLNode<T> *temp = no->left;
      *no = *temp;
      delete temp;
    } else {
      AVLNode<T> *temp = removeMin(no->right);
      no->val = temp->val;
      no->right = removeFromAVL(no->right, temp->val);
    }
  }
  if (no == nullptr) {
    return no;
  }
  no->balance = max(getHeight(no->left), getHeight(no->right)) + 1;
  int bf = getBalance(no);
  if (bf > 1 && getBalance(no->left) >= 0) {
    return rightRotate(no);
  }
  if (bf > 1 && getBalance(no->left) < 0) {
    no->left = leftRotate(no->left);
    return rightRotate(no);
  }
  if (bf < -1 && getBalance(no->right) <= 0) {
    return leftRotate(no);
  }
  if (bf < -1 && getBalance(no->right) > 0) {
    no->right = rightRotate(no->right);
    return leftRotate(no);
  }
  return no;
}

template <class T>
bool AVL<T>::searchInAVL(AVLNode<T> *no, T value) {
  if (no == nullptr) {
    return false;
  } else if (no->val == value) {
    return true;
  } else if (no->val < value) {
    return searchInAVL(no->right, value);
  } else {
    return searchInAVL(no->left, value);
  }
}

template <class T>
bool AVL<T>::search(T value) {
  return searchInAVL(this->root, value);
}

template <class T>
void AVL<T>::insert(T value) {
  this->root = insertIntoAVL(this->root, value);
}

template <class T>
AVLNode<T> *AVL<T>::createNode(T value) {
  AVLNode<T> *n = new AVLNode<T>;
  n->val = value;
  n->balance = 1;
  n->left = nullptr;
  n->right = nullptr;
  return n;
}

template <class T>
void AVL<T>::printAVL(order o) {
  if (o == order::preorder) {
    this->preorder(this->root);
    cout << endl;
  } else if (o == order::inorder) {
    this->inorder(this->root);
    cout << endl;
  } else if (o == order::postorder) {
    this->postorder(this->root);
    cout << endl;
  }
}

template <class T>
void AVL<T>::remove(T value) {
  this->root = removeFromAVL(this->root, value);
}
