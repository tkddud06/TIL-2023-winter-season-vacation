/*
이 강좌를 읽기에 앞서 여태까지 배운 내용들을 복습할 겸 직접 자신만의 문자열 클래스를 만들어보기 바랍니다.그 문자열 클래스는 아래와 같은 내용들을 지원해야 합니다.

문자(char) 로 부터의 문자열 생성, C 문자열(char*) 로 부터의 생성

문자열 길이를 구하는 함수

문자열 뒤에 다른 문자열 붙이기

문자열 내에 포함되어 있는 문자열 구하기

문자열이 같은지 비교

문자열 크기 비교(사전 순)

*/

#include <iostream>

class String {
private:

	char* str;
	size_t len;

public:

	String(int input_len, char c); // 문자로부터의 문자열 생성자

	String(const char* str); // 문자열로부터의 문자열 생성자

	String(const String& string); // 복사 생성자

	~String(); // 소멸자

	size_t strlen() const; // 문자열 길이를 구하는 함수

	String& add_str(const String& other_string); // 문자열 붙이기

	bool involve_check(const String& other_string); // 문자열 포함여부 확인하기

	bool same_check(const String& other_string); // 문자열 같음 여부 확인하기

	int versus(const String& other_string); // 문자열 크기 비교(사전 순) 같으면 0, 앞에것이 더 빠르면(짧으면) -1, 아니면 1

	void print_str() const; // 문자열 출력하기


};

String::String(int input_len, char c) : len(input_len) // 문자로부터의 문자열 생성자
{
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = c;
	}
	str[len] = '\0';
}

String::String(const char* input_str) // 문자열로부터의 문자열 생성자
{
	len = std::strlen(input_str);
	str = new char[len + 1];
	// str = input_str; // "const char* 형식의 값을 char 엔터티에 할당할 수 없습니다. 오류 발생. 원래 안됐나?", 원래 안됐나를 떠나서, 이렇게 하면 동적할당한걸 못써먹게되서 하면 안되네.
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

String::~String() // 소멸자
{
	delete[] str;
}

size_t String::strlen() const// 문자열 길이를 구하는 함수
{
	return len;
}


String& String::add_str(const String& other_string) // 문자열 붙이기
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
		new_str[original_string_len + i] = other_string.str[i]; // !other_string.str로 바로 접근이 돼? 아, 멤버 함수를 타고 접근하는건 되는게 맞지.
	}
	new_str[len] = '\0';
	delete[] str;
	str = new_str;
	return *this;
}

bool String::involve_check(const String& other_string) // 문자열 포함여부 확인하기
{
	// 두가지 케이스. 1, this가 더 길거나, 같음. 2, other_string이 더 김.
	size_t other_string_len = other_string.strlen();
	if (other_string_len > this->len) // this가 짧은 경우
	{
		for (int i = 0; i < other_string_len; i++) // i는 베이스가 될 other_string의 인덱스를 나타냄.
		{
			if (this->str[0] == other_string.str[i]) // this의 첫번째와 일치하는 문자 발견
			{
				int involve_check = 0; // for문의 break여부 판독용 변수
				int copyed_i = i;
				for (int j = 0; j < this->len; j++, copyed_i++) // j는 this의 인덱스를 나타냄. copyed_i는 for문 내에서 베이스인 other_string의 인덱스에 조사 필요한 부분부터 접근하기 위한 변수
				{
					if (i >= other_string_len) // 베이스인 other_string을 이미 다 탐색한 경우 break 작동
					{
						involve_check = 1;
						break;
					}
					if (this->str[j] != other_string.str[copyed_i]) // 베이스와 this가 다를 경우, break작동.
					{
						involve_check = 1;
						break;
					}
				}
				if (involve_check == 0) // break가 작동되지 않고, 정상적으로 포함됨을 확인했을 경우
				{
					return true;
				}
				// break가 작동한 경우, 그 다음 인덱스부터 다시 탐색
			}
		}
		// 베이스를 모두 탐색했지만 성공 실패시
		return false;
	}
	else // this가 긴 경우. 변수가 반대로 되었다고 생각하면 됨.
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

bool String::same_check(const String& other_string) // 문자열 같음 여부 확인하기
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

int String::versus(const String& other_string) // 문자열 크기 비교(사전 순) 같으면 0, 앞에것이 더 빠르면(짧으면) -1, 아니면 1
{
	size_t other_string_len = other_string.strlen();
	if (other_string_len == this->len)
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->str[i] < other_string.str[i]) // 앞의것이 더 작으면(아스키코드상)
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
	else if (other_string_len > this->len) // 앞에것이 더 짧으면
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void String::print_str() const // 문자열 출력하기
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