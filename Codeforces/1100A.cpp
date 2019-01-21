#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int A[N];
    int test = 0;
    int social = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i] == 1)
            test++;
        else
            social++;
    }
    int res = 0;
    for(int i = 0; i < K; ++i){
        int tmp_social = social;
        int tmp_test = test;
        for(int j = i; j < N; j += K){
            if(A[j] == -1)
                tmp_social--;
            else
                tmp_test--;
        }
        res = max(res, abs(tmp_social - tmp_test));
    }
    cout << res << "\n";
    return 0;
}