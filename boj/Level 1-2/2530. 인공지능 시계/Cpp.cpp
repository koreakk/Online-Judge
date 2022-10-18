#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int h, m, s;
	int t;
	
	cin >> h >> m >> s;
	cin >> t;
	
	int st = (s + t) % 60;
	int mt = (m + ((s + t) / 60)) % 60;
	int ht = (h + ((m + ((s + t) / 60)) / 60)) % 24;
	
	cout << ht << ' ' << mt << ' ' << st << endl;
	
	return 0;
}