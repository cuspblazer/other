#include <iostream>
#include <vector>

void convert_to_hex (int a) {
	unsigned char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};	
	std::vector<int> output_values;
	while (a != 0) {
		output_values.push_back(a%16);
		a /= 16;
	}
	for (int i = output_values.size() - 1; i >= 0; --i) {
		std::cout << hex_table[output_values[i]];
	}
}

int main(int argc, char** argv) {
	std::string input_text;
	std::cout << "Enter Text: ";
	getline(std::cin, input_text);
	for (int i = 0; i < input_text.length(); ++i) {
		convert_to_hex(input_text[i]);
		std::cout << " ";
	}
	std::cout << "\n";
	return 0;
}