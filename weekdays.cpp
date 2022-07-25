#include <iostream>

int main() {
	char x;
	std::cout << "Enter a number (1-7): ";
	std::cin >> x;
	switch(x) {
		case '1':
			std::cout << "Monday\n";
			break;
		case '2':
			std::cout << "Tuesday\n";
			break;
		case '3':
			std::cout << "Wednesday\n";
			break;
		case '4':
			std::cout << "Thursday\n";
			break;
		case '5':
			std::cout << "Friday\n";
			break;
		case '6':
			std::cout << "Saturday\n";
			break;
		case '7':
			std::cout << "Sunday\n";
			break;
		default:
			std::cout << x << " is not a valid number\n";
			break;
	}
	return 0;
}