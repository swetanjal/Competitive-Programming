#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
const long long MOD = 1e9 + 7;
pair < long long int, long long int > A[MAXN];
long long int DP_MIN[MAXN];
long long int DP_MIN_CUM[MAXN];
long long int F[MAXN];
int idx[MAXN];
int N;
long long MX;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i].first >> A[i].second;
        MX = max(MX, A[i].second);
    }
    sort(A, A + N);
    DP_MIN[0] = A[0].second - A[0].first;
    DP_MIN_CUM[0] = DP_MIN[0];
    F[0] = 1;
    idx[0] = -1;
    for(int i = 1; i < N; ++i){
        int low = 0; int high = N - 1;
        int mid; int pos = -1;
        while(high >= low)
        {
            mid = (high + low) / 2;
            if(A[mid].first <= A[i].second){
                pos = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(pos == -1)
            DP_MIN[i] = A[i].second - A[i].first;
        else
            DP_MIN[i] = A[i].second - A[i].first + DP_MIN_CUM[pos];
        idx[i] = pos;
        if(DP_MIN[i] == DP_MIN_CUM[i - 1]){
            if(pos != -1)
            F[i] = (F[i - 1] + F[pos]) % MOD;
            else
            F[i] = (F[i - 1] + 1) % MOD;
        }
        else if(DP_MIN[i] > DP_MIN_CUM[i - 1]){
            F[i] = F[i - 1];
        }
        else{
            if(pos != -1)
            F[i] = F[pos];
            else
            F[i] = 1;
        }
        DP_MIN_CUM[i] = min(DP_MIN_CUM[i - 1], DP_MIN[i]);
    }
    long long res = 0;
    vector <long long> a;
    vector <long long> add;
    for(int i = 0; i < N; ++i){
        if(A[i].first <= MX){
            continue;
        }
        if(idx[i] == -1)
        {
            a.push_back(A[i].second);
            add.push_back(1);
        }
        else{
            a.push_back(A[i].second + DP_MIN_CUM[idx[i]]);
            add.push_back(F[idx[i]]);
        }
    }
    long long sm = LONG_LONG_MAX;
    for(int i = 0; i < a.size(); ++i){
        sm = min(sm, a[i]);
    }
    for(int i = 0; i < a.size(); ++i)
    {
        if(sm == a[i])
            res = (res + add[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}