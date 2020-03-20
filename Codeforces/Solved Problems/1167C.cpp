#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5 + 5;
vector < int> edges[MAXN];
int N, M;
int visited[MAXN];
int component;
int dfs(int node){
    if(visited[node] != 0)
        return 0;
    visited[node] = component;
    int L = edges[node].size();
    int c = 1;
    for(int i = 0; i < L; ++i){
        c += dfs(edges[node][i]);
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int cnt;
        cin >> cnt;
        if(cnt == 0)
            continue;
        int u, v;
        cin >> u;
        for(int j = 2; j <= cnt; ++j)
        {
            cin >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
            u = v;
        }
    }
    vector <int> res;
    for(int i = 1; i <= N; ++i){
        if(visited[i] == 0){
            ++component;
            res.push_back(dfs(i));

        }
    }
    for(int i = 1; i <= N; ++i){
        cout << res[visited[i] - 1] << " ";
    }
    cout << endl;
    //cout << component << endl;
    return 0;
}