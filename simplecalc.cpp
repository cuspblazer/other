#include <iostream>
using namespace std;

int main() {
  int a, b, sum, sub, mul, div; // Initialization of variables

  cout << "Enter the 1st number: "; // Prints the specified string
  cin >> a; // Reads the user input and saves it to variable named a
  cout << "Enter the 2nd number: ";
  cin >> b;

  // Calculates the expression
  sum = a+b;
  sub = a-b;
  mul = a*b;
  div = a/b;

  // Prints the results
  cout << "Results:\n";
  cout << sum << endl;
  cout << sub << endl;
  cout << mul << endl;
  cout << div << endl;
  return 0;
} 