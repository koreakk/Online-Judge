#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	cout << count(s.begin(), s.end(), ',') + 1 << '\n';
	return 0;
}