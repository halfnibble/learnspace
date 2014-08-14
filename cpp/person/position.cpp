#include "position.h"

#include <string>

Position::Position(string name, string description)
	: m_Name(name), m_Description(description)
{}

string Position::toString()
	:
{
	return "Position Title: " + m_Name + ", Description: " + m_Description;
}