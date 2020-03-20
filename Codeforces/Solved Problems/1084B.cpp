#include "bits/stdc++.h"
using namespace std;
long long A[1005];
int N;
long long int S;
bool chk(long long K)
{
    long long sum = 0;
    for(int i = 0; i < N; ++i)
    {
        if(A[i] < K)
            return false;
        else 
        sum = sum + abs(A[i] - K);
    }
    if(sum >= S)
        return true;
    return false;
}
int main()
{
    
    cin >> N >> S;
    
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    long long low = 0;
    long long high = 1000000000000;
    long long mid;
    long long ans = -1;
    while(high >= low)
    {
        mid = (high+ low) / 2;
        if(chk(mid))
        {
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}