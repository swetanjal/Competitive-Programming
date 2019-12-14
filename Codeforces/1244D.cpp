#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
long long int C[MAXN][3];
int N;
long long DP[MAXN][4][4];
vector <int> edges[MAXN];
int parent[MAXN];

long long rec(int idx, int c1, int c2)
{
    if(DP[idx][c1][c2] != -1)
        return DP[idx][c1][c2];
    DP[idx][c1][c2] = 10000000000000000;
    for(int i = 1; i <= 3; ++i){
        if(c1 != i && c2 != i){
            DP[idx][c1][c2] = min(DP[idx][c1][c2], C[idx][i - 1] + (edges[idx].size() == 1 ? rec(edges[idx][0], c2, i) : 0));
        }
    }
    return DP[idx][c1][c2];
}

int color[MAXN];

void print(int idx, int c1, int c2)
{
    for(int i = 1; i <= 3; ++i){
        if(c1 != i && c2 != i && edges[idx].size() == 1 && (DP[idx][c1][c2] == (C[idx][i - 1] + DP[edges[idx][0]][c2][i]) ) ){
            color[idx] = i;
            print(edges[idx][0], c2, i);
            return;
        }
        if(c1 != i && c2 != i && edges[idx].size() == 0 && (DP[idx][c1][c2] == (C[idx][i - 1]))) {
            color[idx] = i;
            return;
        }
    }
}

void dfs(int node, int p)
{
    parent[node] = p;
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != p)
            dfs(edges[node][i], node);
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> C[i][0];
    for(int i = 1; i <= N; ++i)
        cin >> C[i][1];
    for(int i = 1; i <= N; ++i)
        cin >> C[i][2];
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < 4; ++j)
            for(int k = 0; k < 4; ++k)
                DP[i][j][k] = -1;
    for(int i = 1; i < N; ++i){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int flag = 1;
    int root = -1;
    for(int i = 1; i <= N; ++i){
        if(edges[i].size() == 1){
            root = i;
            continue;
        }
        if(edges[i].size() <= 2)
            continue;
        flag = 0;
        break;
    }
    if(flag == 0)
    {
        cout << "-1\n";
        return 0;
    }
    dfs(root, -1);
    for(int i = 1; i <= N; ++i){
        
        if(edges[i].size() == 2 && edges[i][0] == parent[i])
        {
            swap(edges[i][0], edges[i][1]);
            edges[i].pop_back();
        }
        else if(parent[i] == -1){
            continue;
        }
        else {
            edges[i].pop_back();
        }
    }
    long long ans = rec(root, 0, 0);
    cout << ans << endl;
    print(root, 0, 0);
    for(int i = 1; i <= N; ++i)
        cout << color[i] << " ";
    cout << "\n";
    return 0;
}