#include <iostream>

void swap(unsigned char* a, unsigned char* b);
unsigned char lfsr(unsigned char n, unsigned char c);
void ttc(char px, unsigned char ks);
void ctt(char c,char c2, unsigned char ks);

// Čísla v komentářích značí titulek se stejným číslem 
int main() {
	unsigned char k[256], ks[8000]; // 3.1
	char choice = 'n';
	std::cout << "Do you want to decode? (y/n): ";
	std::cin >> choice;
	std::cin.ignore();
	if ((int)choice == (int)'y') { // 3.2
		std::string c;
		std::string p;
		std::cout << "Enter ciphertext: ";
		getline(std::cin, c);
		std::cout << "Enter passphrase: ";
		getline(std::cin, p);

		// KSA
		for (unsigned short int i = 0; i < 256; ++i) k[i] = i; 
		unsigned char j = 0;
		for (unsigned short int i = 0; i < 256; ++i){ 
			j = j + p[i % p.length()];
			swap(&k[i], &k[j]);
			k[i] = lfsr(j, p[i % p.length()]);
		}
		// PRGA
		int i = 0;
		while(true) {
			if (c[i*2] == 0x0) break;
			j = j + k[i % 256];
			swap(&k[i], &k[j]);
			ks[i] = k[(k[i] + k[j]) % 256];
			i++;
		}
		for (int i = 0; i < c.length(); i += 2)
		{
			ctt(c[i], c[i+1], ks[i/2]);
		}
		std::cout << "\n";
		return 0;
	}
	// 3.1
	std::string t;
	std::string p;

	std::cout << "Enter plaintext: ";
	getline(std::cin, t);
	std::cout << "Enter passphrase: ";
	getline(std::cin, p);

	// 3.1-1
	for (unsigned short int i = 0; i < 256; ++i) k[i] = i;
	unsigned char j = 0;
	for (unsigned short int i = 0; i < 256; ++i){ 
		j = j + p[i % p.length()];
		swap(&k[i], &k[j]);
		k[i] = lfsr(j, p[i % p.length()]);
	}
	// 3.1-2
	int i = 0;
	while(true) {
		if (t[i] == 0x0) break;
		j = j + k[i % 256];
		swap(&k[i], &k[j]);
		ks[i] = k[(k[i] + k[j]) % 256];
		++i;
	}
	// 3.1-3
	for (int i = 0; i < t.length(); ++i)
	{
		ttc(t[i], ks[i]);
	}
	std::cout << "\n";
	return 0;
}
void swap(unsigned char* a, unsigned char* b) {
	unsigned char* tmp = a;
	*a = *b;
	*b = *tmp;
}
unsigned char lfsr(unsigned char n, unsigned char c) { // Taps: 8, 6, 5, 3
	unsigned char x;
	for (unsigned char i = 0; i < n; ++i) {
		x = (c >> 7) ^ (c >> 5) ^ (c >> 4) ^ (c >> 2);
		c = (c >> 1) ^ (x << 7);
	}
	return c + 1;
}
void ttc(char px, unsigned char ks) { // Text To Ciphertext(HEX)
	unsigned char c = px ^ ks;
	char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	std::cout << hex_table[(c / 16) % 16] << hex_table[c % 16];
}
void ctt(char c, char c2, unsigned char ks) { // Ciphertext(HEX) To Text
	char hex_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	unsigned char j, k;
	for (unsigned char i = 0; i < 16; ++i)
	{
		if (c == hex_table[i]) j = i;
		if (c2 == hex_table[i]) k = i;
	}
	std::cout << (char)((j * 16 + k) ^ ks);
}