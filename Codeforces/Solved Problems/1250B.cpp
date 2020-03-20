#include "bits/stdc++.h"
using namespace std;
const int MAXK = 8005;
int A[MAXK];
int N, K;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; ++i){
        int u;
        cin >> u;
        A[u - 1]++;
    }
    sort(A, A + K, cmp);
    long long int res = 100000000000000000;
    for(int i = 1; i <= K; ++i){
        // Fixing r.
        int idx = 2 * i - K;
        if(idx < 0)
            continue;
        int l = idx; int r = K - 1;
        int mx = A[0];
        while(l <= r)
        {
            mx = max(mx, A[l] + A[r]);
            l++;
            r--;
        }
        //cout << mx << endl;
        res = min(res, mx * 1LL *i);
    }
    cout << res << endl;
    return 0;
}