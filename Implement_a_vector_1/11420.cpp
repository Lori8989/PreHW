#include<iostream>
#include<string>
#include"function.h"

using namespace std;
using namespace oj;

void Vector::pop_back()
{
	if(size()>0)last_--;
}

void Vector::push_back(value_type val)
{
	if( size() >= capacity() ){
		size_type new_capacity = ( capacity()+1 > capacity()*3 ) ? capacity()+1 : capacity()*3;
		reserve(new_capacity);	
	}
	*last_ = val;
	last_++;
}

void Vector::reserve( size_type nwcapy )
{
	if(capacity() < nwcapy ){
		pointer new_begin = new value_type[nwcapy];
		for( Int i=0 ; i<size() ; i++ )
			new_begin[i] = begin_[i];

		size_type the_size = size();
		size_type the_capacity = capacity();
		delete[] begin_;
		begin_ = new_begin;
		last_ = begin_ + the_size;
		end_ = begin_ + nwcapy;
	
	}
}

Vector::~Vector()
{
	delete[] begin_;
}



namespace oj
{
	Int::Int()
		:val(0){}	//set val as 0
	
	Int::Int(const int val_)
		:val(val_){}
	
	Int::Int(const Int &rhs)
		:val(rhs.val){}	//copy from rhs.val

	Int& Int::operator=(const Int &rhs)
	{
		val=rhs.val;	//copy from rhs.val
		return *this;
	}

	Vector::Vector()
		:begin_(NULL),end_(NULL),last_(NULL){}

	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(std::size_t i(0);i!=vec.size();++i)
			os<<vec[i]<<' ';
		return os;
	}
}

int main()
{
	using namespace std;
	{
		oj::Vector v;
		string command;

		for(oj::data_t n;cin>>command;)
		{
			if(command=="pop_back")
			{
				v.pop_back();
				cout<<v<<endl;
			}
			else if(command=="push_back")
			{
				cin>>n;
				v.push_back(n);
				cout<<v<<endl;
			}
			else if(command=="capacity")
				cout<<v.capacity()<<endl;
			else if(command=="size")
				cout<<v.size()<<endl;
			else if(command=="reserve")
			{
				cin>>n;
				v.reserve(n);
				cout<<v<<endl;
			}
		}
		cout<<v<<endl;
	}
	oj::memory_leak_count_check();	//you don't have to pay attention on this
#ifdef ONLINE_JUDGE
	nthuoj_unlock();
#endif
}

namespace oj
{
	Memory_leak_count::Memory_leak_count()
	{
		++count_;	//memory request + 1
	}

	Memory_leak_count::~Memory_leak_count()
	{
		--count_;	//memory request - 1
	}

	unsigned Memory_leak_count::count_(0);

	void memory_leak_count_check()
	{
		if(Memory_leak_count::count_!=0)	//memory leak if count_ is not equal to 0
			std::cout<<"memory leak"<<std::endl;
	}
}