#include<stdio.h>
#include<stdlib.h>
//#include "function.h"
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

extern Node* ReadOneList();
extern void PrintList(Node*);
extern void Merge(Node*, int, int);
extern void Cut(Node*, int, int);
int main(){
    Node* dummy_head;
    Node* tail;

    dummy_head = (Node*) malloc( sizeof(Node) );
    dummy_head->data = NULL;
    dummy_head->size = -1;

    tail = dummy_head;

    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        tail->next = ReadOneList();
        tail = tail->next;
    }
    char act[10];
    int x, y;
    for(int i=0; i<M; i++){
        scanf("%s %d %d", act, &x, &y);
        if( act[0] == 'M' ){
            Merge(dummy_head, x, y);
        }
        else{
            Cut(dummy_head, x, y);
        }
    }
    PrintList(dummy_head);
    return 0;
}


Node* CreateNode(int size){
    Node* n = (Node*) malloc( sizeof(Node) );
    n->size = size;
    n->data = (int*) malloc( sizeof(int) * size );
    n->next = NULL;
    return n;
}

Node* ReadOneList(){
    int Ni;
    scanf("%d:", &Ni );
    Node* new_node = CreateNode(Ni);
    for(int i=0; i<new_node->size; i++){
        scanf(" %d", &(new_node->data[i]) );
    }
    return new_node;
}

void PrintList(Node* dummy_head){
    Node* cur = dummy_head->next;
    while( cur != NULL ){
        printf("%d", cur->data[0]);
        for(int i=1; i<cur->size; i++){
            printf(" %d", cur->data[i]);
        }
        printf("\n");
        cur = cur->next;
    }
}
void Merge(Node* dummy_head, int last, int frt){
    Node* tailnode = dummy_head;
    Node* headnode = dummy_head;

    int i,j=0;
    for( i=0 ; i<last-1 ; i++ )
        tailnode = tailnode->next;

    Node* prevv = tailnode;
    tailnode = tailnode->next;

    //printf("tail = %d##\n",tailnode->size);
    for( i=0 ; i<frt ; i++ )
        headnode = headnode->next;

    int* arr = malloc( headnode->size*sizeof(int) + tailnode->size*sizeof(int) );
    //printf("head = %d##\n",headnode->size);

    for( i=0 ; i<headnode->size; i++ ){
        arr[i] = *((headnode->data)+i);
        //printf("h%d ",*((nwnode->data)+i));
    }
    for( i = headnode->size ; i< headnode->size + tailnode->size ;i++ ){
            //printf("#");
        arr[i] = *((tailnode->data)+j);//(new_node->data[i])
        //printf("t%d ,%d\n",*((nwnode->data)+i),*((tailnode->data)+j));
        j++;
    }

    headnode->data = arr;
    headnode->size = headnode->size + tailnode->size;
    prevv->next = tailnode->next;
    free(tailnode);
    return;

}
/*
2 1
3: 1 2 3
2:5 4
Merge 1 2
*/
void Cut(Node* dummy_head, int x, int idx){
    Node* prev_x = dummy_head;
    Node* list_x = dummy_head->next;
    while( --x ) list_x = list_x->next, prev_x = prev_x->next;

    int size_x1 = idx, size_x2 = list_x->size - size_x1;
    Node* list_x1 = CreateNode( size_x1 );
    Node* list_x2 = CreateNode( size_x2 );

    for(int i=0; i<list_x1->size; i++)
        list_x1->data[i] = list_x->data[i];
    for(int i=0; i<list_x2->size; i++)
        list_x2->data[i] = list_x->data[i + list_x1->size];

    prev_x->next = list_x1;
    list_x1->next = list_x2;
    list_x2->next = list_x->next;

    free(list_x->data);
    free(list_x);
}
