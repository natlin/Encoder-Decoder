//  Authors Nathan Lin, Vijay Kumar

#include "encoder.h"
//#include "SplayTree.h"
#include "iostream"

Encoder::Encoder()
{
} // Encoder()


Encoder::~Encoder()
{
} // ~Encoder()

/*void Encoder::printTree(TreeNode *t)
{
  if(t && t != t->left)
  {
    printTree(t->left);
    cout << t->element << "," << t->count << endl;
    printTree(t->right);
  }//if
}//printTree*/


void Encoder::encode(const unsigned char *message, const int size, 
  unsigned char *encodedMessage, 
    int *encodedSize)
{
  //HuffmanTree <unsigned char> tree(-1);
  QuadraticHashTable<unsigned char> hashTable(-1, 256);
  for(int i = 0; i < size; i++)
  {
    hashTable.insert(message[i]);
    //tree.insert(message[i]);
  }//for
  //BinaryHeap < pair < int, unsigned char> > heap(256);
  LeftistHeap<int> heap;
  for(int i = 0; i < 256; i++)
  {
    if(hashTable.array[i].info == ACTIVE)
    {
      //std::cout << hashTable.array[i].element << ","
        //<< hashTable.array[i].count<< endl;
      //pair<int, unsigned char> p1(hashTable.array[i].count, 
        //hashTable.array[i].element);
      //heap.insert(p1);
      TreeNode *newNode = new TreeNode;
      newNode->element = hashTable.array[i].element;
      newNode->count = hashTable.array[i].count;
      newNode->parent = newNode->left = newNode->right = NULL;
      heap.insert(hashTable.array[i].count, newNode);
    }//if
  }//for
  //int test = 0;
  //LeftistHeap<int> prev;
  //LeftistHeap<int> prev2;
  //int a = 0;
  //char b;
  //TreeNode<unsigned char> *n1();
  //TreeNode<unsigned char> *n2();
  //pair <int unsigned char> prev(0, 0);
  //TreeNode *root = new TreeNode();
  while(1)
  //for(int i = 0; i < 5; i++)
  {
    TreeNode *root = new TreeNode;
    TreeNode *n1 = new TreeNode;
    TreeNode *n2 = new TreeNode;

    n1 = heap.findMin();
    heap.deleteMin();
    n2 = heap.findMin();
    heap.deleteMin();

    root->left = n1;
    root->right = n2;
    n1->parent = n2->parent = root;
    root->count = n1->count + n2->count;
    root->element = 'N';

    if(heap.isEmpty())
    {
      //static TreeNode *newRoot = new TreeNode;
      //newRoot = root;
      //printTree(root);
      heap.insert(root->count, root);
      break;
    }//if

    heap.insert(root->count, root);
    //if(test == 0)
    //{
      //prev.makeEmpty();
      //prev.insert(heap.findMin(a), heap.findMin(b));
      //TreeNode *n1 = new TreeNode();
      //heap.deleteMin();
      //test = 1;
    //}//if
    //else
    //{
      //b = heap.findMin(b);
      //prev2.makeEmpty(); 
      //prev2.insert(heap.findMin(a), heap.findMin(b));
      //heap.deleteMin();
      //prev.merge(prev2);
      //heap.merge(prev);
      //if(b == heap.findMin(b))
        //break;
      //if(prev.findMin(b) == heap.findMin(b))
        //break;
      //test = 0;
    //}//else
  }//while
  heap.printTree(codes, length);
  //tree.printTree();
  int index = 0;
  int pos = 0;

  //char codelen = length[34];
  //cout << (int) codelen << endl;

  for(int i = 0; i < 256; i++)
  {
    encodedMessage[index] = length[i];
    //cout << i << " " << (int) encodedMessage[index] << " " <<length[i] << ". ";
    index++;
    encodedMessage[index] |= ((char*) &codes[i][0])[3];
    encodedMessage[index + 1] |= ((char*) &codes[i][0])[2];
    encodedMessage[index + 2] |= ((char*) &codes[i][0])[1];
    encodedMessage[index + 3] |= ((char*) &codes[i][0])[0];
    index = index + 4;
    /*if(length[i] % 8 == 0)
      index += 1 + (length[i] / 8);
    else
      index += length[i] / 8;*/
  }//for

  for(int i = 0; i < size; i++)
  {
      encodedMessage[index] |= ((char*) &codes[message[i]][pos])[3];
      encodedMessage[index + 1] |= ((char*) &codes[message[i]][pos])[2];
      encodedMessage[index + 2] |= ((char*) &codes[message[i]][pos])[1];
      encodedMessage[index + 3] |= ((char*) &codes[message[i]][pos])[0];
      //cout << encodedMessage[index] << endl;
      index += (pos + length[message[i]]) / 8;
      pos = (pos + length[message[i]]) % 8;
  }//for

  *encodedSize = index + 1;// sizeof(unsigned char);
}  // encode()
