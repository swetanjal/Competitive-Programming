#include "bits/stdc++.h"
using namespace std;

int main()
{
    char x, y;
    cin >> x >> y;
    int flag = 0;
    for(int i = 1; i <= 5; ++i){
        char X, Y;
        cin >> X >> Y;
        if(x == X || y == Y){
            flag = 1;
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}