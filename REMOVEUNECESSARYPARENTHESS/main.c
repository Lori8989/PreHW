#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[260];
int pos;

typedef struct _Node{
    char data;
    struct _Node *right, *left;
}Node;

Node* buildtree();
Node* factor();
Node* makenewnode(char);
void printout( Node* );
void freetree(Node*);

int main()
{
    scanf("%s",arr);
    pos = strlen(arr)-1;
    Node *root = buildtree();
    printout(root);

    return 0;
}

Node* buildtree()//A&B
{
    Node *right = NULL, *node = NULL;
    right = factor();

    if( arr[pos] == '(' || pos < 0 ){//printf("finish pos= %d\n",pos);
        pos--;
        return right;
    }

    if( arr[pos] == '&' || arr[pos] == '|' ){
        node = makenewnode(arr[pos]);//printf("op, pos= %d\n",pos);
        node->right = right;
        pos--;
        node->left = buildtree();
    }
    else
        node = right;



    return node;
}

Node* factor()
{
    Node *nw = NULL;//printf("factor, pos = %d\n",pos);
    if( arr[pos] == ')' ){
        pos--;
        nw = buildtree();
    }
    else{
        nw = makenewnode(arr[pos]);
        pos--;
    }

    return nw;
}

Node* makenewnode(char c)
{//printf("make, %c\n",c);
    Node *nw = malloc(sizeof(Node));
    nw->data = c;
    if(nw->data >= 'A'&& nw->data <= 'D'){
        nw->left = NULL;
        nw->right = NULL;
    }

    return nw;
}

void printout( Node* root)
{
    if(root == NULL)
        return;
//printf("yes\n");
    printout(root->left);
    printf("%c",root->data);

    if(root->right != NULL){
        if( root->right->data == '&' || root->right->data == '|' ){
            printf("(");
            printout(root->right);
            printf(")");
        }
        else {
            printout(root->right);//printf("e\n");
        }
    }

    return;
}

void freeTree(Node *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
