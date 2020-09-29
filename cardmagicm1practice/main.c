#include<stdio.h>
#include<stdlib.h>
//#include "function.h"

typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList();
void PrintList(Node*);
void Merge(Node*, int, int);
void Cut(Node*, int, int);


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

Node* ReadOneList(){
    Node *node = malloc(sizeof(Node));
    scanf("%d: ",&node->size);
    node->data = malloc(node->size*sizeof(int));
    node->next = NULL;

    for(int i=0 ; i<node->size ; i++ )
        scanf("%d ",&(node->data[i]) );

    return node;
}
void PrintList(Node* node)//the head
{//printf("#");
    Node *cur = node->next;
    while( cur != NULL ){
        printf("%d",*(cur->data));
        for(int i=1 ; i<cur->size ; i++ ){
            printf(" %d",cur->data[i]);
        }
        printf("\n");
        cur = cur->next;
    }
}
void Merge(Node* head, int tailidx, int frtidx)
{
    Node *frt , *tail, *ffrt;
    frt = head;
    tail = head;//printf("head size %d\n",head->size);
    int i;

    for( i=0 ; i+1<tailidx ; i++ )
        tail = tail->next;
    ffrt = tail;
    tail = tail->next;
//printf("tail size %d\n",tail->size);

    for( i=0 ; i<frtidx ; i++ )
        frt = frt->next;
//printf("frt size %d\n",frt->size);
    int *arr = malloc( frt->size*sizeof(int) + tail->size*sizeof(int) );

    for( i=0 ; i<frt->size ; i++ )
        arr[i] = *((frt->data)+i);
    for(int j=0 ; j<tail->size ; j++ ){
        arr[i] = *((tail->data)+j);
        i++;
    }

    frt->data = arr;
    frt->size = i;

    ffrt->next = tail->next;
    free(tail);

}
void Cut(Node* head, int orig, int leftnum)
{
    Node *cur = head;
    //printf("head size %d\n",head->size);
    Node *nw1, *nw2, *pre;//1 is the remain one
    //orig--;
    while(--orig)
        cur = cur->next;
    pre = cur;
    cur = cur->next;
    if( cur->size < 2 )return;
    int nwsize = cur->size - leftnum;
        //printf("cur size %d, new size %d, left size %d\n",cur->size,nwsize,leftnum);

    nw1 = malloc(sizeof(Node));
    nw2 = malloc(sizeof(Node));

    nw1->data = malloc( leftnum*sizeof(int) );
    nw2->data = malloc( nwsize*sizeof(int) );
    int i;

    for( i=0 ; i<leftnum ; i++ )
        *((nw1->data)+i) = *((cur->data)+i);
    for(int j=0 ; j<nwsize ; j++ ){
        *((nw2->data)+j) = *((cur->data)+i);
        i++;
//printf("@\n");
    }
    nw1->size = leftnum;
    nw2->size = nwsize;
    pre->next = nw1;
    nw1->next = nw2;
    nw2->next = cur->next;
    free(cur->data);
    free(cur);
}
/*
5 2
2:1 2
3:4 5 6
3:1 2 3
1:4
4:1 2 6 7
Cut 3 1
Cut 2 2

5 2
2:1 2
3:4 5 6
3:1 2 3
1:4
4:1 2 6 7
Merge 4 1
Merge 2 3
*/
