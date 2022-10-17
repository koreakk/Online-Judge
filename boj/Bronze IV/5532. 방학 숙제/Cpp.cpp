#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	
	cout << l - max((a + c - 1) / c, (b + d - 1) / d) << endl;
	return 0;
}