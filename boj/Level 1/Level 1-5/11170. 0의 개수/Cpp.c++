#include <iostream>
using namespace std;

int count_zero(int x) {
	int ret = 0;
	do {
		if (x % 10 == 0) {
			++ret;
		}
		x /= 10;
	} while (x);

	return ret;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int ret = 0;
		for (int i = n; i <= m; ++i) {
			ret += count_zero(i);
		}
		cout << ret << '\n';
	}

	return 0;
}