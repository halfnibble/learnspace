#ifndef _POSITION_H_
#define _POSITION_H_

#include <string>

class Position {
public:
	Position(string name, string description);
	string toString();
private:
	string m_Name;
	string m_Description;
};

#endif