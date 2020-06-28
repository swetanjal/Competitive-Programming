#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        int mod[N];
        for(int i = 0; i < N; ++i){
            mod[i] = 0;
            A[i] += i;
        }
        for(int i = 0; i < N; ++i){
            // long long tmp1 = ceil(A[i] * 1.0 / N);
            long long tmp2 = floor(A[i] * 1.0 / N);
            long long M = A[i] - (N * tmp2);
            // cout << M << endl;
            mod[M]++;
        }
        int got = 0;
        for(int i = 0; i < N; ++i){
            if(mod[i] > 1){
                got = 1;
            }
        }
        if(got == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}