/*
	Author: rklss
	Year: 2022
	Goal of this program to verify if typed number is a prime number or not.
	All inputs should be either sanitized or ignored.
*/
#include <iostream>
#include <cstdlib>

void FindPrime(int num) {
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			if (i != 1 & i != num) {
				std::cout << num << " is not a prime number! Exiting...\n";
				return;
			}
		}
	}
	std::cout << "!!!\n";
	std::cout << num << " is a prime number! Exiting...\n";
}

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "No number typed! Exiting...\n";
		return 0;
	}
	if (atoi(argv[1]) <= 0) {
		std::cout << "Invalid value! Exiting...\n";
		return 0;
	}
	FindPrime(atoi(argv[1])); // std::atoi - converts string to int
	return 0;
}