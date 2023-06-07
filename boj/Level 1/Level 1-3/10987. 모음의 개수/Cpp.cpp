#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int ret = 0;
	for (char c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++ret;
		}
	}

	cout << ret << '\n';
	return 0;
}