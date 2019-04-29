#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int N, M, R;
    cin >> N >> M >> R;
    long long int res = LONG_LONG_MAX;
    for(int i = 1; i <= N; ++i){
        long long int tmp;
        cin >> tmp;
        res = min(res, tmp);
    }
    long long int ret = LONG_LONG_MIN;
    for(int i = 1; i <= M; ++i){
        long long int tmp;
        cin >> tmp;
        ret = max(ret, tmp);
    }
    long long int shares = R / res;
    long long ans = shares * ret;
    cout << max(R, ans + (R % res)) << endl;
    return 0;
}