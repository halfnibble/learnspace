// Ch. 5 Exercise 4
// C++ For Fools
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const int MONTHS = 12;
	string months[MONTHS] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	int monthSales[MONTHS];
	int sales = 0;		// temporarily hold monthly sales
	int totalSales = 0; // hold all sales for the year

	cout << "Enter the number of books sold by month.\n";
	for (int i = 0; i < MONTHS; i++) {
		cout << "Sales for " << months[i] << ": ";
		cin >> sales;
		totalSales += sales;
	}

	cout << "\nTotal sales: " << totalSales << endl;
	return 0;
}