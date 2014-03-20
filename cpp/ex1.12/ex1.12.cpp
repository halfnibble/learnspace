#include <QTextStream>
#include <QString>

int main() {
	QTextStream cout(stdout);
	cout << "GNU stands for \"GNU's Not UNIX\""
		 << "\n\tTitle 1 \t\"Cat Clothing\""
		 << "\n\tTitle 2 \t\"Dog Dancing\"" << endl;
	return 0;
}