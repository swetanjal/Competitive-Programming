#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1000000007;
const int MAXN = 1000005;
long long p[MAXN];
int T, N, K;
string S;
int main()
{
    p[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        p[i] = (p[i - 1] * 2) % MOD;
    cin >> T;
    int cases = 1;
    while(T--){
        cin >> N >> K;
        int cum = 0;
        long long res = 0;
        cin >> S;
        for(int i = (N - 1); i >= 0; --i){
            if(S[i] == 'A')
                cum--;
            else if(S[i] == 'B')
                cum++;
            if(cum == (K + 1)){
                cum -= 2;
                res = (res + p[i + 1]) % MOD;
            }
            cum = max(0, cum);
        }
        cout << "Case #" << cases<<": " << res << endl;
        cases++;
    }
    return 0;
}