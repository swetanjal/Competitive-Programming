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
        int A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        long long int sol = -1;
        for(int i = 1; i <= 1024; ++i){
            map <int, int> H;
            for(int j = 0; j < N; ++j){
                // cout << (A[j] ^ i) << endl;
                H[A[j] ^ i] = 1;
            }
            int exists = 0;
            for(int j = 0; j < N; ++j){
                if(H.find(A[j]) != H.end())
                    exists++;
            }
            if(exists == N){
                sol = i;
                break;
            }
        }
        cout << sol << endl;
    }
    return 0;
}