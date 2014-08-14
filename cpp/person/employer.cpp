#include "employer.h"
#include "person.h"
#include "position.h"

#include <string>

Employer::Employer(string name, string market)
	: m_Name(name), m_market(market)
{}

bool Employer::hire(Person& newHire, Position pos) :
{
	return true;
}

string Employer::getName() :
{
	return m_Name;
}

string Employer::getMarket() :
{
	return m_market;
}

string Employer::toString() :
{
	return "Company: " + m_Name + ", Market: " + m_market;
}
