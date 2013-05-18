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
      heap.insert(hashTable.array[i].count, hashTable.array[i].element);
    }//if
  }//for
  int test = 0;
  LeftistHeap<int> prev;
  LeftistHeap<int> prev2;
  int a = 0;
  char b;
  //pair <int unsigned char> prev(0, 0);
  while(1)
  //for(int i = 0; i < 5; i++)
  {
    if(test == 0)
    {
      prev.makeEmpty();
      prev.insert(heap.findMin(a), heap.findMin(b));
      heap.deleteMin();
      test = 1;
    }//if
    else
    {
      b = heap.findMin(b);
      prev2.makeEmpty(); 
      prev2.insert(heap.findMin(a), heap.findMin(b));
      heap.deleteMin();
      prev.merge(prev2);
      heap.merge(prev);
      if(b == heap.findMin(b))
        break;
      //if(prev.findMin(b) == heap.findMin(b))
        //break;
      test = 0;
    }//else
  }//while
  //tree.printTree();
}  // encode()
