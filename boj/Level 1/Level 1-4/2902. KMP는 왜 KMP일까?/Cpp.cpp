#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	string ret;
	ret += s[0];
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '-') {
			ret += s[i + 1];
		}
	}

	cout << ret << '\n';
	return 0;
}