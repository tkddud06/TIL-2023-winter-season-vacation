

#include <iostream>

class testing {
private:
	char* str;
	int num;
public:
	testing(int n) : num(n) 
	{
		str = new char[21];
		for (int i = 0; i < 20; i++)
		{
			str[i] = 'c';
		}
		str[20] = '\0';
	}

	testing(char c) : num(11)
	{
		str = new char[21];
		for (int i = 0; i < 20; i++)
		{
			str[i] = c;
		}
		str[20] = '\0';
	}

	testing(const testing& test) : num(test.num) 
	{
		str = new char[11];
		for (int i = 0; i < 10; i++)
		{
			str[i] = test.str[1];
		}
		str[10] = '\0';
	}

	testing func(const testing& test)
	{
		testing a(5);
		int temp = 3;
		a.num = 7;
		for (int i = 0; i < a.num; i++)
		{
			a.str[i] = test.str[i];
		}
		return a;
	}
	~testing()
	{
		delete[] str;
	}

	void print()
	{
		std::cout << str << std::endl;
	}

	testing& operator=(const testing& test)
	{
		num = std::strlen(test.str);
		str = new char[num + 1];
		for (int i = 0; i < num; i++)
		{
			str[i] = test.str[i];
		}
		str[num] = '\0';
		return *this;
	}
};

int main()
{
	testing z(3);
	testing p('d');
	//testing k = z.func(p);

	z = z.func(p);

	return 0;
}

// �ڵ�� Ȯ���غ� ���, ����� ���� ������� �� ����� ���� �������� ���� ��, �Ϲ����� �κ��� ���������� �۵��Ǵ� �� Ȯ���� �� ����.
// ���������� �۵����� �ʴ°� 4-5 �ش� �ڵ��, `z = z.func(p)`�� ���� �ڱ� �ڽſ� �����ϴ� �ڵ� ��.
// �ڱ� �ڽſ� �����ϴ� �ڵ�� ���� ������ ��� ���� ����Ͽ� �ذ� �� �� �ִ���.
// 
// ���. 1. ������� �ȵǰ� ���� �̻���? ��(�������� ���� ���ٴ���) �۵��� ���������� �̷����. 2. ���Կ����ڴ� �������� ������� �Ҹ��� �ҷ����°Ͱ� �������� ���� �߻�, ���Կ����� ���Ƿ� �ذᰡ��.
// 3. ���� ������ �޸տ�������. ������ �������� �����۵���.

/*
class Complex {
private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) const {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) const {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) const {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);

	Complex c = a * b;

	c.println();
}
*/


/*

class a
{
	char* str;
	int len;

public:
	a(const a& m);

	a(const char c);
};

a::a(const a& m) : len(5)
{
	str = new char[21];
	for (int i = 0; i < 20; i++)
	{
		str[i] = 'a';
	}
	str[20] = '\0';
}

a::a(const char c) : len(5)
{
	str = new char[11];
	for (int i = 0; i < 10; i++)
	{
		str[i] = 'a';

	}
	str[10] = '\0';
}


int main()
{
	a m('a');
	a c(m);

	return 0;
}
*/