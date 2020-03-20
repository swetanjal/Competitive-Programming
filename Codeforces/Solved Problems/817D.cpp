#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int N;
long long int A[MAXN];
long long int DP1[MAXN];
long long int DP2[MAXN];
long long int DP3[MAXN];
long long int DP4[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];

    for(int i = 0; i < N; ++i)
        DP1[i] = N, DP2[i] = -1, DP3[i] = N, DP4[i] = -1;
    stack < pair < int, int > > S;
    for(int i = 0; i < N; ++i){
        while(S.empty() == false && S.top().first <= A[i]){
            DP1[S.top().second] = i;
            S.pop();
        }
        S.push({A[i], i});
    }
    while(S.empty() == false)
        S.pop();
    for(int i = N - 1; i >= 0; --i){
        while(S.empty() == false && S.top().first < A[i]){
            DP2[S.top().second] = i;
            S.pop();
        }
        S.push({A[i], i});
    }
    while(S.empty() == false)
        S.pop();
    
    for(int i = 0; i < N; ++i){
        while(S.empty() == false && S.top().first >= A[i]){
            DP3[S.top().second] = i;
            S.pop();
        }
        S.push({A[i], i});
    }
    while(S.empty() == false)
        S.pop();
    for(int i = N - 1; i >= 0; --i){
        while(S.empty() == false && S.top().first > A[i]){
            DP4[S.top().second] = i;
            S.pop();
        }
        S.push({A[i], i});
    }
    long long ans = 0;
    for(int i = 0; i < N; ++i)
    {
        long long l = (i - (DP2[i] + 1) + 1) * 1LL * ((DP1[i] - 1) - i + 1) * A[i];
        ans = ans + l;
    }
    for(int i = 0; i < N; ++i)
    {
        long long l = (i - (DP4[i] + 1) + 1) * 1LL * ((DP3[i] - 1) - i + 1) * A[i];
        ans = ans - l;
    }
    cout << ans << endl;
    return 0;
}