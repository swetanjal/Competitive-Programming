#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int N, M;
        cin >> N >> M;
        if((N % 2) == 0){
            cout << (M * N / 2) << endl;
        }
        else if((M % 2) == 0){
            cout << (M * N / 2) << endl;
        }
        else{
            cout << (long long int)(min((N - 1) * M / 2 + ceil(M * 1.0 / 2), (M - 1) * N / 2 + ceil(N * 1.0 / 2))) << endl;
        }
    }
    return 0;
}