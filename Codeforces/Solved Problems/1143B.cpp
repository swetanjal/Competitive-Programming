#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long power[11];
    power[0] = 1;
    for(int i = 1; i <= 10; ++i)
        power[i] = power[i - 1] * 9;
    vector <int> A;
    while(N > 0){
        A.push_back((N % 10));
        N /= 10;
    }
    reverse(A.begin(), A.end());
    int L = A.size();
    long long cum[L];
    for(int i = 0; i < L; ++i){
        if(i == 0)
        {
            cum[i] = A[i];
            continue;
        }
        cum[i] = cum[i - 1] * A[i];
    }
    long long res = cum[L - 1];
    for(int i = 0; i < L; ++i){
        if(i == 0 && A[i] == 1){
            res = max(res, power[L - 1]);
            continue;
        }
        if(i == 0){
            res = max(res, power[L - 1] * (A[i] - 1));
            continue;
        }
        res = max(res, cum[i - 1] * (A[i] - 1) * power[L - i - 1]);
    }
    cout << res << endl;
    return 0;
}