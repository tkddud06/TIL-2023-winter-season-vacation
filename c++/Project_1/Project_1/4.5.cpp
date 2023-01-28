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
	int len;
	char* str;

public:

	String(int len, char c); // 문자로부터의 문자열 생성자

	String(const char* str); // 문자열로부터의 문자열 생성자

	~String(); // 소멸자

	int strlen() const; // 문자열 길이를 구하는 함수

	String& add_str(const String other_string); // 문자열 붙이기

	bool involve_check(const String other_string); // 문자열 포함여부 확인하기

	bool same_check(const String other_string); // 문자열 같음 여부 확인하기

	int versus(const String other_string); // 문자열 크기 비교(사전 순) 같으면 0, 앞에것이 더 빠르면(짧으면) -1, 아니면 1

	void print_str(); // 문자열 출력하기


};

String::String(int len, char c) : len(len) // 문자로부터의 문자열 생성자
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
	// str = input_str; // "const char* 형식의 값을 char 엔터티에 할당할 수 없습니다. 오류 발생. 원래 안됐나?"
	for (int i = 0; i < len; i++)
	{
		str[i] = input_str[i];
	}
	str[len] = '\0';
}
String::~String() // 소멸자
{
	delete[] str;
}

int String::strlen() const// 문자열 길이를 구하는 함수
{
	return len;
}


String& String::add_str(const String other_string) // 문자열 붙이기
{
	
}

bool String::involve_check(const String other_string) // 문자열 포함여부 확인하기
{

}

bool String::same_check(const String other_string) // 문자열 같음 여부 확인하기
{

}

int String::versus(const String other_string) // 문자열 크기 비교(사전 순) 같으면 0, 앞에것이 더 빠르면(짧으면) -1, 아니면 1
{

}

void String::print_str() // 문자열 출력하기
{

}

int main()
{
	String a(10, 'c');
	a.strlen();
	return 0;
}