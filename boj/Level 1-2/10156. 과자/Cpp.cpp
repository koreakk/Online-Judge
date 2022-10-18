#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	
	int k, n, m;
	cin >> k >> n >> m;
	
	cout << max(k * n - m, 0) << endl;
	return 0;
}