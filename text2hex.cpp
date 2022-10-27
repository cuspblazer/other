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
void print_values (unsigned char a) {
	if (a >= 32 && a <= 126) {
		std::cout << "\t" << a << "\n";
	} else {
		std::cout << "\t" << ".\n";
	}
}
void text_conversion(bool hex_string_only) {
	// Saving input text
	std::string input_text;
	std::cout << "Enter Text: ";
	getline(std::cin, input_text);
	if (hex_string_only) { // Prints only as a stream of hex chars
		for (int i = 0; i < input_text.length(); ++i) {
			convert_to_hex((unsigned int) (unsigned char) input_text[i]);
		}
		std::cout << "\n";
		return;
	} // Or else it prints in a "table"
	// Table output
	std::cout << "HEX\tNUM\tVAL\n";
	for (int i = 0; i < input_text.length(); ++i) {
		convert_to_hex((unsigned int) (unsigned char) input_text[i]);
		std::cout << "\t" << (unsigned int) (unsigned char) input_text[i];
		print_values((unsigned char) input_text[i]);
	}
	std::cout << "\n";
}
void number_conversion(bool hex_string_only) {
	// Saving input number
	unsigned int input_number;
	std::cout << "Enter number: ";
	std::cin >> input_number;
	if (hex_string_only) { // Same as in func text_conversion
		convert_to_hex(input_number);
		return;
	}
	// Table output
	std::cout << "HEX\tNUM\n";
	convert_to_hex(input_number);
	std::cout << "\t" << input_number;
	std::cout << "\n";
}
int main(int argc, char** argv) {
	// Mode selection
	bool hex_string_only = (argc == 3 && *argv[2] == 's' ? true : false); // Sets variable if 2nd argument was typed
	if (argc == 1 || *argv[1] == 't') {
		std::cout << "Text conversion!\n";
		text_conversion(hex_string_only);
	} else if (*argv[1] == 'n') {
		std::cout << "Number conversion!\n";
		number_conversion(hex_string_only);
	} else if (*argv[1] == '?' || *argv[1] == 'h') {
		std::cout << "Text to HEX converter - help menu\n";
		std::cout << "Usage:\n\ttext2hex [args]\nArguments:\n\t t/none - Text -> HEX\n\t n - Number -> HEX\n\t s ( 2nd argument ) - Prints only in hex as a stream\n\t?/h - Show this help menu\n"; // Don't judge me
	} else {
		std::cout << "Unrecognized argument! Exiting...\n";
	}
	return 0;
}