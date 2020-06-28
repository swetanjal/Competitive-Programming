#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int N, K;
        cin >> N >> K;
        long long thresh = K / 2;
        long long rem = N % K;
        if(rem <= thresh){
            cout << N << endl;
        }
        else{
            cout << ((N / K) * K + thresh) << endl;
        }
    }
    return 0;
}