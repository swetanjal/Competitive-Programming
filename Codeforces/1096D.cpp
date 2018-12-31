#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    char S[N];
    for(int i = 0; i < N; ++i)
        cin >> S[i];
    long long int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    long long int DP[4][N];
    // Building DP[0]
    if(S[N - 1] == 'd')
        DP[0][N - 1] = A[N - 1];
    else
        DP[0][N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        if(S[i] == 'd'){
            DP[0][i] = A[i] + DP[0][i + 1];
        }
        else
            DP[0][i] = DP[0][i + 1];
    }
    // Building DP[1]
    DP[1][N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        if(S[i] == 'r')
            DP[1][i] = min(DP[0][i + 1], A[i] + DP[1][i + 1]);
        else
            DP[1][i] = DP[1][i + 1];
    }
    // Bulding DP[2]
    DP[2][N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        if(S[i] == 'a')
            DP[2][i] = min(DP[1][i + 1], A[i] + DP[2][i + 1]);
        else
            DP[2][i] = DP[2][i + 1];
    }
    //for(int i = 0; i < N; ++i)
    //    cout << DP[2][i] << " ";
    //cout << endl;
    // Building DP[3]
    DP[3][N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        if(S[i] == 'h')
            DP[3][i] = min(DP[2][i + 1], A[i] + DP[3][i + 1]);
        else
            DP[3][i] = DP[3][i + 1];
    }
    cout << DP[3][0] << endl;
    return 0;
}