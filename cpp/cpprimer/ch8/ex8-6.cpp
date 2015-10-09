// strtref.cpp -- using structure references
#include <iostream>
using namespace std;

struct sysop
{
	char name[26];
	char quote[64];
	int used;
};

const sysop & use(sysop &sysopref);		// function with reference return type

int main()
{
	// NOTE: some implementations require using the keyword static in structure declaration initializations
	sysop looper = 
	{
		"Rick \"Fortran\" Looper",
		"I'm a goto kind of guy.",
		0
	};

	use(looper);			// looper is type sysop
	cout << "Looper: " << looper.used << " use(s).\n";

	sysop copycat;
	copycat = use(looper);
	use(copycat);
	cout << "Looper: " << looper.used << " use(s).\n";
	cout << "Copycat: " << copycat.used << " use(s).\n";
	cout << "use(looper): " << use(looper).used << " use(s).\n";

	return 0;
}

// use() returns the reference passed to it 
const sysop & use(sysop &sysopref)
{
	cout << sysopref.name << " says:\n"
		 << sysopref.quote << endl;
		 sysopref.used++;
		 return sysopref;
}