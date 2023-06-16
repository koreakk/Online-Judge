#include <iostream>
using namespace std;

int main() {
	for (int i = 1;; ++i) {
		int l, p, v;
		cin >> l >> p >> v;
		
		if (v == 0) {
			break;
		}

		cout << "Case " << i << ": ";
		cout << v / p * l + min(v % p, l) << '\n';
	}
	return 0;
}