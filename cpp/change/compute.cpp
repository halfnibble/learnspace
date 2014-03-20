#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char* argv[]) {
	using namespace std;
	double bill;
	double paid;
	double change;
	int changeInt;
	string response;

	cout << "Enter the amount owed: \n$";
	cin >> response;
	bill = atof(response.c_str());

	cout << "Enter to amount paid: \n$";
	cin >> response;
	paid = atof(response.c_str());

	change = paid - bill;
	changeInt = change * 100;

	// Compute best change to give back
	int TEN_BILL = 1000;
	int FIVE_BILL = 500;
	int ONE_BILL = 100;
	int QUARTER_COIN = 25;
	int DIME_COIN = 10;
	int NICKEL_COIN = 5;
	int tenbill = 0;
	int fivebill = 0;
	int onebill = 0;
	int quarter = 0;
	int dime = 0;
	int nickel = 0;
	int penny = 0;
	int remainder = 0;

	tenbill = changeInt / TEN_BILL;
	remainder = changeInt % TEN_BILL;

	fivebill = remainder / FIVE_BILL;
	remainder = remainder % FIVE_BILL;

	onebill = remainder / ONE_BILL;
	remainder = remainder % ONE_BILL;

	quarter = remainder / QUARTER_COIN;
	remainder = remainder % QUARTER_COIN;

	dime = remainder / DIME_COIN;
	remainder = remainder % DIME_COIN;

	nickel = remainder / NICKEL_COIN;
	remainder = remainder % NICKEL_COIN;

	penny = remainder;

	cout << "The change due is: $" << fixed << setprecision(2) << change << endl;
	cout << "Give the customer:\n" 
		 << tenbill << " x $10 bills\n"
		 << fivebill << " x $5 bills\n"
		 << onebill << " x $1 bills\n"
		 << quarter << " x quarters\n"
		 << dime << " x dimes\n"
		 << nickel << " x nickels\n"
		 << penny << " x pennies."
		 << endl;
	return EXIT_SUCCESS;
}