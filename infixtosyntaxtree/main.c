#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "function.h"

#define MAXEXPR 256
#define NUMSYM 6
char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;//0~length
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        //printf("###d\n");
        freeTree(root);
    }

    return 0;
}

BTNode* EXPR() // parse an infix expression and generate a syntax tree
{
    BTNode *node = NULL, *right = NULL;
//(A&B)
    right = FACTOR();
    if( expr[pos] == '(' || pos < 0 ){
        pos--;
        //printf("oh\n");
        return right;
    }


    if( expr[pos] == sym[4] || expr[pos] == sym[5] ){
        node = makeNode(expr[pos]);
        node->right = right;
        pos--;
        node->left = EXPR();//printf("$$\n");
    }
    else
        node = right;

    return node;
}
BTNode* FACTOR()// use the parse grammar FACTOR = ID | (EXPR) to deal with parentheses
{
    BTNode* node = NULL;
    if( expr[pos] == ')' ){
        pos--;
        node = EXPR();
    }
    else{
        node = makeNode( expr[pos] );
        pos--;
    }
    return node;
}
BTNode* makeNode(char c)
{
    BTNode* nw = malloc(sizeof(BTNode));
    int i;
    for( i=0 ; i<6 ; i++ ){
        if( c == sym[i] ){
            nw->data=i;
            //printf("%c, pos = %d\n",sym[i],pos);
            break;
        }
    }
    if( i < 4 ){
        nw->left=NULL;
        nw->right=NULL;
    }

        //printf("%d\n",nw->data);
    return nw;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
    //printf("##print\n");
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
/*
A&B|C&D&A&B|C&D
A|(B&C)|D
(((A&B)))
A|B&C|A
*/
