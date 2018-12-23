#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int main()
{
    long long int N, K;
    cin >> N >> K;
    long long int res = 1000000000000000000;
    for(int i = 1; i * i <= N; ++i){
        if((N % i) == 0)
        {
            long long rem = i;
            long long q = N / i;
            
            long long x = q * K;
            for(long long int j = x; (j / K) == q; j++)
            {
                if((j / K) * (j % K) == N)
                res = min(res, j);
            }

            rem = N / i;
            q = i;
            x = q * K;
            for(long long int j = x; (j / K) == q; j++)
            {
                if((j / K) * (j % K) == N)
                res = min(res, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}