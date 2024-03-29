// Authors Nathan Lin, Fnu Vijay Kumar
#ifndef ENCODER_H
#define	ENCODER_H

//#include "QuadraticProbing.h"
//#include "BinaryHeap.h"
//#include <utility>
//#include "BinaryTree.h"
#include "LeftistHeap.h"
//#include "RandomTree.h"

class Encoder
{
public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
  //void printTree(TreeNode *t);
private:
  unsigned int codes[256][8];
  int array[256];
  int length[256];
};

#endif	/* ENCODER_H */

