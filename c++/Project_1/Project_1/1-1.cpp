// #include <iostream>

/*int main() {

	// std::cout << "nice meet you" << std::endl;

	// std::cout << "die!!!" << std::endl << std::endl << "wow!" << std::endl;

	int num1, num2;

	std::cout << "�ѹ�1 �Է� :";
	std::cin >> num1;
	std::cout << "�ѹ�2 �Է� :";
	std::cin >> num2;

	std::cout << "�� ���� �� :" << num1+num2 << std::endl;



	return 0;
}
*/

/*
int change_val(int* p) {
	*p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}
*/

/*
int main()
{
	int num;
	int& nickname = num;
	std::cout << "nice meet you!\n" << "What's your number? : ";
	std::cin >> nickname;

	if (nickname > 100)
	{
		std::cout << "oh! you higher than 100!" << std::endl;
	}
	else
	{
		std::cout << "oh, your number is " << nickname << "!!" << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << nickname << std::endl;
	}

	return 0;
}
*/

/*
int& function(int& a) {
  a = 5;
  return a;
}

int main() {
  int b = 2;
  int c = function(b);
  return 0;
}
*/


// 4-1 �������� 1��. �������� ���������� �Ȱ�, �ݺ����̳� �� �������� �ٸ��� �����غ����� Ǫ�µ� �����ɸ�. �ٵ� �����δ� �� ���� �����ϰ� �߳�..
// �� �ذ��ϴµ����� ��û �����ɷȴµ�, �ֿ� ������ �Ǽ�����. ����� �־��� ���� ������ �Ǽ�, ��� �Ǽ�, �޸տ�������. ���� ������ ����� �ѹ��� õõ�� ���� ����..
#include <iostream>

class Date {
	int year_;
	int month_; // 1~12
	int day_; // 1~31

	void date_up_checker(int i)
	{
		if (i == 1)
		{
			while (1)
			{
				if (month_ > 12)
				{
					date_up_checker(2);
				}
				if (month_ == 2)
				{
					if ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0))
					{
						if (day_ > 29)
						{
							month_plus(29);
						}
						else
						{
							break;
						}
					}
					else if (day_ > 28)
					{
						month_plus(28);
					}
					else
					{
						break;
					}

				}
				else if ((month_ <= 7 && month_ % 2 == 1) || (month_ > 7 && month_ % 2 == 0))
				{
					if (day_ > 31)
					{
						month_plus(31);
					}
					else
					{
						break;
					}
				}
				else
				{
					if (day_ > 30)
					{
						month_plus(30);
					}
					else
					{
						break;
					}
				}

			}
		
		}

		if (month_ > 12) // date_up �ι� ���� �ʿ� ����, �ݺ� ���� �ѹ��� �������� ���� ��Ƴ�. 24������ �� �ȵǳ�.
		{
			month_ -= 12;
			year_ += 1;
			date_up_checker(2);
		}

	}

	void month_plus(int inc)
	{
		day_ -= inc;
		month_ += 1;
	}

public:
	void SetDate(int year, int month, int date)
	{
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc)
	{
		day_ += inc;
		date_up_checker(1);
	}
	void AddMonth(int inc)
	{
		month_ += inc;
		date_up_checker(2);
	}
	void AddYear(int inc)
	{
		year_ += inc;
	}

	void ShowDate()
	{
		std::cout << year_ << month_ << day_ << std::endl;
	}
};

int main()
{
	Date date;
	int temp_date;
	std::cout << "���ϴ� ��¥�� �Է��ϼ���. ���� : 20030924(8�ڸ�)\n�Է� : ";
	std::cin >> temp_date;
	int temp_year, temp_month, temp_day;
	temp_year = temp_date / 10000;
	temp_month = temp_date % 10000 / 100;
	temp_day = temp_date % 100;
	date.SetDate(temp_year, temp_month, temp_day);
	date.AddDay(365);
	date.ShowDate();
	return 0;
}