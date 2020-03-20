#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int DP[N];
    DP[0] = 1;
    int prev;
    cin >> prev;
    for(int i = 1; i < N; ++i){
        int tmp;
        cin >> tmp;
        if(tmp != prev)
        {
            DP[i] = DP[i - 1] + 1;
        }
        else{
            DP[i] = 1;
        }
        prev = tmp;
    }
    int res = 0;
    for(int i = 0; i < N; ++i)
        res = max(res, DP[i]);
    cout << res << endl;
    return 0;
}