#include <iostream>
#include <math.h>
#include <string.h>
//#include "function.h"
using namespace std;
//Implement the constructor, insert(), search()
//member functions of both the Array_ BST and List_ BST classes
//and createLeaf(), deleteTree() of List_ BST class.


class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print() const = 0;
    int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

protected:
    int Height;
};

class Array_BST : public BST{
public:
    Array_BST();
    virtual ~Array_BST() {}
    virtual void insert(const int &) override; //root node is stored at index 1.
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int k = pow(2, height());
        for (int i = 1; i <= k-1; i++) {
            if (array[i] != 0)
                cout << array[i] << " ";
        }
    }

private:
    int array[1025];
};

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};//end class ListNode

class List_BST : public BST{
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() const override{
        int i;
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    /* clean a tree.*/
    void deleteTree(ListNode *root);

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == NULL)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
};


void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj1.insert(n);
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj1.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj1.height() << endl;;
        cout << bstobj2.height() << endl;;

    }else if (cmd == 'P'){
        bstobj1.print();
        cout << endl;
        bstobj2.print();
        cout << endl;
    }
}
/*
Array_BST::Array_BST():BST()
{
    for( int i=0 ;i<1025 ; i++ )
        array[i] =0;
}

void Array_BST::insert(const int& data)
{
    int count = 1, idx = 1;
    while( array[idx] != 0 ){
        if( data < array[idx] )
            idx = idx*2;
        else if( data > array[idx] )
            idx = idx*2+1;
        else
            return;
        count++;
    }
    array[idx]=data;

    if(count>Height)
        Height = count;
}


bool Array_BST::search(const int &data) const
{
    int idx = 1;
    while ( idx<1025 )
    {
        if( array[idx] == data )
            return true;
        else if( array[idx] < data )
            idx = idx*2+1;
        else
        {
            idx *= 2;
        }
        
    }
    return false;
}

List_BST::List_BST()
    :BST(),root(NULL){}


void List_BST::insert( const int &data)
{
    int count = 1;
    ListNode *nwnode = createLeaf(data);

    if( Height == 0 ) 
        root = nwnode;
    else
    {
        ListNode *tmp = root;
        while ( tmp != NULL )
        {
            if(data < tmp->key ){
                if( tmp->left == NULL ){
                    tmp->left = nwnode;
                    count++;
                    break;
                }
                else
                    tmp = tmp->left;
            }
            else if( data > tmp->key ){
                if( tmp->right == NULL ){
                    tmp->right = nwnode;
                    count++;
                    break;
                }
                tmp = tmp->right;
            }
            else
            {
                return;
            }
            count++;
        }

        
    }
    if( count > Height )
        Height = count;
}

bool List_BST::search(const int& data )const
{
    ListNode *cur = root;
    while ( cur != NULL )
    {
        if( data == cur->key )
            return true;
        else if( data > cur->key )
            cur = cur->right;
        else
            cur = cur->left;
        
    }
    return false;
    
}

ListNode* List_BST::createLeaf(int key)const
{
    ListNode *nw = new ListNode(key);
    return nw;
}

void List_BST::deleteTree( ListNode *root )
{
    if(root == NULL)
        return;
    else{
        deleteTree( root->left );
        deleteTree( root->right );
        delete root;
        return;
    }    
}


*/




void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    
}


bool Array_BST::search(const int &data) const
{
    
}

List_BST::List_BST()
    :BST(),root(NULL){}


void List_BST::insert( const int &data)
{
    
}

bool List_BST::search(const int& data )const
{
    
    
}

ListNode* List_BST::createLeaf(int key)const
{
    
}

void List_BST::deleteTree( ListNode *root )
{
      
}



int main(){
    Array_BST A_bst;
    List_BST B_bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(A_bst, B_bst, cmd);

    return 0;
}
