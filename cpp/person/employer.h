#ifndef _EMPLOYER_H_
#define _EMPLOYER_H_

#include <string>

// Forward Class Declarations
class Person;
class Position;

class Employer {
public:
	Employer(string name, string market);
	bool hire(Person& newHire, Position pos);
	string getName();
	string getMarket();
	string toString();
private:
	string m_Name;
	string m_market;
};