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
        sort(A, A + N);
        int ans = 0;
        for(int i = 1; i <= N; ++i){
            if(A[N - 1] >= (i + 1) && A[N - 2] >= (i + 1) && (N - 2) >= i)
                ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}