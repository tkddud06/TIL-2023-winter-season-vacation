#include <iostream>

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