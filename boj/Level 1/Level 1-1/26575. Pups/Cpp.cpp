#include <iostream>
using namespace std;

int main() {
	cout << fixed;
	cout.precision(2);

	int t;
	cin >> t;

	while (t--) {
		double a, b, c;
		cin >> a >> b >> c;

		cout << "$" << a * b * c << '\n';
	}
}