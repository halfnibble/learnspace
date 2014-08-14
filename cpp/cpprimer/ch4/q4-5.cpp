#include <iostream>

struct CandyBar
{
	std::string brand;
	float weight; // in ounces
	int calories;
};

int main()
{
	using namespace std;

	CandyBar mocha_munch = 
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << "Nutritional Information for " << mocha_munch.brand << endl
		 << "Weight in ounces: " << mocha_munch.weight << endl
		 << "Calories: " << mocha_munch.calories << endl;

	return 0;
}