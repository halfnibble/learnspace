#include <QTextStream>
#include <QString>
#include <QFile>
#include <iostream>

QTextStream cout(stdout);
QTextStream cerr(stderr);
QTextStream cin(stdin);

bool fileOk(QString fileName);

int main() {
	QString str, newstr;
	QTextStream strbuf(&str);
	QString fileName;

	int lucky = 7;
	float pi = 3.14;
	double e = 2.71;

	cout << "An in-memory stream" << endl;
	strbuf << "luckynumber: " << lucky << endl
		<< "pi: " << pi << endl
		<< "e: " << e << endl;

	cout << str;

	do {
		cout << "Name the file:" << endl;
		cin >> fileName;
	} while(fileOk(fileName) == false);

	QFile data(fileName);
	data.open(QIODevice::WriteOnly);
	QTextStream out(&data);
	out << str;
	data.close();

	cout << "Read data from file - watch for errors." << endl;
	if (data.open(QIODevice::ReadOnly)) {
		QTextStream in(&data);
		
		int lucky2;
		in >> newstr >> lucky2;
		if (lucky != lucky2)
			cerr << "ERROR! Wrong " << newstr << lucky2 << endl;
		else
			cout << newstr << " OK" << endl;

		float pi2;
		in >> newstr >> pi2;
		if (pi != pi2)
			cerr << "ERROR! Wrong " << newstr << pi2 << endl;
		else
			cout << newstr << " OK" << endl;

		double e2;
		in >> newstr >> e2;
		if (e != e2)
			cerr << "ERROR! Wrong " << newstr << e2 << endl;
		else
			cout << newstr << " OK" << endl;

		data.close();
	}

	cout << "\nRead from file line-by-line" << endl;
	if (data.open(QIODevice::ReadOnly)) {
		QTextStream in(&data);
		while (not in.atEnd()) {
			newstr = in.readLine();
			cout << newstr << endl;
		}
		data.close();
	}
	return 0;
}

bool fileOk(QString fileName) {
	QFile thisFile(fileName);
	std::string answer;
	if (thisFile.open(QIODevice::ReadOnly)) {
		cout << "This file '" << fileName << "' already exists. "
			 << "Do you want to overwrite it? (Y/N)" << endl;
		std::cin >> answer;
		if (answer == "y" || answer == "Y" || answer == "yes" || answer == "YES") {
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}