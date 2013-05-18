#ifndef _RANDOM_TREE_H_
#define _RANDOM_TREE_H_

//template<class Comparable>
//class HuffmanTree;

//template<class Comparable>
struct TreeNode
{
  unsigned char element;
  int count;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  //TreeNode( ) : count(0), parent(NULL), left( NULL), right( NULL) {}
  //TreeNode( const Comparable &theElement, const int cnt, TreeNode *lt,
    //TreeNode *rt) : element(theElement), count(cnt), parent(NULL), 
    //left(lt), right(rt){}
  //friend class HuffmanTree<Comparable>;
};//Node


/*void printTree(TreeNode *t)
{
  if(t != t->left)
  {
    printTree(t->left);
    cout << t->element << "," << t->count << endl;
    printTree(t->right);
  }//if
}//printTree*/

/*template<class Comparable>
class HuffmanTree
{
  public:
  explicit HuffmanTree(const Comparable &notFound) : ITEM_NOT_FOUND(notFound) {
    nullNode = new TreeNode<Comparable>;
    nullNode->left = nullNode->right = nullNode;
    nullNode->element = notFound;
    root = nullNode;}
  HuffmanTree(const HuffmanTree &rhs) : ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND){
    nullNode = new TreeNode<Comparable>;
    nullNode->left = nullNode->right = nullNode;
    nullNode->element = ITEM_NOT_FOUND;
    root = nullNode;
    *this = rhs; }
  ~HuffmanTree();

  void insertLeft(TreeNode *a) {
    TreeNode<Comparable> *newNode = new TreeNode<Comparable>;
    a->parent = newNode;
    //b->paent = this;
    newNode->left = a;
    root = newNode; }
    //this->right = b;}
  void insertRight(TreeNode *b) {
    b->parent = this;
    this->right = b;
  }

  private:
  TreeNode<Comparible> *root;
  TreeNode<Comparible> *nullNode;
  const Comparable ITEM_NOT_FOUND;
};//class*/


#endif
