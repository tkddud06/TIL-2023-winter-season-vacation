/*
�� ���¸� �б⿡ �ռ� ���±��� ��� ������� ������ �� ���� �ڽŸ��� ���ڿ� Ŭ������ ������ �ٶ��ϴ�.�� ���ڿ� Ŭ������ �Ʒ��� ���� ������� �����ؾ� �մϴ�.

����(char) �� ������ ���ڿ� ����, C ���ڿ�(char*) �� ������ ����

���ڿ� ���̸� ���ϴ� �Լ�

���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�

���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�

���ڿ��� ������ ��

���ڿ� ũ�� ��(���� ��)

*/

#include <iostream>

class String {
private:
	int len;
	char* str;

public:

	String(int len, char c); // ���ڷκ����� ���ڿ� ������

	String(const char* str); // ���ڿ��κ����� ���ڿ� ������

	~String(); // �Ҹ���

	int strlen() const; // ���ڿ� ���̸� ���ϴ� �Լ�

	String& add_str(const String other_string); // ���ڿ� ���̱�

	bool involve_check(const String other_string); // ���ڿ� ���Կ��� Ȯ���ϱ�

	bool same_check(const String other_string); // ���ڿ� ���� ���� Ȯ���ϱ�

	int versus(const String other_string); // ���ڿ� ũ�� ��(���� ��) ������ 0, �տ����� �� ������(ª����) -1, �ƴϸ� 1

	void print_str(); // ���ڿ� ����ϱ�


};

String::String(int len, char c) : len(len) // ���ڷκ����� ���ڿ� ������
{
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = c;
	}
	str[len] = '\0';
}

String::String(const char* input_str) // ���ڿ��κ����� ���ڿ� ������
{
	len = std::strlen(input_str);
	str = new char[len + 1];
	// str = input_str; // "const char* ������ ���� char ����Ƽ�� �Ҵ��� �� �����ϴ�. ���� �߻�. ���� �ȵƳ�?"
	for (int i = 0; i < len; i++)
	{
		str[i] = input_str[i];
	}
	str[len] = '\0';
}
String::~String() // �Ҹ���
{
	delete[] str;
}

int String::strlen() const// ���ڿ� ���̸� ���ϴ� �Լ�
{
	return len;
}


String& String::add_str(const String other_string) // ���ڿ� ���̱�
{
	
}

bool String::involve_check(const String other_string) // ���ڿ� ���Կ��� Ȯ���ϱ�
{

}

bool String::same_check(const String other_string) // ���ڿ� ���� ���� Ȯ���ϱ�
{

}

int String::versus(const String other_string) // ���ڿ� ũ�� ��(���� ��) ������ 0, �տ����� �� ������(ª����) -1, �ƴϸ� 1
{

}

void String::print_str() // ���ڿ� ����ϱ�
{

}

int main()
{
	String a(10, 'c');
	a.strlen();
	return 0;
}