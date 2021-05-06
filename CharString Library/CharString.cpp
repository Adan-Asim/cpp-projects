#include"CharString.h"

void CharString::reset()
{
	clear();
}

CharString::CharString()
{
	cstr = NULL;
	cstr = '\0';
	size = 0;
}

CharString::CharString(char* src)
{
	size = 0;
	for (int i = 0; src[i] != '\0'; i++)
		size++;
	cstr = new char[size + 1];

	for (int i = 0; i < size; i++)
		cstr[i] = src[i];
	cstr[size] = '\0';
}

CharString::CharString(const CharString& src)
{
	size = src.size;
	cstr = new char[size + 1];
	for (int i = 0; i < size; i++)
		cstr[i] = src.cstr[i];
	cstr[size] = '\0';
}

CharString::CharString(string src)
{
	size = src.length();
	cstr = new char[size + 1];

	for (int i = 0; i < size; i++)
		cstr[i] = src[i];
	cstr[size] = '\0';
}

void CharString::print()
{
	cout << cstr;
}

int CharString::getSize()
{
	return size;
}

void CharString::clear()
{
	if (cstr != NULL)
	{
		delete[] cstr;
		cstr = NULL;
	}
	cstr = '\0';
	size = 0;
}

void CharString::operator =(char* src)
{
	reset();
	for (int i = 0; src[i] != '\0'; i++)
		size++;
	cstr = new char[size + 1];

	for (int i = 0; i < size; i++)
		cstr[i] = src[i];
	cstr[size] = '\0';
}

void CharString::copyFrom(char* src, int n, int start )
{
	reset();
	for (int i = start; i < (start + n); i++)
	{
		if (src[i] == '\0')
			break;
		size++;
	}
	int index = 0;
	cstr = new char[size + 1];
	for (int i = start; i < (start + n); i++)
	{
		if (src[i] == '\0')
			break;
		cstr[index++] = src[i];
	}
	cstr[size] = '\0';
}

void CharString::operator =(string src)
{
	reset();
	size = src.length();
	cstr = new char[size + 1];

	for (int i = 0; i < size; i++)
		cstr[i] = src[i];
	cstr[size] = '\0';
}

void CharString::copyFrom(string src, int n, int start )
{
	reset();
	for (int i = start; i < (start + n); i++)
	{
		if (src[i] == '\0')
			break;
		size++;
	}

	int index = 0;
	cstr = new char[size + 1];
	for (int i = start; i < (start + n); i++)
	{
		if (src[i] == '\0')
			break;
		cstr[index++] = src[i];
	}
	cstr[size] = '\0';
}

void CharString::operator =(const CharString src)
{
	reset();
	size = src.size;
	cstr = new char[size + 1];
	for (int i = 0; i < size; i++)
		cstr[i] = src.cstr[i];
	cstr[size] = '\0';
}

void CharString::copyFrom(const CharString src, int n, int start )
{
	reset();
	for (int i = start; i < (start + n); i++)
	{
		if (src.cstr[i] == '\0')
			break;
		size++;
	}

	int index = 0;
	cstr = new char[size + 1];
	for (int i = start; i < (start + n); i++)
	{
		if (src.cstr[i] == '\0')
			break;
		cstr[index++] = src.cstr[i];
	}
	cstr[size] = '\0';
}

void CharString::concat(char* str)
{
	int tsize = size + 1;
	char* temp = new char[tsize];
	for (int i = 0; i <= size; i++)
		temp[i] = cstr[i];
	reset();

	int index = 0;
	cstr = new char[strlen(str) + tsize];
	for (int i = 0; i < tsize - 1; i++)
		cstr[index++] = temp[i];
	for (int i = 0; i < strlen(str); i++)
		cstr[index++] = str[i];
	cstr[index] = '\0';

	size = index;
	if (temp != NULL)
		delete[] temp;
}

void CharString::concat(string str)
{
	int tsize = size + 1;
	char* temp = new char[tsize];
	for (int i = 0; i <= size; i++)
		temp[i] = cstr[i];
	reset();

	int index = 0;
	cstr = new char[str.length() + tsize];
	for (int i = 0; i < tsize - 1; i++)
		cstr[index++] = temp[i];
	for (int i = 0; i < str.length(); i++)
		cstr[index++] = str[i];
	cstr[index] = '\0';

	size = index;
	if (temp != NULL)
		delete[] temp;
}

void CharString::concat(CharString& str)
{
	int tsize = size + 1;
	char* temp = new char[tsize];
	for (int i = 0; i <= size; i++)
		temp[i] = cstr[i];
	reset();

	int index = 0;
	cstr = new char[str.size + tsize];
	for (int i = 0; i < tsize - 1; i++)
		cstr[index++] = temp[i];
	for (int i = 0; i < str.size; i++)
		cstr[index++] = str.cstr[i];
	cstr[index] = '\0';

	size = index;
	if (temp != NULL)
		delete[] temp;
}

CharString CharString::operator +(char* s)
{
	CharString temp(*this);
	temp.concat(s);
	return temp;
}

CharString CharString::operator +(string s)
{
	CharString temp(*this);
	temp.concat(s);
	return temp;
}

CharString CharString::operator +(CharString s)
{
	CharString temp(*this);
	temp.concat(s);
	return temp;
}

bool CharString::operator ==(char* str)
{
	if (size == strlen(str))
	{
		for (int i = 0; i < size; i++)
			if (cstr[i] != str[i])
				return false;
		return true;
	}
	return false;
}

bool CharString::operator ==(string str)
{
	if (size == str.length())
	{
		for (int i = 0; i < size; i++)
			if (cstr[i] != str[i])
				return false;
		return true;
	}
	return false;
}

bool CharString::operator ==(CharString str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size; i++)
			if (cstr[i] != str.cstr[i])
				return false;
		return true;
	}
	return false;
}

CharString CharString::Reverse()
{
	string reversed = " ";
	for (int i = size - 1; i >= 0; i--)
		reversed = reversed + cstr[i];
	CharString temp(reversed);
	return temp;
}

CharString CharString::Substring(int start, int n)
{
	CharString temp;
	temp.copyFrom(*this, n, start);
	return temp;
}

char CharString::At(int i)
{
	if (i < size)
		return cstr[i];
	else
		return '\0';
}

CharString::~CharString()
{
	if (cstr != NULL)
		delete[]cstr;
}