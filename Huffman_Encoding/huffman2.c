/*
 This is huffman.c, the og, the bigg hufflepuff, yeet
 ?
 Dominic Lagorio
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include"tree.h"
#include"pack.h"

#define p(x) (((x) - 1)/2)
#define l(x) ((x) * 2 + 1)
#define r(x) ((x) * 2 + 2)

struct tree * leaves[257];

struct tree * heap[257];
int heapcount = 0;

void count(FILE * );
void inHeap( struct tree * );
void print(struct tree * );
struct tree * deleteMin(void);

int main( int argc, char* argv[]){
    
    assert( argc == 3);
    
    int i;
    
    FILE * fp = fopen(argv[1], "r");
    
//this lil thing counts the occurences while simultaneuously putting them into the heap
    count(fp);
    
// sets up the huffman tree
    struct tree * l, * r, * combined;
    while (heapcount > 1){
        l = deleteMin();
	r = deleteMin();
	combined = createTree((getData(l) + getData(r)), l, r );
	inHeap(combined);
    }
    //print the tree....each character should be paired with its newly incrypted bitcode.
    for (i = 0; i < 256; i++) {
        
        char encoded = i;
        
        if (isprint(encoded) != 0) {
            
            printf("[%c:\t%d:\t", encoded, getdata(leaves[i]));
            
        }else{
            
            printf("%03o:\t%d:\t", encoded, getdata(leaves[i]));
        }
        print(leaves[i]);
        printf("]\n");
    }
    
    printf("EOF:\t0:\t");
    print(leaves[256]);
    printf("\n");
    
    pack(argv[1], argv[2], leaves);
    fclose(fp);
    return 0;
}

void count(FILE * fp){
    
    int c, i, countc[257];
    for(i = 0; i < 257; i ++)
        countc[i] = 0;
    while((c = fgetc(fp)) != EOF){
        countc[c]++;
    }
    for( i = 0 ; i < 257 ; i ++){
        if ( countc[i] != 0){
            leaves[i] = createTree(countc[i], NULL, NULL);
            inHeap(leaves[i]);
        }else
            leaves[i] = NULL;
        
    }
    return;
}

void inHeap( struct tree * new){
    
    if(heapcount == 0){
        heap[0] = new;
        heapcount++;
        return;
    }
    
    struct tree * temp;
    int index = heapcount;
    heap[heapcount] = new;
    
    while(getData(heap[p(index)]) > getData(new)){
        
        temp = heap[p(index)];
        heap[p(index)] = new;
        heap[index] = temp;
        
        index = p(index);

        if( heap[0] == new){
            return;
        }
    }
    heapcount ++;
   //print(heap[index]);
    return;
}


struct tree * deleteMin(void){
    
    struct tree * min = heap(0);
    struct tree * temp;
    int index = 0;
    int smaller;
    // replace with the last value
    // move everything down
    heap[0] = heap[heapcount - 1];
    heap[heapcount - 1] = NULL;
    while (l(index) < heapcount) {// ask about bounding
        
        //if the right child exists, then compare the children, then compare the new thing to the smaller child.
        if (heap[r(index)] != NULL){
            smaller = ( l(index) < r(index) ? l(index): r(index) );
        }
        // Else just compare with the left child
        if (getData(heap[index]) > getData(heap[smaller]) ){
            
            temp = heap[index];
            heap[index] = heap[smaller];
            heap[smaller] = temp;
            
            index = smaller;
            
         }
            
    }
    heapcount --;
    
    
    return min;
}

void print(struct tree * leaf){
// it needs to print the things... you know, the bits and the character... do it recursively
// how do I track the path?
   
   if( getParent(leaf) == NULL || leaf == NULL)
	return;
   
   if (leaf == (getRight(getParent(leaf)))){
	printf("1");
   }else{
	printf("0");
   }
    print(getParent(leaf));
}

