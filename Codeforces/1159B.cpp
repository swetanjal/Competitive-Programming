#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    long long res = LONG_LONG_MAX;
    for(int i = 0; i < N; ++i){
        // check with 0th element
        if(i != 0){
            res = min(res, min(A[i], A[0]) / i);
        }
        // check with N-1th element
        if(i != (N - 1)){
            res = min(res, min(A[i], A[N - 1]) / abs(N - 1 - i));
        }
    }
    cout << res << endl;
    return 0;
}