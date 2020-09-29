// Author: justin0u0 <justin0u0@gapp.nthu.edu.tw>
#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

// Example of creating new Node
// Node *newNode = createNode(1);

struct Node {
	const int val;
	struct Node *prevPtr;
	struct Node *nextPtr;
};
typedef struct Node Node;

/* The below function is already implement above the main function */
Node *createNode(int val);
/* You need to implement the following functions, good luck! */
Node *buildDoublyCircularLinkedList(int n);
Node *getNextPersonOut(int peopleLeft, int m, Node *startNode);
void connectNodes(Node *personInFront, Node *personInBack);
void swapNodes(Node *personInFront, Node *personInBack);


int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	/* Build a circlular linked list from 1 ~ N */
	Node *node = buildDoublyCircularLinkedList(n);

	/* Start N-1 rounds process */
	for (int i = n; i > 1; i--) {
		int peopleLeft = i;
		// 1. Get the node that will get out of the circle this round
		Node *nextPersonOut = getNextPersonOut(peopleLeft, m, node);
		// 2. Get it's neighbors, remove the person out of the circle (free the node)
		Node *personInFront = nextPersonOut->prevPtr;
		Node *personInBack = nextPersonOut->nextPtr;
		free(nextPersonOut);
		// 3. Build connection between 'personInFront' and 'personInBack'
		connectNodes(personInFront, personInBack);
		// 3. Swap the neighbors' position
		if (peopleLeft > 3)
            swapNodes(personInFront, personInBack);
		// 4. Get the smaller value node
		if (personInFront->val < personInBack->val)
			node = personInFront;
		else
			node = personInBack;
	}

	// Output the value of the last person
	printf("%d\n", node->val);
	return 0;
}

Node *createNode(int val) {
	Node newNodeInst = {
		.val = val,
		.prevPtr = NULL,
		.nextPtr = NULL
	};
	Node *newNode = (Node *)malloc(sizeof(Node));
	memcpy(newNode, &newNodeInst, sizeof(newNodeInst));
	return newNode;
}

Node *buildDoublyCircularLinkedList(int n)
{
    Node* head = createNode(1);
    Node* cur = head;
    for( int i=2; i<=n; i++ ){
        Node* nw = createNode(i);
        nw->prevPtr = cur;
        cur->nextPtr = nw;
        cur = nw;
    }
    cur->nextPtr = head;
    head->prevPtr = cur;

    return head;
}
Node *getNextPersonOut(int peopleLeft, int step, Node *startNode)
{
    if( step > 21000 )
        step=step%peopleLeft;
    if(peopleLeft==1)
        return startNode;
    Node* cur = startNode;
    while( --step ){
        cur=cur->nextPtr;
    }
    //printf("left %d, start %d, get %d\n",peopleLeft,startNode->val,cur->val);

    return cur;
}
void connectNodes(Node *personInFront, Node *personInBack)
{
    personInFront->nextPtr = personInBack;
    personInBack->prevPtr = personInFront;
}
void swapNodes(Node *personInFront, Node *personInBack)
{
    personInFront->prevPtr->nextPtr = personInBack;
    personInBack->nextPtr->prevPtr = personInFront;
    personInFront->nextPtr = personInBack->nextPtr;
    personInBack->prevPtr = personInFront->prevPtr;
    personInBack->nextPtr = personInFront;
    personInFront->prevPtr = personInBack;
}
