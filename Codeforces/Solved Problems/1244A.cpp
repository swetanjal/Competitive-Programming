#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int x = ceil(a * 1.0 / c);
        int y = ceil(b * 1.0 / d);
        if((x + y) <= e){
            cout << x << " " << y << endl;
        }
        else
            cout << "-1\n";
    }
    return 0;
}