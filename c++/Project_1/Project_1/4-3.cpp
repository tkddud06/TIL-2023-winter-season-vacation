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
	void print();
};

string::string(char c, int n) // ���� c�� n�� �ִ� ���ڿ��� ����
{
	len = n;
	str = new char[len+1]; // ������ null�� ���� +1
	for (int i = 0; i < len; i++) 
	{
		str[i] = c;
	}
	str[len] = '\0';
}

string::string(const char* s) // ���ڿ��� �ٷ� ����, std::strlen���
{
	len = std::strlen(s);
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = s[i];
	}
}

string::string(const string& s) // ���� ������
{
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = s.str[i];
	}
}

string::~string() // �Ҹ���
{
	delete[] str;
	std::cout << "�����Ϸ�" << std::endl;
}

void string::add_string(const string& s) // �ش� string �ڿ� string s�� �߰�
{
	string temp = s; // strlen�� ����ϱ� ���� �ļ�


	int original_string_len = len; //  ���� string�� ����
	int adding_string_len = temp.strlen();
	len += adding_string_len; // len = �߰��� string�� ���̸� ������ ����
	char* new_str = new char[len + 1];
	// ���� lenũ���� string a, Ÿ len2ũ���� string s
	// ���ο� len + len2 ������ string c(���� ���̴� '\0'�� ���� len + len2 + 1)�� a�� s�� ������ �̾ ����
	int i = 0;
	for (i; i < original_string_len; i++)
	{
		new_str[i] = str[i];
	}
	for (i = 0; i < adding_string_len; i++)
	{
		new_str[original_string_len + i] = s.str[i];
	}
	new_str[len] = '\0';
	delete[] str;
	str = new_str;
}

void string::copy_string(const string& s) // �ش� string�� string s�� ��ü
{
	string temp = s; // strlen�� ����ϱ� ���� �ļ�
	delete[] str;
	len = temp.strlen();
	str = new char[len + 1];
	// ���ο� str�� ���� �� ������ ������ �Է�
	int i = 0;
	for (i; i < len; i++)
	{
		str[i] = s.str[i];
	}
	str[len] = '\0';
}

int string::strlen() // len�� �����ϴ� �Լ�
{
	return len;
}

void string::print()
{
	std::cout << str << std::endl;
}

int main()
{
	string s("s");
	string c("");
	string b("reseting");
	s.print();
	s.add_string(c);
	s.print();
	s.copy_string(b);
	s.print();
	return 0;
}