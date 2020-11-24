#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MinHeapNode { 
  
   
    char data;
    unsigned freq; 
  
    struct MinHeapNode *left, *right; 
}; 

struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
  
    node->left = node->right = NULL; 
    node->data = data; 
    node->freq = freq; 
  
    return node; 
} 

struct MinHeap* createMinHeap(unsigned capacity) 
  
{ 
  
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*)); 
    
    return minHeap; 
} 
