#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int T, N;
int A[MAXN];
int next_greater[MAXN];
int next_greater_[MAXN];
int DP[MAXN];
int DP2[MAXN];
int DP3[MAXN];
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        stack <int> S;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        if(N == 1)
        {
            cout << "1\n";
            continue;
        }
        for(int i = 0; i < N; ++i)
            next_greater_[i] = next_greater[i] = -1;
        S.push(0);
        stack <int> Q;
        for(int i = 1; i < N; ++i){
            while(Q.empty() == false && A[Q.top()] <= A[i]){
                next_greater_[Q.top()] = i;
                Q.pop();
            }
            vector <int> tmp;
            while(S.empty() == false && A[S.top()] <= A[i]){
                next_greater[S.top()] = i;
                tmp.push_back(S.top());
                //Q.push(S.top());
                S.pop();
            }
            int L = tmp.size();
            for(int i = L - 1; i >= 0; i--)
                Q.push(tmp[i]);
            S.push(i);
        }
        for(int i = N - 1; i >= 0; i--)
        {
            if(next_greater[i] != -1)
                DP[i] = 1 + DP[next_greater[i]];
            else
                DP[i] = 1;
        }
        int res = 0;
        DP2[0] = 1;
        DP3[0] = 0;
        stack <int> P;
        P.push(0);
        for(int i = 1; i < N; ++i)
        {
            if(A[P.top()] <= A[i])
                P.push(i);
            DP2[i] = P.size();
            DP3[i] = P.top();
        }
        res = max(DP[0], DP[1]);
        //for(int i = 0; i < N; ++i)
        //    res = max(res, DP[i]);
        //for(int i = 0; i < N; ++i)
        //    res = max(res, DP2[i]);
        for(int i = 1; i < N; ++i)
        {
            if(next_greater[DP3[i - 1]] != -1 && next_greater[DP3[i - 1]] != i)
                res = max(res, DP2[i - 1] + DP[next_greater[DP3[i - 1]]]);
            else if(next_greater_[DP3[i - 1]] != -1)
                res = max(res, DP2[i - 1] + DP[next_greater_[DP3[i - 1]]]);
            else
                res = max(res, DP2[i - 1]);
        }
        cout << res << endl;
    }
    return 0;
}