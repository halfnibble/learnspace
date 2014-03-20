#include <iostream>
using namespace std;

double toCelsius(double fahr);
double toFahr(double celsius);

int main() {
	string type;
	double fahr;
	double celsius;
	cout << "Type C to convert to Celsius and F to convert to Fahrenheit: " << flush;
	cin >> type;
	if (type == "c" || type == "C") {
		cout << "Enter the temperature in Fahrenheit: " << flush;
		if (cin >> fahr) {
			cout << "The temperature in Celius is: " << toCelsius(fahr) << endl;
		} else {
			cerr << "Invalid temperature." << endl;
		}
	} else if (type == "f" || type == "F") 
{		cout << "Enter the temperature in Celsius: " << flush;
		if (cin >> celsius) {
			cout << "The temperature in Fahrenheit is: " << toFahr(celsius) << endl;
		} else {
			cerr << "Invalid temperature." << endl;
		}
	} else {
		cerr << "Invalid conversion selection. The type: " << type << " is not recognized." << endl;
	}
	
	return 0;
}

double toCelsius(double fahr) {
	double celsius;
	celsius = (5.0/9.0) * (fahr - 32);
	return celsius;
}

double toFahr(double celsius) {
	double fahr;
	fahr = (9.0/5.0) * celsius + 32;
	return fahr;
}