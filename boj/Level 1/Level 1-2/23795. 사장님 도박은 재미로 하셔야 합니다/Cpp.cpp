#include <iostream>
using namespace std;

int main() {
	int ret = 0, n;
	for (;;) {
		cin >> n;
		if (n == -1) {
			break;
		}
		ret += n;
	}
	cout << ret << '\n';
	return 0;
}