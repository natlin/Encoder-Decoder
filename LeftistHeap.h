#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "RandomTree.h"
#include "dsexceptions.h"
#include <iostream>
#include <cstring>

using namespace std;

// Leftist heap class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// deleteMin( minItem )   --> Remove (and optionally return) smallest item
// Comparable findMin( )  --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void merge( rhs )      --> Absorb rhs into this heap
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class LeftistHeap
{
  public:
    LeftistHeap( ) : root( NULL )
      { }
    LeftistHeap( const LeftistHeap & rhs ) : root( NULL )
      { *this = rhs; }
    ~LeftistHeap( )
      { makeEmpty( ); }
    
    /**
     * Returns true if empty, false otherwise.
     */
    bool isEmpty( ) const
      { return root == NULL; }
    
    /**
     * Find the smallest item in the priority queue.
     * Return the smallest item, or throw Underflow if empty.
     */
    const Comparable & findMin(int a) const
    {
        if( isEmpty( ) )
            throw Underflow( );
        return root -> element;
    }

    TreeNode* & findMin() const
    {
        if(isEmpty() )
            throw Underflow( );
        return root -> node;
    }

    /**
     * Inserts x; duplicates allowed.
     */
    void insert( const Comparable & x , TreeNode*  element)
      { root = merge( new LeftistNode( x, element ), root ); }

    /**
     * Remove the minimum item.
     * Throws UnderflowException if empty.
     */
    void deleteMin( )
    {
        if( isEmpty( ) )
            throw Underflow( );

        LeftistNode *oldRoot = root;
        root = merge( root->left, root->right );
        delete oldRoot;
    }

    /**
     * Remove the minimum item and place it in minItem.
     * Throws UnderflowException if empty.
     */
    void deleteMin( Comparable & minItem )
    {
        minItem = findMin( );
        deleteMin( );
    }

    /**
     * Make the priority queue logically empty.
     */
    void makeEmpty( )
    {
        reclaimMemory( root );
        root = NULL;
    }

    /**
     * Merge rhs into the priority queue.
     * rhs becomes empty. rhs must be different from this.
     */
    void merge( LeftistHeap & rhs )
    {
        if( this == &rhs )    // Avoid aliasing problems
            return;

        root = merge( root, rhs.root );
        rhs.root = NULL;
    }

    const LeftistHeap & operator=( const LeftistHeap & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }


    void printTree( unsigned int codes[][8] , int length[256]/*, int array[256]*/ ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
        {
            //TreeNode *getter = root->node; 
            printTree( root->node, 0/*getter->code, 0*/, codes , length, /*array,*/ 0);
        }//else
    }



  private:
    struct LeftistNode
    {
        Comparable   element;
        TreeNode* node;
        LeftistNode *left;
        LeftistNode *right;
        int          npl;

        LeftistNode( const Comparable & theElement, TreeNode* element, LeftistNode *lt = NULL,
                        LeftistNode *rt = NULL, int np = 0 )
          : element( theElement ), node(element), left( lt ), right( rt ), npl( np ) { }
    };

    LeftistNode *root;

    /**
     * Internal method to merge two roots.
     * Deals with deviant cases and calls recursive merge1.
     */
    LeftistNode * merge( LeftistNode *h1, LeftistNode *h2 )
    {
        if( h1 == NULL )
            return h2;
        if( h2 == NULL )
            return h1;
        if( h1->element < h2->element )
            return merge1( h1, h2 );
        else
            return merge1( h2, h1 );
    }

    /**
     * Internal method to merge two roots.
     * Assumes trees are not empty, and h1's root contains smallest item.
     */
    LeftistNode * merge1( LeftistNode *h1, LeftistNode *h2 )
    {
        if( h1->left == NULL )   // Single node
            h1->left = h2;       // Other fields in h1 already accurate
        else
        {
            h1->right = merge( h1->right, h2 );
            if( h1->left->npl < h1->right->npl )
                swapChildren( h1 );
            h1->npl = h1->right->npl + 1;
        }
        return h1;
    }

    /**
     * Swaps t's two children.
     */
    void swapChildren( LeftistNode *t )
    {
        LeftistNode *tmp = t->left;
        t->left = t->right;
        t->right = tmp;
    }

    /**
     * Internal method to make the tree empty.
     * WARNING: This is prone to running out of stack space;
     *          exercises suggest a solution.
     */
    void reclaimMemory( LeftistNode *t )
    {
        if( t != NULL )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }
    
    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     *          exercises suggest a solution.
     */
    LeftistNode * clone( LeftistNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new LeftistNode( t->element, t->node, clone( t->left ), clone( t->right ), t->npl );
    }


    void printTree( TreeNode *t, unsigned int mask/*char str[], unsigned int mask2*/, unsigned int codes[][8], int length[256], /*int array[],*/ int size) const
    {
        if(t)
        {
          if(!t->left && !t->right)
          {
            //mask << size;
            //int shift = 31 - size;
            //cout << t->element <<"," << mask << "," << size << endl;
            length[t->element] = size;
            //array[t->element] |= mask2;
            //cout << t->element;
            for(int i = 0; i < 8; i++)
            {
              codes[t->element][i] = (mask >> i );
              //cout << " " << i << " " << codes[t->element][i];
            }//for
            //cout << endl;
          }//if
          else
          {
            size++;
            //t->left->code = strcat(str, "0");
            //str[strlen(str) - 1] = '\0';
            printTree(t->left, mask, /*mask2,*/ codes, length, /*array,*/ size);
            //str[strlen(str) - 1] = '\0';
            //t->right->code = strcat(str, "1");
            //str[strlen(str) - 1] = '\0';
            unsigned int masque = 1;
            mask |= (masque << (32 - size));
            //int masque2 = 0x80;
            //mask2 |= (masque2 << size);
            printTree(t->right, mask, /*mask2,*/ codes, length, /*array,*/ size);
            //str[strlen(str) - 1] = '\0';
            
          }//else
        }
    }
};

#endif
