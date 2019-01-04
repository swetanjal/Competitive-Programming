#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int DP[N];
    if(S[N - 1] == 'G')
        DP[N - 1] = 1;
    else
        DP[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--)
    {
        if(S[i] == 'G')
            DP[i] = 1 + DP[i + 1];
        else
            DP[i] = 0;
    }    
    int dp[N];
    if(S[0] == 'G')
        dp[0] = 1;
    else
        dp[0] = 0;
    for(int i = 1; i < N; ++i)
    {
        if(S[i] == 'G')
            dp[i] = 1 + dp[i - 1];
        else
            dp[i] = 0;
    }
    int first = -1;
    int last = -1;
    
    for(int i = 0; i < N; ++i){
        if(S[i] == 'G'){
            first = i;
            break;
        }
    }
    for(int i = N - 1; i >= 0; --i){
        if(S[i] == 'G'){
            last = i;
            break;
        }
    }
    if(first == -1)
    {
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        if(S[i] == 'G')
            cnt++;
    }
    if(cnt == N){
        cout << N << endl;
        return 0;
    }
    int res = 0;
    for(int i = 0; i < N; ++i){
        if(S[i] == 'S'){
            if(i == 0){
                if(last > (i + DP[i + 1]))
                    res = max(res, DP[i + 1] + 1);
                else
                    res = max(res, DP[i + 1]);
            }
            else if(i == (N - 1)){
                if(first < (i - dp[i - 1]))
                    res = max(res, dp[i - 1] + 1);
                else
                    res = max(res, dp[i - 1]);
            }
            else
            {
                if(first < (i - dp[i - 1]) || last > (i + DP[i + 1]))
                    res = max(res, dp[i - 1] + DP[i + 1] + 1);
                else
                    res = max(res, dp[i - 1] + DP[i+ 1]);
            }
        }
    }
    cout << res << endl;
    return 0;
}