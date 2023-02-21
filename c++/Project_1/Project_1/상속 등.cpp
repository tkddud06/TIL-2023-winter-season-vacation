#include <iostream>

class base {
protected:
	int a;

public:
	virtual void print()
	{
		std::cout << "hello" << std::endl;
	}
};

class second : public base {
protected:
	int b;
public:
	void print() override
	{
		std::cout << "not hello" << std::endl;
	}
};

int main()
{
	second s;
	base* b = new second();
	b->print(); // 정상적으로 오버라이딩됨
	base d = s;
	d.print(); // 정상적으로 오버라이딩되지 않음
	// second s2 = d; // 컴파일 에러
	delete b;
	return 0;
}