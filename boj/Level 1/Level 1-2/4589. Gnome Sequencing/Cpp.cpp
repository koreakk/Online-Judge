#include <iostream>
using namespace std;

int main() {
	cout << "Gnomes:\n";

	int T;
	cin >> T;

	while (T--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		if ((n1 <= n2 && n2 <= n3) || (n1 >= n2 && n2 >= n3)) {
			cout << "Ordered\n";
		}
		else {
			cout << "Unordered\n";
		}
	}

	return 0;
}