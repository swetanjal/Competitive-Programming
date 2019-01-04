#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long N, X, Y, D;
        cin >> N >> X >> Y >> D;
        long long res = -1;
        if((Y - X) % D == 0)
        {
            res = abs((Y - X) / D);
        }
        if((Y - 1) % D == 0)
        {
            if(res == -1){
                res = abs((long long)ceil((X - 1) * 1.0 / D)) + (Y - 1) / D;
            }
            else
                res = min(res, abs((long long)ceil((X - 1) * 1.0 / D)) + (Y - 1) / D);
        }
        if((N - Y) % D == 0)
        {
            if(res == -1)
                res = abs((long long)ceil((N - X) * 1.0 / D)) + (N - Y) / D;
            else
                res = min(res, abs((long long)ceil((N - X) * 1.0 / D)) + (N - Y) / D);
        }
        cout << res << endl;
    }    
    return 0;
}