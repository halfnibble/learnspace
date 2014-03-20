#include <iostream>
using namespace std;

int main() {
	int* ip = 0;
	delete ip;

	if (ip)
		cout << "non-null" << endl;
	else
		cout << "null" << endl;

	ip = new int;
	int* jp = new int(13);

	int djp = *jp * 2;
	cout << "double *jp = " << djp << endl;

	int jp5 = *jp + 5;
	cout << "*jp + 5 = " << jp5 << endl;

	ip = new int(*jp * 7);
	cout << "ip (*jp x 7) = " << ip <<endl;

	delete ip;
	delete jp;
}