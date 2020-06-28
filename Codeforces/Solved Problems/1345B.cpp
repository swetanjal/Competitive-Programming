#include "bits/stdc++.h"
using namespace std;

long long int sum(long long int a){
    return a * 1LL * (a + 1) / 2;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int N;
        cin >> N;
        long long int ans = 0;
        while(N > 0){
            long long int low = 0;
            long long int high = N;
            long long int mid;
            long long int res = -1;
            long long int sub = 0;
            while(high >= low){
                mid = (high + low) / 2;
                long long tmp = (3 * 1LL * sum(mid) - mid);
                if(tmp <= N){
                    res = mid;
                    sub = tmp;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(sub == 0)
                break;
            N = N - sub;
            ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}