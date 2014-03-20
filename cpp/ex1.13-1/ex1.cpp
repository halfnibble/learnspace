#include <QtGui>
#include <string>
#include <sstream>
#include <iomanip>

// Temp conversion 
double celsiusToFahr(double celsius);

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	QTextStream cout(stdout);

	double goAgain = 0;

	do {
		double celsius = 0.00;
		double fahr = 0.00;

		// Get temperature from User in Celsius
		celsius = QInputDialog::getDouble(0, "Celsius to Fahrenheit Converter",
			"Temperature in Celsius", 1);

		// Convert temperature to Fahrenheit
		fahr = celsiusToFahr(celsius);

		// Display answer and ask to "go again?"
		QString result = QString("%1 degrees Celsius is %2 degrees Fahrenheit.\n%3")
			.arg(QString::number(celsius, 'f', 2))
			.arg(QString::number(fahr, 'f', 2))
			.arg("Do you want to convert another temperature?");
		goAgain = QMessageBox::question(0, "Convert again?", result, 
			QMessageBox::Yes | QMessageBox::No);

		// Display temperature conversion chart in console
		int i;
		cout << "\nCelsius to Fahrenheit table.\n"
			 << "\tCelsius\tFahrenheit\n"
			 << "\t-------\t----------" << endl;
		for(i = 0; i <= 100;) {
			cout << "\t" << i << "\t" << celsiusToFahr(i) << endl;
			i += 5;
		}

	} while (goAgain == QMessageBox::Yes);

	return EXIT_SUCCESS;
}

double celsiusToFahr(double celsius) {
	// Convert temperature to Fahrenheit
	double fahr = 9.0 * celsius / 5 + 32;

	return fahr;
}