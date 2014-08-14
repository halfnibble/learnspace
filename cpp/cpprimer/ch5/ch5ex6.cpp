// Ch. 5 Exercise 6
#include <iostream>
#include <string>

struct car
{
	std::string make;
	int built;
};

int main()
{
	using namespace std;
	int numCars = 0;	// number of cars to catalogue
	int testInt;

	cout << "How many cars do you wish to cataloge? ";
	cin >> numCars;

	car* catalogue = new car[numCars];	// car catalogue array

	for (int i = 0; i < numCars; i++) {
		cout << "Car # " << i+1 << ":\n"
			 << "Please enter the make: ";
		cin.ignore(); // fix \n char issue
		getline(cin, catalogue[i].make);
		
		cout << "Please enter the year made: ";
		cin >> catalogue[i].built;
	}

	 cout << "\nHere is your collection:\n";
	 for (int i = 0; i < numCars; i++) {
	 	cout << catalogue[i].built << "\t" << catalogue[i].make << endl;
	 }

	return 0;
}