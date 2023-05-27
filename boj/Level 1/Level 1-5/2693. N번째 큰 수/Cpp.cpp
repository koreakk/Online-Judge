#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, A[10];
	cin >> t;
	while (t--) {
		for (int i = 0; i < 10; ++i) {
			cin >> A[i];
		}
		sort(A, A + 10);
		cout << A[7] << '\n';
	}
	return 0;
}