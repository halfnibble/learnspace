// nested.cpp -- nested loops and 2-D array
#include <iostream>

const int Cities = 5;
const int Years = 4;

int main()
{
	using namespace std;
	const char* cities[Cities] = // array of pointer
	{							 // to 5 strings 
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};

	int maxtemps[Years][Cities] = // 2-D array
	{
		{95, 99, 86, 100, 104},	  // maxtemps[0]
		{95, 97, 90, 106, 102},	  // maxtemps[1]
		{96, 100, 940, 107, 105}, // etc...
		{97, 102, 89, 108, 104}
	};

	cout << "Maximum temperatures for 2002-2005\n\n";
	for (int city = 0; city < Cities; ++city) {
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; ++year) {
			cout << maxtemps[year][city] << "\t";
		}
		cout << endl;
	}

	return 0;
}