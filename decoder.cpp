//  Author: Sean Davis

#include "decoder.h"
#include "RandomTree.h"
#include <iostream>
#include <cstring>

using namespace std;

Decoder::Decoder()
{
} // Decoder()


Decoder::~Decoder()
{
} // ~Decoder()


void Decoder::decode(const unsigned char* encodedMessage, const int encodedSize, 
  unsigned char* decodedMessage, int *decodedSize)
{
  TreeNode *root = new TreeNode;
  TreeNode *position = root;
  unsigned char tempcode, getBit;
  unsigned char mask = 1 << 7;
  char str[100] = {'\0'};
  int length = 0;
  int done = 0;
  int index = 0;
  //cout << (char) 67<< endl;
  for(int i = 0; i < 256; i++)
  {
    length = (int) encodedMessage[index];
    //cout << i << " " << length << " ";
    index++;
    //if( length == 0)
      //continue;
    //while(length > 0)
    for(int k = 3; k >= 0; k--)
    {
      tempcode = encodedMessage[index + k];
      for(int j = 6; j >= -1; j--)
      {
        if(length <= 0)
        {
          unsigned char element = i;
          position->element = element;
          //cout << position->element << " "<< str << endl;
          position = root;
          str[0] = '\0';
          done = 1;
          break;
        }//if
        getBit = (tempcode << j) & mask;
        if(getBit == 0)
        {
          if(position->left == NULL)
          {
            TreeNode *newNode = new TreeNode;
            newNode->parent = position;
            position->left = newNode;
          }
          strcat(str, "0");
          position = position->left;
        }//if
        else
        {
          if(position->right == NULL)
          {
            TreeNode *newNode = new TreeNode;
            newNode->parent = position;
            position->right = newNode;
          }
          strcat(str, "1");
          position = position->right;
        }//else
        length--;
      }//for(j)
      //index++;
      if(done)
      {
        done = 0;
        break;
      }
    }//while*/
    index = index + 4;
  }//for(i)
  //LeftistHeap<int> heap;
  //heap.insert(1, root);
  //heap.printTree(codes, lengths);
  TreeNode *ptr = root;
  int count = 0;
  for(; index < encodedSize; index++)
  {
    tempcode = encodedMessage[index];
    for(int i = 6; i >= -1; i--)
    {
      if(ptr->left == NULL || ptr->right == NULL)
      {
          decodedMessage[count] = ptr->element;
          cout << ptr->element;
          count++;
          ptr = root;
          i++;
      }//if
      getBit = (tempcode << i) & mask;
      if(getBit == 0)
      {
        ptr = ptr->left;
      }//if
      else
      {
        ptr = ptr->right;
      }//else
    }//for
    //index++;
  }//while
  //cout << decodedMessage << endl;
} // decode()
