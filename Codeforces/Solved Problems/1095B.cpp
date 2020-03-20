#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    if(N <= 2){
        cout << "0\n";
        return 0;
    }
    long long int ans = min(A[N - 1] - A[1], A[N - 2] - A[0]);
    cout << ans << endl;
    return 0;
}