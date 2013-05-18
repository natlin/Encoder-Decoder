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

void Encoder::encode(const unsigned char *message, const int size, 
  unsigned char *encodedMessage, 
    int *encodedSize)
{
  //SplayTree <unsigned char> tree(-1);
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
      std::cout << hashTable.array[i].element << ","
        << hashTable.array[i].count<< endl;
      //pair<int, unsigned char> p1(hashTable.array[i].count, 
        //hashTable.array[i].element);
      //heap.insert(p1);
    }//if
  }//for
  int test = 0;
  LeftistHeap<int> prev;
  LeftistHeap<int> prev2;
  int a;
  char b;
  //pair <int unsigned char> prev(0, 0);
  while(heap.findMin(b) != prev.findMin(b))
  {
    if(test == 0)
    {
      prev.insert(heap.findMin(a), heap.findMin(b));
      heap.deleteMin();
      test = 1;
    }//if
    else
    {
      prev2.insert(heap.findMin(a), heap.findMin(b));
      heap.deleteMin();
      prev.merge(prev2);
      heap.merge(prev);
      test = 0;
      prev.makeEmpty(); 
    }//else
  }//while
  //tree.printTree();
}  // encode()
