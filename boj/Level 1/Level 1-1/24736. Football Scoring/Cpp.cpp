#include <iostream>
using namespace std;

int main(void)
{
    for (int i = 2; i > 0; --i) {
        int t, f, s, p, c;
        cin >> t >> f >> s >> p >> c;
        
        cout << 6*t + 3*f + 2*s + p + 2*c << endl;
    }
    return 0;
}