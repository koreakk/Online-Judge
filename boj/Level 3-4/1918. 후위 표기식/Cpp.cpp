#include <bits/stdc++.h>
using namespace std;

string solve(string expression) {
	stack<char> s;
	string result;

	for (auto x : expression) {
		if (x == '+' || x == '-') {
			while (!s.empty() && s.top() != '(') {
				result += s.top();
				s.pop();
			}
		} else if (x == '*' || x == '/') {
			while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
				result += s.top();
				s.pop();
			}
		} else if (x == ')') {
			while (s.top() != '(') {
				result += s.top();
				s.pop();
			}
			
			s.pop();
			continue;
		}
		s.push(x);
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	return result;
}

int main(void) {
	string expression;
	cin >> expression;

	cout << solve(expression) << endl;
	return 0;
}