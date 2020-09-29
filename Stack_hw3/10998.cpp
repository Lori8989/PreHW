#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "function.h"
using namespace std;


List_stack::List_stack(){
    this->head = this->tail =NULL;
}
List_stack::~List_stack(){}

void List_stack::push(const int &r){
    ListNode *nw = new ListNode(r);
    nw->prevPtr = this->tail;
    this->tail = nw;
}
void List_stack::pop(){
    if( this->tail == NULL )return;
    ListNode *tmp = this->tail;
    this->tail = this->tail->prevPtr;
    free(tmp);
}
void List_stack::print(){
    ListNode *cur = this->tail;
    while( cur != NULL ){
        if(cur->prevPtr == NULL){
            cout<<cur->data;
            break;
        }
        else{
            cout<<cur->data<<" ";
            cur = cur->prevPtr;
        }
    }
}
