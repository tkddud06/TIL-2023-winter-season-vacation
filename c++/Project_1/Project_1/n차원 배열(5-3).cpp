// n���� �迭�� 1���� �迭�� �����, �ű⿡ �� �迭�� �ְ� �̷��� ������ �� ������.
// (������ �ϵ���, �ּҸ� �ְ� �ּҸ� �־)
// ȣ����, �Ƹ� ���� �����ϱ�� []�� ȣ��������, [index]�� Ȯ���غ� ��,
// �ش� �κ��� ���ϴ� data �ڷ��� size�� ��ġ�Ѵٸ�, �ش簪�� ����,
// �׷��� ���� ��쿡�� �ּҰ��� �����ϴ� ������� ������ �� ���� ������ ������.

#include <iostream>


// n���� ���簢�� �迭 ����� ������Ʈ

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
				hang[i][j - 1] = j + (i * n); // n���� ���簢�� �迭�� ���� ������������ �ֱ�
			} // �Ϲ�������, �̷��� ���ϰ� int���� �ϳ� �� ����� �ְ���. ��ó�� for�� ���ų�, while�� i�� ������ �� �ְ���.
		}
	}

	// �ٵ� �̷��� �ϸ� 2�����ۿ� �� �Ǵµ�.. ���� �ϴ� �Ѿ��!
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