#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int A[K + 1];
    for(int i = 1; i <= K; ++i)
        A[i] = 0;
    for(int i = 1; i <= N; ++i){
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }
    int rem = 0;
    int res = 0;
    for(int i = 1; i <= K; ++i){
        rem = rem + (A[i] % 2);
        if((A[i] % 2) == 0)
            res = res + A[i];
        else
            res = res + (A[i] - 1);
    }
    res = res + ceil(rem * 1.0 / 2);
    cout << res << endl;
    return 0;
}