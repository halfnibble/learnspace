#include <iostream>

int main()
{
	using namespace std;

	// Set variables
	string f_name;
	string l_name;
	string whole_name;
	char grade;
	int age;

	// Get user information
	cout << "What is your first name? ";
	getline(cin, f_name);

	cout << "What is your last name? ";
	getline(cin, l_name);

	whole_name = l_name + ", " + f_name;

	cout << "What grade do you deserve? ";
	cin >> grade;

	cout << "What is your age? ";
	cin >> age;

	// Display user information
	cout << "Name: " << whole_name << endl
		 << "Grade: " << ++grade << endl
		 << "Age: " << age << endl;
}