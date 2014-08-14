// textin4.cpp -- reading chars with cin.get()
#include <iostream>
#include <stdio.h>

int main(void)
{
	using namespace std;
	int ch;							// should be int, not char
	int count = 0;

	while ((ch = cin.get()) != EOF)	// teswt of end of file
	{
		cout.put(char(ch));
		++count;
	}

	cout << endl << count << " characters read\n";
	cout.put(int(EOF)) << endl;
	return 0;
}