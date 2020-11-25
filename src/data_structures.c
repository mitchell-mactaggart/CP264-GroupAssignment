#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct MinHeapNode { 

    unsigned char data;
    int freq; 
  
    struct MinHeapNode *left, *right; 
};

typedef struct _pq{
  int heap_size;
  MinHeapNode *array[256];
} PQ;

void create _pq(PQ *q) {
  q->heap_size = 0;
}

int parent(int i){
  return (i-1) / 2;
}

int left(int i){
  return i * 2 + 1;
}

int right(int i) {
  return i * 2 + 2;
}

void heapify(PQ *q, int i) {
  int l, r, min;
  MinHeapNode *n;
  
  l = left(i);
  r = right(i);
  
  if(l < q->heap_size && q->array[l]->freq < q->array[i]->freq) {
    min = l;
  else{
    min = i;
  }
    
  if(r < q->heap_size && q->array[r]->freq < p->array[min]->freq) {
    min = r;
  }
    
  if(min != i){
    n = q->array[i];
    q->array[i] = q->array[min];
    q->array[min] = n;
    heapify(q, min);
  }
    
}

void insert_pq(PQ *q, MinHeapNode *n) {
  int i;
  
  i = q->heap_size;
  
  while((i > 0) && (q->array[(i-1) / 2]->freq > n->freq)){
    q->array[i] = q->array[(i-1) / 2];
    i = (i-1) / 2;
  }
  q->array[i] = n;
  q->heap_size++;
}
  
MinHeapNode *remove_pq(PQ *q){
  MinHeapNode *n;
  
  if(q->heap_size == 0) {
    exit(1);
  }
  
  n = q->array[0];
  q->array[0] = q->array[q->heap_size-1];
  q->heap_size--;
  
  heapify(q, 0);
  
  return n;
}


