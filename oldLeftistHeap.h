
template <typename Comparable>
class LeftistHeap
{
  public:
  LeftistHeap();
  LeftistHeap(const LeftistHeap &rhs);
  ~LeftistHeap();

  bool isEmpty() const;
  const Comparable & findMin() const;

  void insert(const Comparable &x);
  void deletemin();
  void deleteMin(Comparable &minItem);
  void makeEmpty();
  void merge(LeftistHeap &rhs);

  const LeftistHeap & operator=(const LeftistHeap &rhs);

  private:
  struct LeftistNode
  {
    Comparable element;
    LeftistNode *left;
    LeftistNode *right;
    int npl;

    LeftistNode(const Comparable &theElement, LeftistNode *lt = NULL, 
      LeftistNode *rt = NULL, int np = 0) : element( theElement ), 
      left(lt), right(rt), npl(np) {}
  };//struct

  LeftistNode *root;

  LeftistNode *merge(LeftistNode *h1, LeftistNode *h2);
  LeftistNode *merge1(LeftistNode *h1, LeftistNode *h2);

  void swapChildren(LeftistNode *t);
  void reclaimMemory(LeftistNode *t);
  LeftistNode * clone(LeftistNode *t) const;
};

void LeftistHeap::merge(LeftistHeap &rhs)
{
  if(this == &rhs)
    return;
  root = merge(root, rhs.root);
  rhs.root = NULL;
}//merge

LeftistNode LeftistHeap::*merge(LeftistNode *h1, LeftistNode *h2)
{
  if(h1 == NULL)
    return h2;
  if(h2 == NULL)
    return h1;
  if(h1->element < h2->element)
    return merge1(h1, h2);
  else
    return merge1(h2,h1);
}//merge

LeftistNode LeftistHeap::merge1(LeftistNode *h1, LeftistNode *h2)
{
  if(h1->left == NULL)
    h1->left = h2;
  else
  {
    h1->right - merge(h1->right, h2);
    if(h1->left->np1 < h1->right->npl)
      swapChildren(h1);
    h1->np1 = h1->right->npl + 1;
  }
  return h1;
}

void LeftistHeap::insert(const Cpmarable &x)
{
  root = merge(new LeftistNode(x), root);
}

void LeftistHeap::deleteMin()
{
  if(isEmpty())
    throw UnderflowException();
  LeftistNode *oldRoot = root;
  root = merge(root->left, root->right);
  delete oldRoot;
}

template <typename Comparable>
void LeftistHeap::deleteMin(Comparable &minItem)
{
  minItem = findMin();
  deleteMin();
}
