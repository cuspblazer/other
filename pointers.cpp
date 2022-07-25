#include <iostream>

int main() {
	std::cout << "Enter string: ";
	std::string txt;
	getline(std::cin, txt);

	std::cout << "\n" << "Value: " << txt << "\n"; // Prints the value of the variable txt
	std::cout << "Address: " << &txt << "\n"; // Prints address where the variable txt is stored in memory

	std::string* ptr = &txt; // Declaration of pointer ptr + storing the address of the variable txt

	std::cout << "Pointer ref.: " << ptr << "\n"; // Reference (prints the address where the variable txt is stored in memory using a pointer)
	std::cout << "Pointer der.: " << *ptr << "\n"; // Dereference (prints the value of the address stored in pointer ptr)
	return 0;
}