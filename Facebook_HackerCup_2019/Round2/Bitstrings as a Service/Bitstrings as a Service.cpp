#include "bits/stdc++.h"
using namespace std;
const int MAXN = 4005;
int T, N, M;
vector <int> edges[MAXN];
int exists[MAXN][MAXN];
vector <int> A;
vector <int> C;
int DP[MAXN][2 * MAXN];
int color[MAXN];
int F[MAXN];
int comp;

int dfs(int node){
    if(color[node] != -1)
        return 0;
    int res = 1;
    color[node] = comp;
    for(int i = 0; i < edges[node].size(); ++i){
        res = res + dfs(edges[node][i]);
    }
    return res;
}

int rec(int idx, int s){
    if(idx == (comp - 1))
        return DP[idx][s + MAXN] = abs(s);
    if(DP[idx][s + MAXN] != -1)
        return DP[idx][s + MAXN];
    DP[idx][s + MAXN] = min(rec(idx + 1, s - A[idx]), rec(idx + 1, s + A[idx]));
    return DP[idx][s + MAXN];
}

void fill_it(int idx, int s)
{
    if(idx == (comp - 1))
        return;
    if(DP[idx + 1][s - A[idx] + MAXN] < DP[idx + 1][s + A[idx] + MAXN])
    {
        F[C[idx]] = 0;
        fill_it(idx + 1, s - A[idx]);
    }
    else{
        F[C[idx]] = 1;
        fill_it(idx + 1, s + A[idx]);
    }
}

int main()
{
    int cases = 1;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                exists[i][j] = 0;
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < 2 * MAXN; ++j)
                DP[i][j] = -1;
        comp = 1;
        A.clear();
        C.clear();
        for(int i = 1; i <= N; ++i){
            edges[i].clear();
            color[i] = -1;
            F[i] = 0;
        }
        for(int i = 1; i <= M; ++i){
            int u, v;
            cin >> u >> v;
            if(exists[u][v] == 0){
                edges[u].push_back(v);
                edges[v].push_back(u);
                while(u < v){
                    u++;
                    v--;
                    if(u != v)
                    {
                        edges[u].push_back(v);
                        edges[v].push_back(u);
                    }
                }
                exists[u][v] = 1;
                exists[v][u] = 1;
            }
        }
        for(int i = 1; i <= N; ++i)
        {
            if(color[i] == -1){
                A.push_back(dfs(i));
                C.push_back(comp);
                comp++;
            }
        }
        rec(0, 0);
        fill_it(0, 0);
        cout << "Case #" << cases << ": ";
        for(int i = 1; i <= N; ++i)
            cout << F[color[i]];
        cout << endl;
        cases++;
    }
    return 0;
}