#include <QtGui>
#include <sstream>

int main (int argc, char* argv[]) {
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	// Declaration of variables
	int answer = 0;

	do {
		// local variables to close the loop:
		int factArg = 0;
		long double fact = 1;
		std::stringstream factString;
		bool ok = false;
		
		factArg = QInputDialog::getInt(0, "Factorial Calculator", "Factorial of:", 1, 0, 2147483647, 1, &ok);
		if (!ok)
			return EXIT_SUCCESS;

		cout << "User entered: " << factArg << endl;


		int i=2;
		while (i <= factArg) {
			fact = fact * i;
			++i;
		}

		factString << fact;
		QString response = QString("The factorial of %1 is %2.\n%3")
			.arg(factArg).arg(QString::fromStdString(factString.str()))
			.arg("Do you want to computer another factorial?");
		answer = QMessageBox::question(0, "Play again?", response, QMessageBox::Yes | QMessageBox::No);
	} while (answer == QMessageBox::Yes);
	return EXIT_SUCCESS;
}