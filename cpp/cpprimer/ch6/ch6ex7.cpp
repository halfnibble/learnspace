#include <iostream>

int main()
{
	using namespace std;

	char ch = 'C';

	switch (ch) {
		case 'A':
			cout << "It's an A.\n";
			break;
		case 'B':
			cout << "It's a B.\n";
			break;
		case 'C':
			cout << "It's a C.\n";
			break;
		default:
			cout << "You're a failure!";
			break;
	};

	return 0;
}