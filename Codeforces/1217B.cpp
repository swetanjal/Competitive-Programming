#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n, x, d, h;
        cin >> n >> x;
        long long res = 1e18;
        for(int i = 1; i <= n; ++i){
            cin >> d >> h;
            long long low = 1; long long high = 1e9;
            long long mid; long long pos = -1;
            while(high >= low)
            {
                mid = (high + low) / 2;
                if((x - mid * d + (mid - 1) * h) <= 0){
                    pos = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if(pos!=-1)
                res = min(res, pos);
        }
        if(res == 1e18)
            cout << "-1\n";
        else
        {
            cout << res << endl;
        }
        
    }
    return 0;
}