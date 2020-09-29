//#include "function.h"
#include <iostream>
using namespace std;

class Char{
	friend class Str;
	private:
		Char(char text):next(NULL){
			this->text=text;
		}

		~Char(){
            if(next)
                delete next;
		}

		void print(){
            cout<<text;
            if(next)
                next->print();
		}

		char text;
		Char *next;
};

class Str{
	public:
		Str():head(NULL),tail(NULL){}
		Str(char*); // construct a new Str by linked list of Char
		Str(const Str &); // copy constructor
		~Str(){
            if(head)
                delete head;
		}

		Str& strInsert(const Str &);//-----------

		Str& strSwap(Str &s){
			Str *tmp=new Str(*this);
			this->~Str();

			*this=s;
            s=*tmp;

            tmp->head=NULL;
            delete tmp;
			return *this;
		}

		void strPrint(){
            if(head)
                head->print();
            cout<<endl;
		}

	private:
		Char *head;
		Char *tail;
};


Str::Str( char *input ):head(NULL),tail(NULL)
{
	int idx=0;
	if (input[idx] != '\0' )
	{
		Char *tmp = new Char(input[idx]);
		head = tmp;
		tail = tmp;
		idx++;
		while (input[idx] ! = '\0')
		{
			Char nw = Char(input[idx]);
			tail->next = nw;
			tail = nw;
			idx++;
		}
		
	}
	
}

Str::Str(const Str &cpy)
{
	head = new Char(cpy.head->text);
	tail = head;
	Char *tmp = cpy.head->next;

	while (tmp != NULL )
	{
		Char *nwc = new Char(tmp->text);
		tail->next = nwc;
		tail = nwc;
		tmp = tmp->next;
	}
	
}

Str& Str::strInsert(const Str &s)
{
	Str *tmp = new Str(s);
	this->tail->next = tmp;
	this->tail = tmp;

	return *this;
}



























Str::Str( char *input ):head(NULL),tail(NULL)
{
	int idx=0;
	if( input[idx] != '\0' ){
		Char *tmp = new Char(input[idx]);
		head = tmp;
		tail = tmp;
		idx++;

		while ( input[idx] != '\0' )
		{
			Char* nwchar = new Char(input[idx]);
			tail->next = nwchar;
			tail = nwchar;
			idx++;
		}
		
	}
}

Str::Str(const Str &cpy)
{
	head = new Char(cpy.head->text);
	tail = head;
	Char *tmp = cpy.head->next;
	while (tmp != NULL)
	{
		Char *nw_c = new Char(tmp->text);
		tail->next = nw_c;
		tail = nw_c;
		tmp = tmp->next;
	}
	
	
}

Str& Str::strInsert(const Str &s)
{
	Str *tmp = new Str(s);
	this->tail->next = tmp->head;
	this->tail = tmp->tail;

	return *this;
}





int main() {

	int N;
	char input[100];

	int index=0;
	Str *s[100];

	cin>>N;
    for(int i=0;i<N;i++){
    	cin>>input;
    	s[index++]=new Str(input);
    }

    char op[3];//"si" || "is" || "s" || "i" || "e"
    while(1){
    	cin>>op;
    	if(op[0]=='e')break;

    	int idx1,idx2;
    	cin>>idx1;
    	cin>>idx2;

    	Str &s1=*s[idx1];
    	Str &s2=*s[idx2];


        if(op[0]=='s'&&op[1]=='i'){
            s1.strSwap(s2).strInsert(s2);

        }else if(op[0]=='i'&&op[1]=='s'){
            s1.strInsert(s2).strSwap(s2);

        }else if(op[0]=='s'){
            s1.strSwap(s2);

        }else if(op[0]=='i'){
            s1.strInsert(s2);

        }
	}

	for(int i=0;i<N;i++){
        s[i]->strPrint();
        delete s[i];
	}

	return 0;
}


