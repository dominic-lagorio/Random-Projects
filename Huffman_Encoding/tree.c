/* This is tree.c, the code to originally make the tree and all that jazz.
Dominic Lagorio
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"tree.h"

typedef struct tree TREE;

struct tree{
    int data;
    struct tree * left, * right, * parent;
};

void detatch(struct tree * tp);

/*
 This function allocates and sets up a new tree.
 */
struct tree *createTree(int data, struct tree *left, struct tree *right){
    
    //actually allocating the tree and making sure tha that happened
    TREE *tp = malloc(sizeof(TREE));
    assert(tp != NULL);
    
    
    //setting the left and right pointers
    setLeft(tp, left);
    setRight(tp, right);
    
    //setting the data and parent
    tp -> data = data;
    tp -> parent = NULL;
    
    
    return tp;
}

/*
 This function deallocates the entire subtree pointed to by the recieved pointer CHECK THIS THING FIRST!!!!!!!
 */
void destroyTree(struct tree *root){
  
    assert(root != NULL);
   
    if(root -> left != NULL || root -> right != NULL){
        if (root -> left){
            destroyTree(root -> left);
        }
        if (root -> right != NULL){
            destroyTree(root -> right);
        }
    }
    
    detatch(root);
    free(root);
    return;
}

/*
 This function returns the data in the root in question
 */
int getData(struct tree *root){
    
    assert(root != NULL);
    return root-> data;
}

/*
This function returns the data in the "left" child
 */
struct tree *getLeft(struct tree *root){
    
    assert(root != NULL);
    return root -> left;
}

/*
 This function returns the data from the right subtree
 */
struct tree *getRight(struct tree *root){
    
    assert(root != NULL);
    return root -> right;
}

/*
 This function returns the parent  of the given pointer
 */
struct tree *getParent(struct tree *root){
    
    assert(root != NULL);
    return root -> parent;
    
}

/*
 Sets the left pointer of the root in question
 */
void setLeft(struct tree *root, struct tree *left){
    
    //checks to se if the kid was alone/ had a parent with them
    if( left != NULL){
        detatch(left);
    
        left -> parent = root;
    }
    root -> left = left;
    
    return;
    
}

/*
 Sets the right pointer of the given pointer.
 */
void setRight(struct tree *root, struct tree *right){
    
    //checks to se if the kid was alone/ had a parent with them
    if(right != NULL){
        detatch(right);
        
        right -> parent = root;
    }
    root -> right = right;
    
    return;
}

/*
 This function removes any existing parents from the adopted child
 */
void detatch( struct tree * tp){
    
    //checks to see whether or not there is a parent, and which child the pointer is
    if(tp -> parent != NULL){
        if(tp -> parent -> left == tp){
            
            tp -> parent -> left = NULL;
            
        }else{
            
            tp -> parent -> right = NULL;
            
        }
        tp -> parent = NULL;
    }
    
    return;
}
