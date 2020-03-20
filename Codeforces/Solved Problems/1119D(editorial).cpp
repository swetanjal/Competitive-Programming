#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, Q;
long long A[MAXN];
long long cum[MAXN];
long long l, r;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);    
    for(int i = 0; i < N - 1; ++i)
        A[i] = A[i + 1] - A[i];
    sort(A, A + N - 1);
    cum[0] = A[0];
    for(int i = 1; i < N - 1; ++i)
        cum[i] = cum[i - 1] + A[i];
    cin >> Q;
    while(Q--){
        cin >> l >> r;
        long long len = r - l + 1;
        long long pos = -1;
        long long low = 0; long long high = N - 2; long long mid;
        while(high >= low){
            mid = (high + low) / 2;
            if(A[mid] <= len){
                low = mid + 1;
                pos = mid;
            }
            else{
                high = mid - 1;
            }
        }
        long long res = 0;
        if(pos != -1){
            res = cum[pos] + (N - 1 - pos) * len;
        }
        else{
            res = N * 1LL * len;
        }
        cout << res << endl;
    }
    return 0;
}