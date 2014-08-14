#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

// Forward Class Declarations
class Employer;
class Position;

class Person {
public:
	Person(string name);
	void setPosition(Employer newC, Position newP);
	void resetPosition();
	string getName();
	string getPosition();
	string getEmployer();
	string toString();
private:
	string m_Name;
	bool m_Employed;
	Position m_position;
	Employer m_employer;
};

#endif