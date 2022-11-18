#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string name;
    int age, weight;
    
    while (true) {
        cin >> name;
        cin >> age >> weight;
        
        if (name == "#") {
            break;
        }
        
        cout << name;
        
        if (age > 17 || weight >= 80) {
            cout << " Senior" << endl;
        } else {
            cout << " Junior" << endl;
        }
    }
    
    return 0;
}