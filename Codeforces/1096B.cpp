#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
int main()
{
    int L;
    cin >> L;
    char A[L];
    for(int i = 0; i < L; ++i)
        cin >> A[i];
    long long res = 0;
    if(A[0] == A[L - 1])
    {
        long long beg = 1;
        for(int i = 1; i < L; ++i)
        {
            if(A[i] == A[i - 1])
                beg++;
            else break;
        }
        long long en = 1;
        for(int i = L - 2; i >= 0; i--)
        {
            if(A[i] == A[i + 1])
                en++;
            else break;
        }
        long long ans = (((beg + 1) % MOD) * ((en + 1) % MOD)) % MOD;
        cout << ans << endl;
    }
    else{
        long long beg = 1;
        for(int i = 1; i < L; ++i)
        {
            if(A[i] == A[i - 1])
                beg++;
            else break;
        }
        
        long long en = 1;
        for(int i = L - 2; i >= 0; i--)
        {
            if(A[i] == A[i + 1])
                en++;
            else break;
        }
        long long ans = (beg + en + 1) % MOD;
        cout << ans << endl;
    }
    return 0;
}