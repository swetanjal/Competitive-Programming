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
        int ans = 1;
        for(int i = 0; i < N; ++i){
            if(A[i] <= (1 + i))
                ans = max(ans, i + 2);
        }
        cout << ans << endl;
    }
    return 0;
}