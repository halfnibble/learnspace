// ch5ex3.cpp
#include <iostream>

int main()
{
	using namespace std;

	int fundsDaphne = 100; 	// Daphne's original investment
	int fundsCleo = 100; 	// Cleo's original investment
	int year = 0;			// years of investment

	// test when Cleo's inestment is more valuable than Daphne's
	while (fundsCleo <= fundsDaphne) {
		// Daphne earns 10% x original investment annually
		fundsDaphne += (0.10 * 100);
		// Cleo earns 5% compound interest
		fundsCleo += (0.05 * fundsCleo);
		// add a year
		year += 1;
	}

	cout << "Cleo's investment is more valuable after " << year << " years.\n";
	cout << "Cleo's fund: " << fundsCleo << endl;
	cout << "Daphne's fund: " << fundsDaphne << endl;

	return 0;
}