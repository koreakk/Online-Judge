#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	string s = to_string(N);
	int l = static_cast<int>(s.length());

	for (int i = 0; i < M && i < N * l; ++i) {
		cout << s[i % l];
	}
	cout << '\n';

	return 0;
}