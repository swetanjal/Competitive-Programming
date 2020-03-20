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
    int idx1 = INT_MAX;
    int idx2 = INT_MAX;
    for(int i = N - 1; i >= 0; i--){
        if(A[i] == 1 && idx1 == INT_MAX)
            idx1 = i;
        if(A[i] == 0 && idx2 == INT_MAX)
            idx2 = i;
    }
    cout << min(idx1, idx2) + 1 << endl;
    return 0;
}