#include "bits/stdc++.h"
using namespace std;
const int MAXN = 15;
int T;
int R, C;
int A[MAXN][MAXN];

long long compute()
{
    long long dist[MAXN][MAXN];
    long long ret = 0;
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j){
            dist[i][j] = 1000000000;
            for(int k = 0; k < R; ++k){
                for(int l = 0; l < C; ++l){
                    if(A[k][l] == 1)
                        dist[i][j] = min(dist[i][j], 1LL * (abs(k - i) + abs(l - j)));
                }
            }
            ret = max(ret, dist[i][j]);
        }
    }
    return ret;
}

int main()
{
    cin >> T;
    int cases = 1;
    while(T--)
    {
        cin >> R >> C;
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                char ch;
                cin >> ch;
                if(ch == '0')
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        long long res = LONG_LONG_MAX;
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                int yes = A[i][j];
                A[i][j] = 1;
                res = min(res, compute());
                if(yes == 0)
                    A[i][j] = 0;
            }
        }
        cout << "Case #" << cases <<": " << res << endl;
        cases++;
    }
    return 0;
}