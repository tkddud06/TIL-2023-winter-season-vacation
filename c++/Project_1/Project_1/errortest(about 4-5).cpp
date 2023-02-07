

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

// 코드로 확인해본 결과, 디버깅 툴을 사용했을 때 디버깅 툴이 추적하지 못할 뿐, 일반적인 부분은 정상적으로 작동되는 걸 확인할 수 있음.
// 정상적으로 작동되지 않는건 4-5 해당 코드와, `z = z.func(p)`와 같은 자기 자신에 정의하는 코드 뿐.
// 자기 자신에 정의하는 코드는 대입 연산자 라는 것을 사용하여 해결 할 수 있더라.
// 
// 결론. 1. 디버깅이 안되고 뭔가 이상할? 뿐(리턴으로 먼저 간다던가) 작동은 정상적으로 이루어짐. 2. 대입연산자는 지역변수 사라질때 소멸자 불러지는것과 겹쳐지며 에러 발생, 대입연산자 정의로 해결가능.
// 3. 실제 문제는 휴먼에러였음. 변수를 수정하자 정상작동함.

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