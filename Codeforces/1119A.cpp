#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        //cout << A[i] << endl;
        if(A[i] != A[N - 1]){
            //cout << A[i] << endl;
            res = max(res, N - 1 - i);
        }
        if(A[0] != A[i])
            res = max(res, i - 0);
    }
    cout << res << endl;
    return 0;
}