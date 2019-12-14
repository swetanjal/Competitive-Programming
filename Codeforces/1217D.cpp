#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5005;
int N, M;
vector <int> edges[MAXN];
stack <int> S;
map < pair <int, int> , int > C;
vector < pair <int, int> > E;
int visited[MAXN];
int mx = 1;
void dfs(int node, int parent)
{
    if(visited[node] == 2){
        C[{parent, node}] = 1;
        return;
    }
    if(visited[node] == 1){
        // Then cycle found!
        C[{parent, node}] = 2;
        mx = 2;
        return;
    }
    int L = edges[node].size();
    visited[node] = 1;
    if(parent != -1)
        C[{parent, node}] = 1;
    for(int i = 0; i < L; ++i){
        dfs(edges[node][i], node);
    }
    visited[node] = 2;
}

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u, v;
        cin >> u >> v;
        E.push_back({u, v});
        C[{u, v}] = -1;
        edges[u].push_back(v);
    }
    for(int i = 1; i <= N; ++i)
        dfs(i, -1);
    cout << mx << endl;
    for(int i = 1; i <= M; ++i){
        cout << C[E[i - 1]] << " ";
    }
    cout << endl;
    return 0;
}