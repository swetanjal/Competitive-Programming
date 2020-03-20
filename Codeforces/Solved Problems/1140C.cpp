#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
pair <long long, long long> A[MAXN];
multiset <long long> S;
long long sum = 0;
long long DP[MAXN];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        A[i] = make_pair(y, x);
    }
    if(K == 1){
        for(int i = 0; i < N; ++i)
            ans = max(ans, A[i].second * A[i].first);
        cout << ans << endl;
        return 0;
    }
    sort(A, A + N);
    
    for(int i = N - 1; i >= 0; i--){
        if(S.size() < (K - 1)){
            S.insert(A[i].second);
            sum += A[i].second;
        }
        else{
            long long first = *(S.begin());
            if(A[i].second > first)
            {
                S.erase(S.begin());
                sum -= first;
                sum += A[i].second;
                S.insert(A[i].second);
            }
        }
        DP[i] = sum;
    }
    for(int i = 0; i < N - 1; ++i)
        ans = max(ans, (DP[i + 1] + A[i].second) * A[i].first);
    for(int i = 0; i < N; ++i)
        ans = max(ans, A[i].second * A[i].first);
    cout << ans << endl;
    return 0;
}