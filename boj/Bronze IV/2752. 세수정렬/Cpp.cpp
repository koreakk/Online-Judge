#include <bits/stdc++.h>
using namespace std;

#define SwapInt(a, b)	(a ^= b, b ^= a, a ^= b)

int main(void)
{
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	
	if (n1 > n2) {
		SwapInt(n1, n2);
	}
	if (n2 > n3) {
		SwapInt(n2, n3);
	}
	if (n1 > n2) {
		SwapInt(n1, n2);
	}
	
	cout << n1 << ' ' << n2 << ' ' << n3 << endl;
	
	return 0;
}