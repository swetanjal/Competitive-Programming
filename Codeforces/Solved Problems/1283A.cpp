#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int h, m;
        cin >> h >> m;
        if(h == 0 && m == 0)
        {
            cout << 0 << endl;
            continue;
        }
        long long int rem = 23 - h;
        long long int min = 60 - m;
        cout << (rem * 60 + min) << endl;
    }
    return 0;
}