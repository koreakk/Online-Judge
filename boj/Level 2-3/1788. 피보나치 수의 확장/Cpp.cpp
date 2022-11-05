#include <iostream>
using namespace std;

long long fib(int n) {
    long long Tmp = 0;
    long long x = 0, y = 1;

    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            Tmp = (x + y) % 1000000000;
            x   = y;
            y   = Tmp;
        }
    } else {
        n *= -1;
        for (int i = 0; i < n; ++i) {
            Tmp = (x - y) % 1000000000;
            x   = y;
            y   = Tmp;
        }
    }

    return x;
}

int main(void)
{
    int n;
    cin >> n;

    long long result = fib(n);
    int x = result == 0 ? 0 :
            result >  0 ? 1 :
                         -1;
    cout << x << ' ' << abs(result) << endl;
    return 0;
}