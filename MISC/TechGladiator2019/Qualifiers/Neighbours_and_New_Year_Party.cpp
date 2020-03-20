#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e4 + 5;
int T, N;
int A[MAXN];
long long DP[MAXN][2];

long long rec(int idx, int flag){
    if(idx == N)
        return DP[idx][flag] = 0;
    if(DP[idx][flag] != -1)
        return DP[idx][flag];
    if(flag == 0)
        return DP[idx][flag] = max(A[idx] + rec(idx + 1, 1), rec(idx + 1, 0));
    return DP[idx][flag] = rec(idx + 1, 0);
}

void print(int idx, int flag){
    if(idx == N)
        return;
    if(flag == 0 && ((DP[idx + 1][1] + A[idx]) > DP[idx + 1][0]))
    {
        cout << A[idx];
        print(idx + 1, 1);
    }
    if(flag == 0 && ((DP[idx + 1][1] + A[idx]) < DP[idx + 1][0])){
        print(idx + 1, 0);
    }
    if(flag == 0 && ((DP[idx + 1][1] + A[idx]) == DP[idx + 1][0])){
        if(A[idx] == 0)
        {
            print(idx + 1, 0);
        }
        else if(A[idx] > A[idx + 1]){
            cout << A[idx];
            print(idx + 1, 1);
        }
        else{
            print(idx + 1, 0);
        }
    }
    if(flag == 1){
        print(idx + 1, 0);
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> N;
        int cnt = N - 1;
        for(int i = 0; i < N; ++i)
            cin >> A[cnt--];
        for(int i = 0; i < N; ++i){
            DP[i][0] = DP[i][1] = -1;
        }
        int all_neg = 1;
        for(int i = 0; i < N; ++i){
            if(A[i] > 0)
                all_neg = 0;
        }
        if(all_neg == 1){
            long long ans = LONG_LONG_MIN;
            for(int i = 0; i < N; ++i)
                ans = max(ans, A[i] * 1LL);
            cout << ans << endl;
        }
        else{
            rec(0, 0);
            print(0, 0);
            cout << endl;
        }
    }
    return 0;
}