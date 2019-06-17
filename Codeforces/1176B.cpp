#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
int T, N;
long long int A[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        long long f[3];
        f[0] = 0; f[1] = 0; f[2] = 0;
        for(int i = 0; i < N; ++i){
            cin >> A[i];
            f[A[i] % 3]++;
        }
        long long res = f[0] + min(f[2], f[1]) + ((f[2] - min(f[2], f[1])) / 3) + ((f[1] - min(f[2], f[1])) / 3);
        //res = max(res, min(f[1] % 3, f[2] % 3)+ (f[1] / 3) + (f[2] / 3) + f[0]);
        cout << res << endl;
        //cout << (f[0] + max(max(f[1], f[2]), max(f[1] / 3, f[2] / 3))) << endl;
    }
    return 0;
}