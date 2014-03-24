#include <QTextStream>
#include <QString>
#include "fraction.h"

int main() {
	QTextStream cout(stdout);
	Fraction t1;
	t1.set(1, 2);

	Fraction t2;
	t2.set(3, 4);

	cout << "t1: " << t1.toString() << endl;
	cout << "t2 as Double: " << t2.toDouble() << endl;
	cout << "Added together: " << t1.add(t2).toString() << endl;

	Fraction t3, t4;
	t3.set(2, 3);
	t4.set(5, 6);

	cout << "t3: " << t3.toString() << endl;
	cout << "t4: " << t4.toString() << endl;
	cout << "t3 - t4: " << t3.subtract(t4).toString() << endl;
	cout << "t3/t4: " << t3.divide(t4).toString() << endl;
	cout << "t3*t4: " << t3.multiply(t4).toString() << endl;

	return 0;
}