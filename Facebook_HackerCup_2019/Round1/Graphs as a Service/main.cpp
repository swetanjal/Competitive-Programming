#include "bits/stdc++.h"
using namespace std;
const int INF = INT_MAX;
const int MAXN = 55;
int T, N, M, u, v;
long long cost;
long long DP[MAXN][MAXN];
long long U[1005];
long long V[1005];
long long C[1005];
int main()
{
    cin >> T;
    int cases = 1;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j <MAXN; ++j)
                DP[i][j] = INF;
        for(int i = 0; i < MAXN; ++i)
            DP[i][i] = 0;
        for(int i = 0; i < M; ++i){
            cin >> u >> v >> cost;
            U[i] = u; V[i] = v; C[i] = cost;
            DP[u][v] = cost;
            DP[v][u] = cost;
        }
        for(int k = 1; k <= N; k++)
	    {
		    for(int i = 1; i <= N; i++)
		    {
			    for(int j = 1; j <= N; j++)
			    {
				    DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
			    }
		    }
	    }
        int ok = 1;
        for(int i = 0; i < M; ++i){
            if(DP[U[i]][V[i]] == C[i]){
                assert(DP[V[i]][U[i]] == C[i]);
                continue;
            }
            ok = 0;
        }
        if(ok == 0)
            cout << "Case #" << cases << ": Impossible" << endl;
        else{
            cout << "Case #" << cases << ": " << M << endl;
            for(int i = 0; i < M; ++i)
                cout << U[i] << " " << V[i] << " " << C[i] << endl;
        }
        cases++;
    }
    return 0;
}