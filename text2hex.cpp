#include <iostream>
#include <vector>

void convert_to_hex (unsigned int a) {
	unsigned char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};	
	std::vector<int> output_values;
	while (a != 0) {
		output_values.push_back(a%16); // Remainder is stored in the vector
		a /= 16; // Division is stored in [a]
	}
	for (int i = output_values.size() - 1; i >= 0; --i) {
		std::cout << hex_table[output_values[i]]; // All elements of the vector are printed to the user from the back
	}
}
void text_conversion() {
	// Saving input text
	std::string input_text;
	std::cout << "Enter Text: ";
	getline(std::cin, input_text);
	// Table output
	std::cout << "HEX\tNUM\n";
	for (int i = 0; i < input_text.length(); ++i) {
		convert_to_hex(input_text[i]);
		std::cout << "\t" << (unsigned int)input_text[i] << "\n";
	}
	std::cout << "\n";
}
void number_conversion() {
	// Saving input number
	unsigned int input_number;
	std::cout << "Enter number: ";
	std::cin >> input_number;
	// Table output
	std::cout << "HEX\tNUM\n";
	convert_to_hex(input_number);
	std::cout << "\t" << input_number;
	std::cout << "\n";
}
int main(int argc, char** argv) {
	// Mode selection
	if (argc == 1 || *argv[1] == 't') {
		std::cout << "Text conversion!\n";
		text_conversion();
	} else if (*argv[1] == 'n') {
		std::cout << "Number conversion!\n";
		number_conversion();
	} else if (*argv[1] == '?' || *argv[1] == 'h') {
		std::cout << "Text to HEX converter - help menu\n";
		std::cout << "Usage:\n\ttext2hex [args]\nArguments:\n\t t/none - Text -> HEX\n\t n - Number -> HEX\n\t ?/h - Show this help menu\n"; // Don't judge me
	} else {
		std::cout << "Unrecognized argument! Exiting...\n";
	}
	return 0;
}