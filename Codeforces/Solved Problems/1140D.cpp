#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    long long res = 0;
    for(int i = 2; i < N; ++i){
        res = res + i * 1LL * (i + 1);
    }
    cout << res << endl;
    return 0;
}