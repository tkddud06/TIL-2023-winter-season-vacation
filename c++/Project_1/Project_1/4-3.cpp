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