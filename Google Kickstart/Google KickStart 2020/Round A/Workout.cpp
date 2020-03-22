#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int T;
int N, K;
long long int A[MAXN];

bool chk(long long int S)
{
    long long s = 0;
    for(int i = 1; i < N; ++i){
        long long int diff = A[i] - A[i - 1];
        diff = ceil(diff * 1.0 / S) - 1;
        s += diff;
    }
    if(s <= K)
        return true;
    return false;
}


int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> N >> K;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        long long int low = 1; long long int high = 1e9;
        long long int mid; long long int res = -1;
        while(high >= low)
        {
            mid = (high + low) / 2;
            if(chk(mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << "Case #" << cases << ": " << res << endl;
    }
    return 0;
}