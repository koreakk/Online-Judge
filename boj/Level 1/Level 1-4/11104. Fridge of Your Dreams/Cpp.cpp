#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int l = (int)s.length();
		int ret = 0, d = 1;
		
		while(l--) {
			if (s[l] == '1') {
				ret += d;
			}
			d *= 2;
		}

		cout << ret << '\n';
	}
	
	return 0;
}