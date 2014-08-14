#include "person.h"
#include "position.h"
#include "employer.h"

#include <string>

Person::Person(string name)
	: m_Name(name), m_Employed(false)
{}

void Person::setPosition(Employer newC, Position newP)
	: m_employer(newC), m_position(newP), m_Employed(true)
{}

void Person::resetPosition()
	: m_Employed(false)
{}

string Person::getName() :
{
	return m_Name;
}

string Person::getPosition() :
{
	if (m_Employed) {
		return m_position.getName();
	} else {
		return "Unemployed";
	}
	
}

string Person::getEmployer() :
{
	if (m_Employed) {
		return m_employer.getName();
	} else {
		return "Unemployed";
	}
}

string Person::toString() :
{
	if (m_Employed) {
		return "Name: " + m_Name + ", Employed by: " + Person::getEmployer() + ", Position: " + Person::getPosition();
	} else {
		return "Name: " + m_Name + ", Unemployed";
	}
}



