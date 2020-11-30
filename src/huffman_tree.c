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

unsigned int get_freq(FILE *f, unsigned int charArray[]) {

	// Adds all characters in the file to an array
	// c is the temp storage for the char found
	// numChar is the number of all the chars in the file
	int c, numChar;

	// numChar counts the characters
	for (numChar = 0;; numChar++) {

		// get the next char in the file
		c = fgetc(f);

		// stop if eof is reached
		if (feof(f)) {
			break;
		}

		// Add the character found
		charArray[c]++;
	}
	return numChar;
}

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


int target_bits, cur_bytes, target_bytes; //global variables
void output_bits (FILE *f, char d) { 
    cur_bytes<<=1;
    if (d=='1') cur_bytes|=1;
    target_bits++;
    if (target_bits==8) {
        fputc (cur_bytes, f);
        target_bytes++;
        target_bits=0;
        cur_bytes=0;
    }
}

void f_encode (FILE *infile, FILE *outfile, char *z[]) {
    unsigned char ch;
    char *h;
    target_bits=0;
    cur_bytes=0;
    target_bytes=0;
    for (;;) {
        ch = fgetc (infile);
        if (feof (infile)) break;
        for (h=z[ch]; *h; h++) output_bits (outfile,*h);
    }
    while (target_bits) output_bits (outfile,'0');
}
