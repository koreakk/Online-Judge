#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int mn = min(a, min(b, c));
	int mx = max(a, max(b, c));

	cout << a + b + c - mn - mx << '\n';
	return 0;
}