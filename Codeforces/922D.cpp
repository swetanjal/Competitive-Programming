#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
long long int N, K;
long long A[MAXN];
int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int l = 0;
    int r = 0;
    long long p = A[0];
    long long s = A[0];
    long long res = 0;
    while(l <= r && r < N){
        while(r < (N - 1) && (p * 1.0/ s) < K){
            r++;
            s += A[r];
            p *= A[r];
            cout << (p *1.0/ s) << endl;
        }
        //cout << (p/s) << endl;
        //cout << l << " " << r << endl;
        if((p * 1.0 / s) == K)
            res++;
        l++;
        p = p / A[l - 1];
        s = s - A[l - 1];
    }
    cout << res << endl;
    return 0;
}