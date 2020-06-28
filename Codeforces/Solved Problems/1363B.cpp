#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        string S;
        cin >> S;
        N = S.size();
        int a1 = 0;
        int cum0[N];
        int cum1[N];
        for(int i = 0; i < N; ++i)
            cum0[i] = cum1[i] = 0;
        if(S[0] == '1')
            cum1[0] = 1;
        else
            cum0[0] = 1;
        for(int i = 1; i < N; ++i){
            cum0[i] = cum0[i - 1] + (S[i] == '0' ? 1 : 0);
            cum1[i] = cum1[i - 1] + (S[i] == '1' ? 1 : 0);
        }
        int res = N;
        for(int i = 0; i < N; ++i){
            // Till here it is 0.
            res = min(res, cum1[i] + cum0[N - 1] - cum0[i]);
            // Till here it is 1.
            res = min(res, cum0[i] + cum1[N - 1] - cum1[i]);
        }
        cout << res << endl;
    }
    return 0;
}