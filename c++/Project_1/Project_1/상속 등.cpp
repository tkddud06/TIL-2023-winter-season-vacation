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
	b->print(); // ���������� �������̵���
	base d = s;
	d.print(); // ���������� �������̵����� ����
	// second s2 = d; // ������ ����
	delete b;
	return 0;
}