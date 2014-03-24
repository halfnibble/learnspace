#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <QString>

class Fraction {
public:
	void set(int n, int d);
	QString toString();
	double toDouble();
	Fraction add(const Fraction& other);
	Fraction subtract(const Fraction& other);
	Fraction multiply(const Fraction& other);
	Fraction divide(const Fraction& other);
	static int LCD(int a, int b);
private:
	int m_Numerator;
	int m_Denominator;
};

#endif