// n차원 배열은 1차원 배열을 만들고, 거기에 또 배열을 넣고 이렇게 구현할 수 있을듯.
// (포인터 하듯이, 주소를 넣고 주소를 넣어서)
// 호출은, 아마 지금 생각하기론 []로 호출했을때, [index]로 확인해본 뒤,
// 해당 부분이 원하는 data 자료형 size와 일치한다면, 해당값을 리턴,
// 그렇지 않을 경우에는 주소값을 리턴하는 방식으로 구현할 수 있지 않을까 추측함.

#include <iostream>


// n차원 정사각형 배열 만들기 프로젝트

class ncha {
private:
	int n;
	int** hang;
public:
	ncha(int n) : n(n)
	{
		*hang = new int[n];
		for (int i = 0; i < n; i++)
		{
			hang[i] = new int[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				hang[i][j - 1] = j + (i * n); // n차원 정사각형 배열에 숫자 오름차순으로 넣기
			} // 일반적으론, 이렇게 안하고 int변수 하나 더 만들어 넣겠지. 이처럼 for문 쓰거나, while로 i를 제어할 수 있겠지.
		}
	}

	// 근데 이렇게 하면 2차원밖에 안 되는데.. 어라라 일단 넘어가자!
};
/*
class bae {
private:
	int n;

	friend bae operator+(bae a, bae b);
	friend bae operator*(bae a, bae b);
	friend bae operator-(bae a, bae b);
	friend bae operator/(bae a, bae b);
	friend std::ostream& operator<<(std::ostream& os, bae a);

public:
	//operator int() { return a; }

	bae(int n) : n(n) {}
	bae() : n(0) {}
};

bae operator+(bae a, bae b)
{
	bae temp = bae(a.n + b.n);
	return temp;
}

bae operator*(bae a, bae b)
{
	bae temp = bae(a.n * b.n);
	return temp;
}

bae operator-(bae a, bae b)
{
	bae temp = bae(a.n - b.n);
	return temp;
}

bae operator/(bae a, bae b)
{
	bae temp = bae(a.n / b.n);
	return temp;
}

std::ostream& operator<<(std::ostream& os, bae a)
{
	os << a.n;

	return os;
}

int main()
{
	bae a = 2, b = 3;
	bae c = a * 2 + b;
	bae f[2][3] = { 1,2,3,4,5,6 };
	std::cout << f[1][2] << std::endl;
	std::cout << c << std::endl;
	return 0;
}
*/