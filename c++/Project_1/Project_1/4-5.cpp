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

	char* str;
	size_t len;

public:

	String(int input_len, char c); // ���ڷκ����� ���ڿ� ������

	String(const char* str); // ���ڿ��κ����� ���ڿ� ������

	String(const String& string); // ���� ������

	~String(); // �Ҹ���

	size_t strlen() const; // ���ڿ� ���̸� ���ϴ� �Լ�

	String& add_str(const String& other_string); // ���ڿ� ���̱�

	bool involve_check(const String& other_string); // ���ڿ� ���Կ��� Ȯ���ϱ�

	bool same_check(const String& other_string); // ���ڿ� ���� ���� Ȯ���ϱ�

	int versus(const String& other_string); // ���ڿ� ũ�� ��(���� ��) ������ 0, �տ����� �� ������(ª����) -1, �ƴϸ� 1

	void print_str() const; // ���ڿ� ����ϱ�


};

String::String(int input_len, char c) : len(input_len) // ���ڷκ����� ���ڿ� ������
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
	// str = input_str; // "const char* ������ ���� char ����Ƽ�� �Ҵ��� �� �����ϴ�. ���� �߻�. ���� �ȵƳ�?", ���� �ȵƳ��� ������, �̷��� �ϸ� �����Ҵ��Ѱ� ����԰ԵǼ� �ϸ� �ȵǳ�.
	for (int i = 0; i < len; i++)
	{
		str[i] = input_str[i];
	}
	str[len] = '\0';
}

String::String(const String& string) : len(string.len)
{
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = string.str[i];
	}
	str[len] = '\0';
}

String::~String() // �Ҹ���
{
	delete[] str;
}

size_t String::strlen() const// ���ڿ� ���̸� ���ϴ� �Լ�
{
	return len;
}


String& String::add_str(const String& other_string) // ���ڿ� ���̱�
{
	size_t other_string_len = other_string.strlen();
	size_t original_string_len = len;
	len = other_string_len + original_string_len;
	char* new_str = new char[len + 1];
	for (int i = 0; i < original_string_len; i++)
	{
		new_str[i] = str[i];
	}
	for (int i = 0; i < other_string_len; i++)
	{
		new_str[original_string_len + i] = other_string.str[i]; // !other_string.str�� �ٷ� ������ ��? ��, ��� �Լ��� Ÿ�� �����ϴ°� �Ǵ°� ����.
	}
	new_str[len] = '\0';
	delete[] str;
	str = new_str;
	return *this;
}

bool String::involve_check(const String& other_string) // ���ڿ� ���Կ��� Ȯ���ϱ�
{
	// �ΰ��� ���̽�. 1, this�� �� ��ų�, ����. 2, other_string�� �� ��.
	size_t other_string_len = other_string.strlen();
	if (other_string_len > this->len) // this�� ª�� ���
	{
		for (int i = 0; i < other_string_len; i++) // i�� ���̽��� �� other_string�� �ε����� ��Ÿ��.
		{
			if (this->str[0] == other_string.str[i]) // this�� ù��°�� ��ġ�ϴ� ���� �߰�
			{
				int involve_check = 0; // for���� break���� �ǵ��� ����
				int copyed_i = i;
				for (int j = 0; j < this->len; j++, copyed_i++) // j�� this�� �ε����� ��Ÿ��. copyed_i�� for�� ������ ���̽��� other_string�� �ε����� ���� �ʿ��� �κк��� �����ϱ� ���� ����
				{
					if (i >= other_string_len) // ���̽��� other_string�� �̹� �� Ž���� ��� break �۵�
					{
						involve_check = 1;
						break;
					}
					if (this->str[j] != other_string.str[copyed_i]) // ���̽��� this�� �ٸ� ���, break�۵�.
					{
						involve_check = 1;
						break;
					}
				}
				if (involve_check == 0) // break�� �۵����� �ʰ�, ���������� ���Ե��� Ȯ������ ���
				{
					return true;
				}
				// break�� �۵��� ���, �� ���� �ε������� �ٽ� Ž��
			}
		}
		// ���̽��� ��� Ž�������� ���� ���н�
		return false;
	}
	else // this�� �� ���. ������ �ݴ�� �Ǿ��ٰ� �����ϸ� ��.
	{
		for (int i = 0; i < len; i++) 
		{
			if (this->str[i] == other_string.str[0]) 
			{
				int involve_check = 0; 
				int copyed_i = i;
				for (int j = 0; j < other_string_len; j++, copyed_i++)
				{
					if (i >= len)
					{
						involve_check = 1;
						break;
					}
					if (this->str[copyed_i] != other_string.str[j])
					{
						involve_check = 1;
						break;
					}
				}
				if (involve_check == 0)
				{
					return true;
				}
			}
		}
		return false;
	}
}

bool String::same_check(const String& other_string) // ���ڿ� ���� ���� Ȯ���ϱ�
{
	if (other_string.strlen() != this->len)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->str[i] != other_string.str[i])
			{
				return false;
			}
		}
		return true;
	}
}

int String::versus(const String& other_string) // ���ڿ� ũ�� ��(���� ��) ������ 0, �տ����� �� ������(ª����) -1, �ƴϸ� 1
{
	size_t other_string_len = other_string.strlen();
	if (other_string_len == this->len)
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->str[i] < other_string.str[i]) // ���ǰ��� �� ������(�ƽ�Ű�ڵ��)
			{
				return -1;
			}
			else if (this->str[i] > other_string.str[i])
			{
				return 1;
			}
		}

		return 0;

	}
	else if (other_string_len > this->len) // �տ����� �� ª����
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void String::print_str() const // ���ڿ� ����ϱ�
{
	std::cout << str << std::endl;
}

int main()
{
	String a("nice");
	String b("hello");
	String p(10, 'c');
	String z("heflo");
	a.add_str(b);
	bool d = a.same_check(b);
	bool s = a.involve_check(b);
	size_t c = a.strlen();
	int f = a.versus(b);
	a.print_str();
	b.print_str();
	bool m = b.same_check(z);
	int q = b.versus(z);
	return 0;
}