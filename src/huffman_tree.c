#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define NUM_CHARS 256
int num,frq[NUM_CHARS],bits[20];
typedef struct node{
  char ch;
  int frq;
  struct node *left, *right;
} node;

node *nodes[256],*HTree;

void buildHuffmanTree(void){
    node *new;
    int a,b,min,temp;

    for(a=0,num=0;a<NUM_CHARS;a++){
        if(frq[a]){
            nodes[num] = (node*)malloc(sizeof(node));
            nodes[num]->ch=a;
            nodes[num]->frq=frq[a];
            nodes[num]->left=NULL;
            nodes[num]->right=NULL;
            num++;
        }
    }
    temp=num-1;
    for(a=0;a<temp;a++){
        new=(node*)malloc(sizeof(node));
        min=0;
        for(b=1;b<num;b++)
            if(nodes[a]->frq < nodes[min]->frq)
                min=b;
        new->right = nodes[min];
        nodes[min] = nodes[--num];
        min=0;
        for(b=1; b<num;b++)
            if(nodes[b]->frq < nodes[min]->frq)
                min=b; 
        new->left=nodes[min];
        nodes[min]=nodes[--num];
        new->frq=new->left->frq+new->right->frq;
        nodes[num++]=new;
    }
    HTree=nodes[0];
}

void traverseTheTree(node *t, int height){
    int a;

    if(t->left == NULL && t->right){
        print("%c\t",t->ch);
        for (a=0;a<height;a++)
            print("%1d",bits[a]);
        printf("\n");
        return;
    }
    if ( t->left !=  NULL){
        bits[height]=0;
        traverseTheTree(t->left,height+1);
    }
    if ( t->right !=  NULL){
        bits[height]=1;
        traverseTheTree(t->left,height+1);
    }
}

