#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for_each(s.begin(), s.end(), [](char& ch) {
		if ('A' <= ch && ch <= 'Z') {
			ch = 'A' + (ch - 'A' + 13) % 26;
		} 
		else if ('a' <= ch && ch <= 'z') {
			ch = 'a' + (ch - 'a' + 13) % 26;
		}
	});

	cout << s << '\n';

	return 0;
}