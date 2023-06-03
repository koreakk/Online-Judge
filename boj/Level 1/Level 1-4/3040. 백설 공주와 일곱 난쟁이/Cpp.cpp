#include <iostream>
using namespace std;

int main() {
	int A[9], n = -100;
	for (int& p : A) {
		cin >> p;
		n += p;
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (A[i] + A[j] != n) { continue; }

			for (int k = 0; k < 9; ++k) {
				if (k == i || k == j) { continue; }
				cout << A[k] << '\n';
			}
			exit(EXIT_SUCCESS);
		}
	}

	exit(EXIT_FAILURE);
}