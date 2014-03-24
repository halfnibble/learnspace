#include <QString>
#include "fraction.h"

void Fraction::set(int n, int d) {
	m_Numerator = n;
	m_Denominator = d;
}

QString Fraction::toString() {
	return QString("%1 / %2").arg(m_Numerator).arg(m_Denominator);
}

double Fraction::toDouble() {
	return 1.0 * m_Numerator / m_Denominator;
}

Fraction Fraction::add(const Fraction& other) {
	Fraction result;
	int result_Numerator, result_Denominator;

	// Result denominator is Least Common Denominator
	result_Denominator = Fraction::LCD(m_Denominator, other.m_Denominator);

	// Use LCD to get numerators
	result_Numerator = (result_Denominator / m_Denominator) * m_Numerator
					 + (result_Denominator / other.m_Denominator) * other.m_Numerator;

	result.set(result_Numerator, result_Denominator);
	
	return result;
}

Fraction Fraction::subtract(const Fraction& other) {
	Fraction result;
	int result_Numerator, result_Denominator;

	// Result denominator is Least Common Denominator
	result_Denominator = Fraction::LCD(m_Denominator, other.m_Denominator);

	// Use LCD to get numerators
	result_Numerator = (result_Denominator / m_Denominator) * m_Numerator
					 - (result_Denominator / other.m_Denominator) * other.m_Numerator;

	result.set(result_Numerator, result_Denominator);
	
	return result;
}

Fraction Fraction::multiply(const Fraction& other) {
	Fraction result;

	result.set(m_Numerator * other.m_Numerator, m_Denominator * other.m_Denominator);

	return result;
}

Fraction Fraction::divide(const Fraction& other) {
	Fraction result;

	result.set(m_Numerator * other.m_Denominator, m_Denominator * other.m_Numerator);

	return result;
}

int Fraction::LCD(int a, int b) {
	int i, j = 0, gcd, lcd;

	for (i = 1; i < a; ++i)
		j = j + floor(i * b / a);

	gcd = 2 * j + a + b - (a * b);
	lcd = (a * b) / gcd;

	return lcd;
}