#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e4 + 5;
int T;
int N; long long K;
long long A[MAXN];
long long s = 0;
long long MIN;
bool chk(long long m)
{
    long long res = min(MIN, s / K);
    long long tmp[N];
    for(int i = 0; i < N; ++i)
        tmp[i] = A[i];
    long long int cnt = 0;
    for(int i = 0; i < (N - 1); ++i){
        long long a = (tmp[i] + tmp[i + 1]) / m;
        cnt += a;
        
        long long to_be_sub = a * m;
        long long sub = min(tmp[i], to_be_sub);
        tmp[i] -= sub;
        tmp[i + 1] -= (to_be_sub - sub);
    }
    if(cnt >= K)
        return true;
    if(res >= m)
        return true;
    return false;
}


int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        s = 0;
        MIN = 1e18;
        for(int i = 0; i < N; ++i){
            cin >> A[i];
            s += A[i];
            MIN = min(MIN, A[i]);
        }
        long long int low = 1; long long int high = ceil(s * 1.0 / K);
        long long mid;
        long long pos = 0;
        while(high >= low)
        {
            mid = (high + low) / 2;
            if(chk(mid)){
                pos = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << (K * 1LL * pos) << endl;
    }
    return 0;
}