/*

#include <iostream>

class test
{
private:
	int a;

public:
	test()
	{
		a = 3;
		std::cout << "����" << std::endl;
	}

	~test()
	{
		std::cout << "����" << std::endl;
	}
};

int main()
{
	test b;
	test* a;
	a = new test;
	delete a;
	return 0;
} // new, delete�� ����� �Լ� �Ⱦ��� ���� �ڵ����� �� �ǰ�,
// ���������� test �����ϸ� �ڵ����� ���� ���� ��. �Ҹ��ڵ� ����ǰ�.

*/

#include <iostream>

class string {
private:
	char* str;
	int len;

public:
	string(char c, int n); // ���� c�� n�� �ִ� ���ڿ��� ����
	string(const char* s); // �Ƹ� ���ڿ��� �ٷ� ����, strlen��� �ʿ��� ��
	string(const string& s); // ���� ������
	~string(); // delete str �䱸�� ��


	void add_string(const string& s); // str�ڿ� s�� ���δ�.
	void copy_string(const string& s); // str �� s�� �����Ѵ�.
	int strlen(); // ���ڿ� ���� ����
};

string::string(char c, int n)
{
	len = n;
	str = new char[len+1]; // null�� ���� +1
	for (int i = 0; i < len; i++) 
	{
		str[i] = c;
	}
	str[len] = '\0';
}

string::string(const char* s)
{
	len = std::strlen(s) +1;
	str = new char[len];
	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}
}

string::string(const string& s)
{
	len = s.len;
	str = new char[len];
	for (int i = 0; i < len; i++)
	{
		str[i] = s.str[i];
	}
}

string::~string()
{
	delete[] str;
}

void string::add_string(const string& s)
{

}

void string::copy_string(const string& s)
{
	len = s.strlen() + 1;
	str = new char[len];
	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}
}

int string::strlen()
{
	return len;
}



int main()
{


	return 0;
}