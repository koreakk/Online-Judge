#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr char VOWELS[] = "AEIOUaeiou";

int main() {
	int t;
	cin >> t;
	getchar();

	while (t--) {
		string s;
		getline(cin, s);

		int consonants = 0;
		int vowels     = 0;

		for (char ch : s) {
			if (('a' > ch || 'z' < ch) && ('A' > ch || 'Z' < ch)) {
				continue;
			}
			
			if (find(begin(VOWELS), end(VOWELS), ch) != end(VOWELS)) {
				++vowels;
			}
			else {
				++consonants;
			}
		}

		cout << consonants << ' ' << vowels << '\n';
	}
	
	return 0;
}