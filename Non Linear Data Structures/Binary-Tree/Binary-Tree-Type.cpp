#include <bits/stdc++.h>
using namespace std;

template <class elemType>
struct binaryTreeNode {
  elemType info;
  binaryTreeNode<elemType> *llink;
  binaryTreeNode<elemType> *rlink;
};

template <class elemType>
class binaryTreeType {
 public:
  const binaryTreeType<elemType> &operator=(const binaryTreeType<elemType> &);
  bool isEmpty() const;
  void inorderTraversal() const;
  void preorderTraversal() const;
  void postorderTraversal() const;
  void levelorderTraversal() const;
  int treeHeight() const;
  int treeNodeCount() const;
  int treeLeavesCount() const;
  void destroyTree();
  binaryTreeType(const binaryTreeType<elemType> &otherTree);
  binaryTreeType();
  ~binaryTreeType();

 protected:
  binaryTreeNode<elemType> *root;

 private:
  void copyTree(binaryTreeNode<elemType> *&copiedTreeRoot,
                binaryTreeNode<elemType> *otherTreeRoot);
  void destroy(binaryTreeNode<elemType> *&p);
  void inorder(binaryTreeNode<elemType> *p) const;
  void preorder(binaryTreeNode<elemType> *p) const;
  void postorder(binaryTreeNode<elemType> *p) const;
  void levelorder(binaryTreeNode<elemType> *p) const;
  int height(binaryTreeNode<elemType> *p) const;
  int max(int x, int y) const;
  int nodeCount(binaryTreeNode<elemType> *p) const;
  int leavesCount(binaryTreeNode<elemType> *p) const;
};

template <class elemType>
void binaryTreeType<elemType>::levelorder(binaryTreeNode<elemType> *p) const {
  if (p == NULL) return;
  queue<binaryTreeNode<elemType> *> q;
  q.push(p);
  while (!q.empty()) {
    binaryTreeNode<elemType> *node = q.front();
    q.pop();
    cout << node->info << " ";
    if (node->llink != NULL) q.push(node->llink);
    if (node->rlink != NULL) q.push(node->rlink);
  }
}

template <class elemType>
void binaryTreeType<elemType>::levelorderTraversal() const {
  levelorder(root);
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const {
  return (root == NULL);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType() {
  root = NULL;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const {
  inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const {
  preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const {
  postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const {
  return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const {
  return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const {
  return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const {
  if (p != NULL) {
    inorder(p->llink);
    cout << p->info << " ";
    inorder(p->rlink);
  }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const {
  if (p != NULL) {
    cout << p->info << " ";
    preorder(p->llink);
    preorder(p->rlink);
  }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const {
  if (p != NULL) {
    postorder(p->llink);
    postorder(p->rlink);
    cout << p->info << " ";
  }
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const {
  if (p == NULL)
    return 0;
  else
    return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const {
  if (x >= y)
    return x;
  else
    return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const {
  if (p == NULL) {
    return 0;
  } else {
    return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
  }
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const {
  if (p == NULL) {
    return 0;
  } else if (p->llink == NULL && p->rlink == NULL) {
    return 1;
  } else {
    return leavesCount(p->llink) + leavesCount(p->rlink);
  }
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(
    binaryTreeNode<elemType> *&copiedTreeRoot,
    binaryTreeNode<elemType> *otherTreeRoot) {
  if (otherTreeRoot == NULL)
    copiedTreeRoot = NULL;
  else {
    copiedTreeRoot = new binaryTreeNode<elemType>;
    copiedTreeRoot->info = otherTreeRoot->info;
    copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
    copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
  }
}

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType> *&p) {
  if (p != NULL) {
    destroy(p->llink);
    destroy(p->rlink);
    delete p;
    p = NULL;
  }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree() {
  destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType(
    const binaryTreeType<elemType> &otherTree) {
  if (otherTree.root == NULL)
    root = NULL;
  else
    copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType() {
  destroy(root);
}

template <class elemType>
const binaryTreeType<elemType> &binaryTreeType<elemType>::operator=(
    const binaryTreeType<elemType> &otherTree) {
  if (this != &otherTree) {
    if (root != NULL) destroy(root);
    if (otherTree.root == NULL)
      root = NULL;
    else
      copyTree(root, otherTree.root);
  }
  return *this;
}