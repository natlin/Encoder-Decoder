//  Authors Nathan Lin, Vijay Kumar

#include "encoder.h"
#include "SplayTree.h"
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
  SplayTree <unsigned char> tree(-1);
  for(int i = 0; i < size; i++)
  {
    tree.insert(message[i]);
  }//for
  tree.printTree();
}  // encode()
