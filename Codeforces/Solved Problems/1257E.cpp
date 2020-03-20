#include "bits/stdc++.h"
using namespace std;

int main()
{
    int K1, K2, K3;
    cin >> K1 >> K2 >> K3;
    int A[K1], B[K2], C[K3];
    for(int i = 0; i < K1; ++i)
        cin >> A[i];
    for(int i = 0; i < K2; ++i)
        cin >> B[i];
    for(int i = 0; i < K3; ++i)
        cin >> C[i];
    int N = K1 + K2 + K3 + 2;
    int DP1[N];
    int DP3[N];
    int freq[N];
    int freq2[N];
    for(int i = 0; i < N; ++i)
        freq2[i] = freq[i] = DP1[i] = DP3[i] = 0;

    for(int i = 0; i < K1; ++i){
        DP1[A[i]] += 1;
        freq[A[i]] += 1;
    }
    for(int i = 0; i < K3; ++i){
        DP3[C[i]] += 1;
        freq2[C[i]] += 1;
        
    }
    for(int i = 1; i < N; ++i){
        DP1[i] += DP1[i - 1];
        freq2[i] += freq2[i - 1];
    }
    for(int i = N - 2; i >= 0; --i){
        DP3[i] += DP3[i + 1];
        freq[i] += freq[i + 1];
    }
    for(int i = 0; i < N; ++i){
        DP1[i] = (K1 - DP1[i]) + (i - DP1[i]) - freq2[i];
        //cout << DP1[i] << " ";
    }
    //cout << endl;

    for(int i = 0; i < N; ++i){
        DP3[i] = ((K1 + K2 + K3) - i + 1) - DP3[i] + (K3 - DP3[i])- freq[i];
        //cout << DP3[i] << " ";
    }
    //cout << endl;
    for(int i = 1; i < N; ++i)
        DP1[i] = min(DP1[i], DP1[i - 1]);
    for(int i = (N - 2); i >= 0; --i)
        DP3[i] = min(DP3[i], DP3[i + 1]);
    long long ans = 1000000000000;
    for(int i = 0; i < N - 1; ++i){
        ans = min(ans, 1LL * (DP1[i] + DP3[i + 1]));
    }
    cout << ans << endl;
    return 0;
}