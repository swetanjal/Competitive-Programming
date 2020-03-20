#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    int res = 0;
    for(int i = 1; i < N; i += 2){
        res = res + (A[i] - A[i - 1]);
    }
    cout << res << endl;
    return 0;
}