#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	if (n == 2 && m == 18) {
		cout << "Special\n";
	}
	else if (n < 2 || (n == 2 && m < 18)) {
		cout << "Before\n";
	}
	else {
		cout << "After\n";
	}

	return 0;
}