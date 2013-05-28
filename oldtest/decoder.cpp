//Authors Nathan Lin, Fnu Vijay Kumar

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
  //unsigned char mask = 1 << 7;
  //int mask = 0x80;
  //char str[100] = {'\0'};
  int length = 0;
  int done = 0;
  int index = 0;
  for(int i = 0; i < 256; i++)
  {
    length = (int) encodedMessage[index];
    //cout << i << " " << length << " ";
    //index++;
    //if( length == 0)
      //continue;
    //while(length > 0)
    for(int k = 3; k > 0; k--)
    {
      //unsigned char mask = 1;
      unsigned char mask = 1;
      tempcode = (encodedMessage[index + k] /*>> 1*/);
      for(int j = 0; j < 8; j++)
      {
        if(length <= 0)
        {
          unsigned char element = i;
          position->element = element;
          //cout << position->element << " "<< str << endl;
          position = root;
          //str[0] = '\0';
          done = 1;
          break;
        }//if
        getBit = tempcode & mask;
        mask <<= 1;
        //tempcode <<= 1;
        if(getBit == 0)
        {
          if(position->left == NULL)
          {
            TreeNode *newNode = new TreeNode;
            newNode->parent = position;
            position->left = newNode;
          }
          //strcat(str, "0");
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
          //strcat(str, "1");
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
    index = index + 5;
  }//for(i)
  //LeftistHeap<int> heap;
  //heap.insert(1, root);
  //heap.printTree(codes, lengths);
  TreeNode *ptr = root;
  int count = 0;
  //int pos = encodedMessage[encodedSize - 1];
      //unsigned char mask = 1;
  //cout << pos << endl;
  //unsigned int mask = 0x80;
  //cout << index << endl;
  for(int h = index; h < encodedSize - 1; h++)
  {
    unsigned char mask = 1 << 7;
  tempcode = encodedMessage[h];
    for(int i = 0; i < 8; i++)
    {
      getBit = tempcode & mask;
      tempcode <<= 1;
      //mask <<= 1;
      if(ptr->left == NULL && ptr->right == NULL)
      {
          decodedMessage[count] = ptr->element;
          //cout << ptr->element;
          count++;
          ptr = root;
          //i--;
      }//if
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
  cout << decodedMessage << endl;
} // decode()
