#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	cout << max(a + d, b + c);
	return 0;
}