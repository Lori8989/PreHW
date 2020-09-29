#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
//#include"function.h"

#include<cstddef>
using namespace oj




namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string&);
		String(const String&);
		String& operator=(const String&);
	};

	std::ostream& operator<<(std::ostream&, const String&);

	void insert(std::map<int, String>& ma, int key, const std::string& str);
	void output(const std::map<int, String>& ma, int begin, int end);
	void erase(std::map<int, String>& ma, int begin, int end);

	std::ostream& operator<<(std::ostream&, const std::map<int, String>&);
}








namespace oj
{

	std::ostream& operator<<(std::ostream&, const String&);

	//inserts a string (cmd) with the key (key) to map.
	//If the key has already existed, insert the cmd at the
	// begin of string (the string which the key belongs).
	void insert(std::map<int, String>& ma, int key, const std::string& str)
	{
		ma.insert({ key, str });
	}
	//outputs the string from key (first) to key (last).
	//Output a space character (' ') after printing an element
	void output(const std::map<int, String>& ma, int begin, int end)
	{

	}
	//erase the string from key (first) to key (last)
	void erase(std::map<int, String>& ma, int begin, int end) {}

	//outputs all strings in map. From the smallest key to
	//biggest key. Output a space character (' ') after printing an element.
	std::ostream& operator<<(std::ostream&, const std::map<int, String>&) {}
}





namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string &);
		String(const String &);
		String& operator=(const String &);
	};

	std::ostream& operator<<(std::ostream &,const String &);

	//inserts a string (cmd) with the key (key) to map.
	//If the key has already existed, insert the cmd at the
	// begin of string (the string which the key belongs).
	void insert(std::map<int,String> &ma,int key,const std::string &str);
	//outputs the string from key (first) to key (last).
	//Output a space character (' ') after printing an element
	void output(const std::map<int,String> &ma,int begin,int end);
	//erase the string from key (first) to key (last)
	void erase(std::map<int,String> &ma,int begin,int end);

    //outputs all strings in map. From the smallest key to
    //biggest key. Output a space character (' ') after printing an element.
	std::ostream& operator<<(std::ostream &,const std::map<int,String> &);
}



namespace oj
{
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}
}

int main()
{
	using namespace std;
	using namespace oj;
	map<int,String> ma;
	for(string cmd;cin>>cmd;)
	{
		if(cmd=="insert")
		{
			int key;
			cin>>key>>cmd;
			insert(ma,key,cmd);
		}
		else
			if(cmd=="range")
			{
				int begin,end;
				cin>>cmd>>begin>>end;
				if(cmd=="output")
					output(ma,begin,end);
				else
					if(cmd=="erase")
						erase(ma,begin,end);
					else
						assert(false);
			}
			else
				assert(false);
		cout<<ma<<endl;
	}
}
