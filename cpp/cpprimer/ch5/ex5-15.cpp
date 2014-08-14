// dowhile.cpp -- exit-condition loop
#include <iostream>

int main()
{
	using namespace std;
	int n;

	cout << "Enter numbers in the range 1-10 to find"
		 << " my favorite number\n";

	do {
		cout << "It's NOT " << n << "!\n";
		cin >> n;	  // exectute
	} while (n != 7); // then test

	cout << "Yes, 7 is my favorite.\n";
	return 0;
}