#include <iostream>

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

int& function(int& a) {
  a = 5;
  return a;
}

int main() {
  int b = 2;
  int c = function(b);
  return 0;
}