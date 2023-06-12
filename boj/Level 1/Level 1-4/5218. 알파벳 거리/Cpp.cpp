#include <iostream>
using namespace std;

#define D(x) (int)(x - 'A' + 1)

int main() {
	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;

		int l = (int)a.length();
		
		cout << "Distances:";
		for (int i = 0; i < l; ++i) {
			int x = D(b[i]) - D(a[i]);
			if (x < 0) { x += 26; }

			cout << ' ' << x;
		}
		cout << '\n';
	}
	return 0;
}