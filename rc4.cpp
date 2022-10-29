/*
	Author: rklss
	Year: 2022
	Goal: RC4 implementation in C++
	Sources: https://wl.vern.cc/wiki/RC4?lang=en
		 https://bw.vern.cc/cryptography/wiki/RC4
*/
#include <iostream>
#include <vector>

void swap_bytes(unsigned char* a, unsigned char* b) {
	unsigned char tmp = *a;
	*a = *b;
	*b = tmp;
}
void convert_to_hex (unsigned int a) {
	unsigned char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};	
	std::vector<int> output_values;
	while (a != 0) {
		output_values.push_back(a%16); // Remainder is stored in the vector
		a /= 16; // Division is stored in [a]
	}
	if (output_values.size() == 1) { // Prevents single hex digit output when [a] is smaller than 16 ( outputs "0?" instead of "?" )
		output_values.push_back(0);
	}
	for (int i = output_values.size() - 1; i >= 0; --i) {
		std::cout << hex_table[output_values[i]]; // All elements of the vector are printed to the user from the back
	}
}

int main(int argc, char** argv) {
	// Initialization of variables
	std::string key;
	int i, j, len;
	std::vector<unsigned char> S, K;
	//Key length input & check
	std::cout << "Enter key: ";
	getline(std::cin, key);
	if (key.length() < 5) {
		std::cout << "Too short password! Exiting...\n";
		return 0;
	}
	std::cout << "Enter the length of the ciphertext: ";
	std::cin >> len;
	if (len < 10) {
		std::cout << "Too short length! Exiting...\n";
		return 0;
	}
	// KSA
	for (i = 0; i < 256; ++i) { // Puts all possible permutations of a byte to S
		S.push_back(i);
	}
	j = 0;
	for (i = 0; i < 256; ++i) {
		j = (j + S[i] + key[i % key.length()]) % 256;
		swap_bytes(&S[i], &S[j]);
	}
	// PRGA
	i = 0;
	j = 0;
	while (len > 0) {
		i = (++i) % 256;
		j = (j + S[i]) % 256;
		swap_bytes(&S[i], &S[j]);
		K.push_back(S[(S[i] + S[j]) % 256]);
		--len;
	}
	// Print ciphertext ( in hex )
	for (int x = 0; x < K.size(); ++x) {
		convert_to_hex(K[x]);
		std::cout << " "; // Separates every ASCII character ( every 2 hex chars )
	}
	std::cout << "\n";
	return 0;
}
