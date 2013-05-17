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
  BinaryHeap < pair < int, unsigned char> > heap(256);
  for(int i = 0; i < 256; i++)
  {
    if(hashTable.array[i].info == ACTIVE)
    {
      std::cout << hashTable.array[i].element << ","
        << hashTable.array[i].count<< endl;
      pair<int, unsigned char> p1(hashTable.array[i].count, 
        hashTable.array[i].element);
      heap.insert(p1);
    }//if
  }//for
  //tree.printTree();
}  // encode()
