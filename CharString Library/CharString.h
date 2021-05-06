#include<iostream>
#include<string>
using namespace std;

struct CharString
{
private:
	char* cstr;
	int size;
public:
	void reset();
	CharString();
	CharString(char* src);
	CharString(const CharString&);
	CharString(string src);
	void print();
	int getSize();
	void clear();
	void operator =(char* src);
	void copyFrom(char* , int n, int start = 0);
	void operator =(string );
	void copyFrom(string , int , int start = 0);
	void operator =(const CharString );
	void copyFrom(const CharString , int , int start = 0);
	void concat(char* str);
	void concat(string );
	void concat(CharString&) ;
	CharString operator +(char* s);
	CharString operator +(string );
	CharString operator +(CharString );
	bool operator ==(char* str);
	bool operator ==(string );
	bool operator ==(CharString );
	CharString Reverse();
	CharString Substring(int , int );
	char At(int );
	~CharString();
}; 
