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
		std::cout << "생성" << std::endl;
	}

	~test()
	{
		std::cout << "삭제" << std::endl;
	}
};

int main()
{
	test b;
	test* a;
	a = new test;
	delete a;
	return 0;
} // new, delete로 만들면 함수 안쓰면 삭제 자동으로 안 되고,
// 지역변수로 test 선언하면 자동으로 생성 삭제 됨. 소멸자도 실행되고.

*/

#include <iostream>

class string {
private:
	char* str;
	int len;

public:
	string(char c, int n); // 문자 c가 n개 있는 문자열의 정의
	string(const char* s); // 아마 문자열로 바로 정의, strlen사용 필요할 듯
	string(const string& s); // 복사 생성자
	~string(); // delete str 요구될 듯


	void add_string(const string& s); // str뒤에 s를 붙인다.
	void copy_string(const string& s); // str 에 s를 복사한다.
	int strlen(); // 문자열 길이 리턴
};

string::string(char c, int n)
{
	len = n;
	str = new char[len+1]; // null을 위해 +1
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