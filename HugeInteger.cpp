#include<iostream>
#include<string.h>
using namespace std;

class HugeInteger
{
private:
	char integer_array[40];
public:
	HugeInteger()
	{
		for (int i = 0; i < 40; i++)
			integer_array[i] = '0';
	}

	friend istream &operator >>(istream&, HugeInteger&);
	friend ostream &operator <<(ostream&, HugeInteger);

	HugeInteger operator=(HugeInteger obj)
	{
		for (int i = 0; i < 40; i++)
			integer_array[i] = obj.integer_array[i];
		return *this;
	}

	HugeInteger operator=(int n)
	{
		int count = 0;
		int temp = n;
		for (int i = 0; ; i++)
		{
			temp = temp / 10;
			count++;
			if (temp <= 0)
				break;
		}

		double t=n;
		for (int i = 39; i>39-count; i--)
		{
			t= t / 10.0;
			temp = (t - (int)t)*10;
			integer_array[i] = temp+48;
		}
		return *this;
	}

	HugeInteger operator+(HugeInteger& obj)
	{
		HugeInteger sum;
		int carry = 0;
		for (int i = 39; i >= 0; i--)
		{
			int s =((int) obj.integer_array[i]-48) + ((int)integer_array[i]-48)+carry;
			sum.integer_array[i] = (s % 10) + 48;
			carry = s / 10;
		}
		return sum;
	}

	HugeInteger operator-(HugeInteger& obj)
	{
		HugeInteger ans;
		if (*this >= obj)
		{
			HugeInteger result; 
			for (int i = 39; i >= 0; i--)
				result.integer_array[i] = (9 - (obj.integer_array[i] - 48)) + 48;
			HugeInteger temp;
			temp = 1;
			result += temp;

			ans= *this + result;
			return ans;
		}
		else
		{
			cout << "\nCannot be Substracted\0";
			return ans;
		}
	}

	HugeInteger operator++()
	{
		HugeInteger temp;
		temp= 1;
	    
		*this = *this + temp;
		return *this;
	}

	HugeInteger operator++(int)
	{
		HugeInteger prev;
		prev= *this;

		HugeInteger temp;
		temp = 1;
		
		*this = *this + temp;
		return prev;
	}

	HugeInteger operator--()
	{
		HugeInteger temp;
		temp = 1;

		*this = *this - temp;
		return *this;
	}

	HugeInteger operator--(int)
	{
		HugeInteger prev;
		prev = *this;

		HugeInteger temp;
		temp = 1;

		*this = *this - temp;
		return prev;
	}

	HugeInteger operator+=(HugeInteger& obj)
	{
		*this = *this + obj;
		return *this;
	}

	HugeInteger operator-=(HugeInteger& obj)
	{
		*this = *this - obj;
		return *this;
	}

	char& operator[](int i)
	{
		return integer_array[i];
	}
	
	bool operator ==(HugeInteger& obj)
	{
		for (int i = 39; i >= 0; i--)
			if (this->integer_array[i] != obj.integer_array[i])
				return false;
		return true;
	}

	bool operator !=(HugeInteger& obj)
	{
		if (*this == obj)
			return false;
		return true;
	}

	bool operator>(HugeInteger& obj)
	{
		for (int i = 0; i < 40; i++)
		{
			if (integer_array[i] ==obj.integer_array[i])
				continue;
			else if (integer_array[i] > obj.integer_array[i])
				return true;
			else if (integer_array[i] < obj.integer_array[i])
				return false;
		 }
		return false;
	}

	bool operator<(HugeInteger& obj)
	{
		if (*this >= obj)
			return false;
		return true;
	}
	
	bool operator<=(HugeInteger& obj)
	{
		if (*this < obj || *this == obj)
			return true;
		return false;
	}

	bool operator>=(HugeInteger& obj)
	{
		if (*this > obj || *this == obj)
			return true;
		return false;
	}

};


istream& operator >>(istream& in, HugeInteger& obj)
{
	string s;
	in >> s;
	
	if (s.length()<40)
	{
		int size = 39 - s.length()+1;
		int index = 0;
		for (int i = size; i < 40; i++)
			obj.integer_array[i] = s[index++];
	}
	return in;
}
ostream& operator <<(ostream& out, HugeInteger obj)
{
	int start=0;
	for (int i = 0; i < 40; i++)
		if (obj.integer_array[i] != '0')
		{
			start = i;
			break;
		}
	if (start == 0)
		cout << '0';
	else
	    for (int i = start;i < 40; i++)
		    cout <<obj.integer_array[i];
	return out;
}


int main()
{
	HugeInteger obj1;
	HugeInteger obj2;

	for (int i = 0;; i++)
	{
		int n;
		cout << "Enter First Value: ";
		cin >> obj1;
		cout << "\nEnter Second Value: ";
		cin>>n;
		obj2 = n;
		
		cout << "\Arthemethic:\nobj1 + obj2 = " << obj1 + obj2;
		cout << "\nobj1 - obj2 = " << obj1 - obj2;
		
		cout << "\nIncrement:\nobj1++ = " << obj1++;
		cout << "\n++obj2 = " << ++obj2 << " became: " << obj2;
		cout << "\nDecrement:\nobj1-- =" << obj1--;
		cout << "\n--obj2 =" << --obj2 << " became: " << obj2;

		cout << "\nCompound Assignment:\nobj1+=obj2 = " << (obj1 += obj2);
		cout << "\nobj1-=obj2 = " << (obj1 -= obj2);


		cout << "\nRelational Operators:\n obj1==obj2 = ";
		if (obj1 == obj2)
			cout << "True";
		else
			cout << "False";

		cout<<"\n obj1 != obj2 =  ";
		if (obj1 != obj2)
			cout << "True";
		else
			cout << "False";

		cout << "\n obj1 > obj2 =  ";
		if (obj1 > obj2)
			cout << "True";
		else
			cout << "False";

		cout << "\n obj1 < obj2 =  ";
		if (obj1 < obj2)
			cout << "True";
		else
			cout << "False";

		cout << "\n obj1 > obj2 =  ";
		if (obj1 > obj2)
			cout << "True";
		else
			cout << "False";

		cout << "\n obj1 >= obj2 =  ";
		if (obj1 >= obj2)
			cout << "True";
		else
			cout << "False";

		cout << "\n obj1 <= obj2 =  ";
		if (obj1 <= obj2)
			cout << "True";
		else
			cout << "False";

		cout<<endl;
	}
	 

	//cout << --obj3<<endl;
//	cout << obj2--<<endl;
//	cout << obj2<<endl;
//	obj3 = 8888;
//	obj3 -= obj2;
//	cout << obj3;

	//if (obj1 >=obj2)
	//	cout << "\nTrue";
	//else
	//	cout << "\nFalse";

	//cout << "\nsubscript: "<<obj1[38]<<endl;
	//obj2[36] = '8';
	//cout << obj2;*/
	//   	 
}
