#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	int result[26] = { 0, };
	for (auto x : s) {
		++result[x - 'a'];
	}
	
	for_each(result, result + 26, [](int n) { cout << n << ' '; });
	cout << endl;
	return 0;
}