// #include <iostream>

/*int main() {

	// std::cout << "nice meet you" << std::endl;

	// std::cout << "die!!!" << std::endl << std::endl << "wow!" << std::endl;

	int num1, num2;

	std::cout << "넘버1 입력 :";
	std::cin >> num1;
	std::cout << "넘버2 입력 :";
	std::cin >> num2;

	std::cout << "두 수의 합 :" << num1+num2 << std::endl;



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


// 4-1 연습문제 1번. 같은문장 여러번쓰기 싫고, 반복문이나 뭐 여러가지 다른걸 생각해보느라 푸는데 오래걸림. 근데 실제로는 다 쓰고 무식하게 했네..
// 다 해결하는데까지 엄청 오래걸렸는데, 주요 문제는 실수였다. 사소한 주어진 사항 못읽은 실수, 상식 실수, 휴먼에러였다. 정신 차리고 제대로 한번에 천천히 보자 차라리..
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

		if (month_ > 12) // date_up 두번 들어올 필요 없이, 반복 없이 한번에 수식으로 정리 어렵나. 24때문에 잘 안되네.
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
	std::cout << "원하는 날짜를 입력하세요. 형식 : 20030924(8자리)\n입력 : ";
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