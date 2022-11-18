#include <iostream>
using namespace std;

int main(void)
{ 
    int a, b;
    cin >> a >> b;
    
    cout << (int)(a * (100 - b) < 10000) << endl;
    
    return 0;
}