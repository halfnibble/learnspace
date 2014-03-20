#include <iostream>

long double factorial(long n) {
	long double ans = 1;
	for (long i = 2; i <= n; ++i) {
		ans = ans * i;
		if (ans < 0) {
			return -1;
		}
	}
	return ans;
}

int main() {
	using namespace std;
	cout << "Please enter n: " << flush;
	long n;
	if (cin >> n && n < 1001) {
		if (n >= 0) {
			long double nfact = factorial(n);
			if (nfact < 0) {
				cerr << "overflow error: "
					<< n << " is too big." << endl;
			} else {
				cout << "factorial(" << n << ") = "
				<< nfact << endl;
			}
		} else {
			cerr << "Undefined: "
				<< "factorial of a negative number: " << n << endl;
		}
	} else {
		cerr << "You entered a number too large. Please enter a number of 1,000 or less." << endl;
	}
	
	return 0;
}