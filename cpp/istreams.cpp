#include <iostream>
#include <sstream>
#include <fstream>

bool fileOk(std::string fileName);
bool fileExists(std::string fileName);
bool confirmIt(std::string question);

int main() {
	using namespace std;
	ostringstream strbuf;
	string fileName;

	int lucky = 7; 
	float pi = 3.14;
	double e = 2.71;

	cout << "An in-memory stream" << endl;
	strbuf << "luckynumber: " << lucky << endl
		<< "pi: " << pi << endl
		<< "e: " << e << endl;

	string strval = strbuf.str();
	cout << strval;

	do {
		cout << "Name the file to write to: " << endl;
		cin >> fileName;
	} while (!fileOk(fileName));

	ofstream outf;
	outf.open(fileName.c_str());
	outf << strval;
	outf.close();

	cout << "Read data from the file - watch for errors." << endl;

	string newstr;
	ifstream inf;
	inf.open(fileName.c_str());
	if (inf) { // Make sure the file exists before attempting to read
		int lucky2;
		inf >> newstr >> lucky2;
		if (lucky != lucky2)
			cerr << "ERROR! Wrong " << newstr << lucky2 << endl;
		else
			cout << newstr << " OK [" << lucky2 << "]" << endl;

		float pi2;
		inf >> newstr >> pi2;
		if (pi2 != pi)
			cerr << "ERROR! Wrong " << newstr << pi2 << endl;
		else
			cout << newstr << " OK [" << pi2 << "]" << endl;

		double e2;
		inf >> newstr >> e2;
		if (e2 != e)
			cerr << "ERROR! Wrong " << newstr << e2 << endl;
		else
			cout << newstr << " OK [" << e2 << "]" << endl;
		inf.close();
	}

	// Line-by-line
	cout << "\nRead from file line-by-line" << endl;
	inf.open(fileName.c_str());
	if (inf) {
		while (not inf.eof()) {
			getline(inf, newstr);
			cout << newstr << endl;
		}
		inf.close();
	}

	return 0;
}

bool fileOk(std::string fileName) {
	if (fileExists(fileName)) {
		std::ostringstream question;
		question << "The file '" << fileName << "' already exists. Do you wish to overwrite?";
		return confirmIt(question.str());
	} else {
		return true;
	}
}

bool fileExists(std::string fileName) {
	using namespace std;
	ifstream thisFile;
	thisFile.open(fileName.c_str());
	if (thisFile)
		return true;
	else
		return false;
}

bool confirmIt(std::string question) {
	using namespace std;
	string response;
	cout << question << " (Y/N)" << endl;
	cin >> response;
	while (response != "Y" && response != "y" && response != "n" && response != "N") {
		cout << question << endl
			 << "Please respond 'Y' or 'N'." << endl;
		cin >> response;
	}
	if (response == "Y" || response == "y")
		return true;
	else
		return false;
}