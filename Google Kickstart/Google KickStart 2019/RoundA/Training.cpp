#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
long long A[MAXN];
long long B[MAXN];
long long DP[MAXN];
int N, P, T;
int main()
{
    cin >> T;
    int cases = 1;
    while(T--)
    {
        cin >> N >> P;
        for(int i = 0; i < N; ++i)
            cin >> B[i];
        sort(B, B + N);
        for(int i = 1; i <= N; ++i)
            A[i] = B[i - 1];
        DP[0] = 0;
        for(int i = 1; i < P; ++i)
            DP[i] = DP[i - 1] + A[i];
        long long ans = LONG_LONG_MAX;
        for(int i = P; i <= N; ++i)
        {
            DP[i] = DP[i - 1] + A[i];
            ans = min(ans, (A[i] * (P - 1)) - (DP[i] - DP[i - P] - A[i]));
        }
        cout << "Case #" << cases << ": " << ans << endl;
        cases++;
    }
    return 0;
}