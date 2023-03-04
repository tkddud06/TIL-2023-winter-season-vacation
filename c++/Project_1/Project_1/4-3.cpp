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
	void print();
};

string::string(char c, int n) // 문자 c가 n개 있는 문자열의 정의
{
	len = n;
	str = new char[len+1]; // 마지막 null을 위해 +1
	for (int i = 0; i < len; i++) 
	{
		str[i] = c;
	}
	str[len] = '\0';
}

string::string(const char* s) // 문자열로 바로 정의, std::strlen사용
{
	len = std::strlen(s);
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = s[i];
	}
}

string::string(const string& s) // 복사 생성자
{
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i <= len; i++)
	{
		str[i] = s.str[i];
	}
}

string::~string() // 소멸자
{
	delete[] str;
	std::cout << "삭제완료" << std::endl;
}

void string::add_string(const string& s) // 해당 string 뒤에 string s를 추가
{
	string temp = s; // strlen을 사용하기 위한 꼼수


	int original_string_len = len; //  기존 string의 길이
	int adding_string_len = temp.strlen();
	len += adding_string_len; // len = 추가될 string의 길이를 포함한 길이
	char* new_str = new char[len + 1];
	// 기존 len크기의 string a, 타 len2크기의 string s
	// 새로운 len + len2 길이의 string c(실제 길이는 '\0'을 위해 len + len2 + 1)에 a와 s의 내용을 이어서 복사
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

void string::copy_string(const string& s) // 해당 string을 string s로 교체
{
	string temp = s; // strlen을 사용하기 위한 꼼수
	delete[] str;
	len = temp.strlen();
	str = new char[len + 1];
	// 새로운 str을 만든 후 내용을 새로이 입력
	int i = 0;
	for (i; i < len; i++)
	{
		str[i] = s.str[i];
	}
	str[len] = '\0';
}

int string::strlen() // len을 리턴하는 함수
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