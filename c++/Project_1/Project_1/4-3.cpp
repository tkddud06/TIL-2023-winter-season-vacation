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