// cctypes.cpp -- using the ctype.h library
#include <iostream>
#include <cctype>				// prototypes for character functions

int main()
{
	using namespace std;
	cout << "Enter text for analysis, and type @"
			" to terminate input.\n";

	char ch;
	int whitespace = 0,
		digits = 0,
		chars = 0,
		punct = 0,
		others = 0;

	cin.get(ch);				// get first character
	while (ch != '@')			// test for sentinel
	{
		if (isalpha(ch))		// is it alphabetic?
			chars++;
		else if (isspace(ch))	// is is whitespace?
			whitespace++;
		else if (isdigit(ch))	// is it a digit?
			digits++;
		else if (ispunct(ch))	// is it a punctuation?
			punct++;
		else
			others++;
		cin.get(ch);			// get next character
	}

	cout << chars << " letters, "
		 << whitespace << " whitespace, "
		 << digits << " digits, "
		 << punct << " punctuation, "
		 << others << " others.\n";

	return 0;
}