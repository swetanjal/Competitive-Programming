#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    long long ans = 0;
    for(int i = N - 2; i >= 0; i--)
        A[i] = min(A[i], A[i + 1] - 1);
    for(int i = 0; i < N; ++i)
        ans = ans + max(A[i], 0LL);
    cout << ans << endl;
    return 0;
}