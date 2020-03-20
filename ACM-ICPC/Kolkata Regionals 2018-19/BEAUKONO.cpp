#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
vector <int> edges[MAXN];
int parity[MAXN];
long long int DP[2];
int T, N, tmp;
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 1; i <= N; ++i) 
            edges[i].clear();
        parity[1] = 0;
        DP[0] = 0;
        DP[1] = 0;
        long long int res = 0;
        for(int i = 2; i <= (N + 1); ++i){
            cin >> tmp;
            parity[i] = 1 - parity[tmp];
            if(edges[tmp].size() == 1){
                if(parity[i] == 0){
                    DP[1] = 1 + DP[1];
                    DP[0] -= 1;
                }
                else{
                    DP[0] = 1 + DP[0];
                    DP[1] -= 1;
                }
            }
            else{
                if(parity[i] == 0)
                    DP[1] = 1 + DP[1];
                else
                    DP[0] = 1 + DP[0];
            }
            if(i == 2){
                DP[0] = 1;
                DP[1] = 1;
            }
            DP[0] = max(0 * 1LL, DP[0]);
            DP[1] = max(0 * 1LL, DP[1]);
            res = res + max(DP[0], DP[1]);
            edges[i].push_back(tmp);
            edges[tmp].push_back(i);
        }
        cout << res << endl;
    }
    return 0;
}