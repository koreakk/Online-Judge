#include <iostream>
using namespace std;

int main(void) {
	char str[4] = { 0 };
	cin >> str;
	
	swap(str[0], str[2]);
	cout << str << endl;
	
	return 0;
}