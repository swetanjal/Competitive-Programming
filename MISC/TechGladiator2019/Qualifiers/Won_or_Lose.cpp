#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int A[N];
        int B[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        for(int i = 0; i < N; ++i)
            cin >> B[i];
        sort(A, A + N);
        sort(B, B + N);
        int flag = 1;
        for(int i = 0; i < N; ++i){
            if(A[i] >= B[i]){
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "WIN\n";
        else
            cout << "LOSE\n";
    }
    return 0;
}