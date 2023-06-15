#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << pow((n + 1) / 2, 2) << '\n';
	}
	return 0;
}