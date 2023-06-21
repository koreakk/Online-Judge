#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string n;
		int g;

		cin >> n >> g;

		cout << n << ' ';
		if      (g >= 97) { cout << "A+\n"; }
		else if (g >= 90) { cout << "A\n";  }
		else if (g >= 87) { cout << "B+\n"; }
		else if (g >= 80) { cout << "B\n";  }
		else if (g >= 77) { cout << "C+\n"; }
		else if (g >= 70) { cout << "C\n";  }
		else if (g >= 67) { cout << "D+\n"; }
		else if (g >= 60) { cout << "D\n";  }
		else              { cout << "F\n";  }
	}
	
	return 0;
}