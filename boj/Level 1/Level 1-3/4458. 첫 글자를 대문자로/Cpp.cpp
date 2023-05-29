#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	getchar();
	while (n--) {
		getline(cin, str);
		if (str[0] >= 'a' && str[0] <= 'z') {
			str[0] -= 32;
		}
		cout << str << '\n';
	}
	return 0;
}