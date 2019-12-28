#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        int idx[N + 1];
        int A[N + 1];
        for(int i = 1; i <= N; ++i)
        {
            cin >> A[i];
            idx[A[i]] = i;
        }
        int max_idx = -1;
        int tmp;
        long long ans = 0;
        for(int i = 1; i <= M; ++i){
            cin >> tmp;
            int ind = idx[tmp];
            // cout << ind << " " << max_idx << endl;
            if(ind <= max_idx){
                ans += 1;
            }
            else{
                max_idx = ind;
                // cout << i << endl;
                //cout << (- 1 + (2 * (ind - (i - 1)))) << endl;
                ans = ans - 1 + (2LL * (ind - (i - 1)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}