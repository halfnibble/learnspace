#include <QtGui>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	// Constants 
	int TEN_BILL = 1000;
	int FIVE_BILL = 500;
	int ONE_BILL = 100;
	int QUARTER_COIN = 25;
	int DIME_COIN = 10;
	int NICKEL_COIN = 5;

	// Loop control
	int doAgain = 0;
	bool ok = false;

	do {
		// Compute change variables
		double bill;
		double paid;
		double change;
		int changeInt;
		QString result;
		// Compute change denominations
		int tenbill = 0;
		int fivebill = 0;
		int onebill = 0;
		int quarter = 0;
		int dime = 0;
		int nickel = 0;
		int penny = 0;
		int remainder = 0;

		// Get user input
		bill = QInputDialog::getDouble(0,"Bill","Amount owed in USD",0,-2147483647,2147483647,2,&ok);
		if (!ok)
			return EXIT_SUCCESS;
		paid = QInputDialog::getDouble(0,"Paid","Amount paid in USD",0,-2147483647,2147483647,2,&ok);
		if (!ok)
			return EXIT_SUCCESS;

		// Compute change
		change = paid - bill;
		changeInt = (int)round(change * 100.0);

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

		// Format response
		result = QString("The change due is $%1\n\nGive the customer:\n"
			" %2 - $10 bills\n %3 - $5 bills\n %4 - $1 bills\n %5 - quarters\n"
			" %6 - dimes\n %7 - nickes\n %8 - pennies.\n\n%9")
			.arg(QString::number(change, 'f', 2))
			.arg(tenbill)
			.arg(fivebill)
			.arg(onebill)
			.arg(quarter)
			.arg(dime)
			.arg(nickel)
			.arg(penny)
			.arg("Do you want to compute another transaction?");

		doAgain = QMessageBox::question(0, "Another transaction?", result,
			QMessageBox::Yes | QMessageBox::No);

	} while (doAgain == QMessageBox::Yes);

	return EXIT_SUCCESS;
}