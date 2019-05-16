#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    char A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }   
    int res = 0; 
    for(int i = N - 1; i > (N - 1 - X); i--){
        if(i == (N - 1 - Y) && A[i] == '0')
            res++;
        if(i != (N - 1 - Y) && A[i] != '0')
            res++;
    }
    cout << res << endl;
    return 0;
}