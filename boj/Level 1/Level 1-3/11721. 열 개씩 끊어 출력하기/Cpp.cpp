#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		if (i % 10 == 0 && i != 0) {
			cout << '\n';
		}
		cout << s[i];
	}

	return 0;
}