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