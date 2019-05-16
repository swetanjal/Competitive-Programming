#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
const long long MOD = 998244353;
long long int N;
long long A[MAXN];
long long B[MAXN];
long long C[MAXN];
bool cmp(long long a, long long b)
{
    return a > b;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        cin >> B[i];
    
    sort(B, B + N, cmp);
    long long res = 0;
    for(long long int i = 0; i < (N / 2); i++){
        long long tmp = ((i + 1) * (N - i));
        C[i] = (A[i] * tmp);
        C[N - 1 - i] = A[N - 1 - i] * tmp;
    }
    if((N % 2) != 0){
        long long int i = N / 2;
        long long tmp = ((i + 1) * (N - i));
        C[i] = A[i] * tmp;
    }
    sort(C, C + N);
    for(int i = 0; i < N; ++i){
        C[i] = C[i] % MOD;
        res = (res + (C[i] * B[i]) % MOD) % MOD;
    }
    cout << res << endl;
    return 0;
}