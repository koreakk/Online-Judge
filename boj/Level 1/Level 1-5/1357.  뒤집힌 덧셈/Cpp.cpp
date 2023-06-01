#include <iostream>
using namespace std;

int Rev(int x) {
	int ret = 0;
	while (x) {
		ret *= 10;
		ret += (x % 10);
		x /= 10;
	}
	return ret;
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << Rev(Rev(x) + Rev(y)) << '\n';
	return 0;
}