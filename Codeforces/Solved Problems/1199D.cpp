#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
long long A[MAXN];
long long DP[MAXN];
int lst[MAXN];
int N, Q;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        lst[i] = -1;
    cin >> Q;
    for(int i = 0; i < Q; ++i)
        DP[i] = LONG_LONG_MIN;
    int cnt = 0;
    while(Q--){
        int key, p;
        long long x;
        cin >> key;
        if(key == 1){
            cin >> p >> x;
            lst[p - 1] = cnt;
            A[p - 1] = x;
        }
        else{
            cin >> x;
            DP[cnt] = x;
        }
        cnt++;
    }
    for(int i = cnt - 2; i >= 0; --i)
        DP[i] = max(DP[i + 1], DP[i]);
    for(int i = 0; i < N; ++i){
        if(lst[i] == -1)
            cout << max(DP[0], A[i]) << " ";
        else
            cout << max(A[i], DP[lst[i]]) << " ";
    }
    cout << endl;
    return 0;
}