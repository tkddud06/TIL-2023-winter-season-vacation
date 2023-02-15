#include <iostream>


class String {
private:

	char* str;
	int length;

	friend String operator+(const String& a, const String& b);

	friend String operator*(int n, const String& b);

	friend String operator*(const String& b, int n);


public:


	String(const String& s) : length(s.length)
	{
		str = new char[length];
		for (int i = 0; i < s.length; i++)
		{
			str[i] = s.str[i];
		}
	}

	String(const char* s) : length(strlen(s))
	{
		str = new char[length];
		for (int i = 0; i < length; i++)
		{
			str[i] = s[i];
		}
	}

	~String()
	{
		delete[] str;
	}

	// 생성자, 소멸자들

	String& operator=(const String& s)
	{
		length = s.length;
		delete[] str;
		str = new char[length];
		for (int i = 0; i < s.length; i++)
		{
			str[i] = s.str[i];
		}
		return *this;
	}


	// 오퍼레이터
	

	void print();

};



String operator+(const String& a, const String& b)
{
	char* a_plus_b = new char[a.length + b.length];
	for (int i = 0; i < a.length; i++)
	{
		a_plus_b[i] = a.str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		a_plus_b[a.length + i] = b.str[i];
	}

	String temp(a_plus_b);
	return temp;
}

String operator*(int n, const String& b)
{
	char* n_gob_b = new char[b.length * n + 1];
	for (int i = 0; i < b.length * n; i++)
	{
		n_gob_b[i] = b.str[i % b.length];
	}
	n_gob_b[b.length * n + 1] = '\0';
	String temp(n_gob_b);
	return temp;
}

String operator*(const String& a, int n)
{
	char* n_gob_b = new char[a.length * n];
	for (int i = 0; i < a.length * n; i++)
	{
		n_gob_b[i] = a.str[i % a.length];
	}
	String temp(n_gob_b);
	return temp;
}

void String::print()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}

int main()
{
	String a = "hello";

	a.print();

	a = 3 * a;

	a.print();

	return 0;
}