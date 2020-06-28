#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    int B[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        cin >> B[i];
    int idx1[N + 1];
    int idx2[N + 1];
    for(int i = 0; i < N; ++i){
        idx1[A[i]] = i;
        idx2[B[i]] = i;
    }
    int freq[N + 1];
    for(int i = 0; i <= N; ++i)
        freq[i] = 0;
    for(int i = 1; i <= N; ++i){
        if(idx1[i] <= idx2[i])
            freq[idx2[i] - idx1[i]]++;
        else
            freq[N - 1 - idx1[i] + idx2[i] + 1]++;
    }
    int res = 0;
    for(int i = 0; i <= N; ++i)
        res = max(res, freq[i]);
    cout << res << endl;
    return 0;
}