#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N, K;
int u, v;
int res;
vector < pair < pair <int, int> , int > > V[MAXN];
int visited[MAXN];
int exists[MAXN];

void dfs(int node)
{
    if(visited[node] == 2)
        return;
    queue <int> Q;
    for(int i = 0; i < V[node].size(); ++i){
        if(exists[V[node][i].second] == 1)
            continue;
        u = V[node][i].first.first; 
        v = V[node][i].first.second;
        exists[V[node][i].second] = 1;
        if(visited[u] == 0 && u != node)
            Q.push(u);
        if(visited[v] == 0 && v != node)
            Q.push(v);
        if(visited[u] >= 1 && visited[v] >= 1)
            res++;
        visited[u] = 1;
        visited[v] = 1; 
    }
    visited[node] = 2;
    while(Q.empty() == false)
    {
        dfs(Q.front());
        Q.pop();
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= K; ++i){
        cin >> u >> v;
        V[u].push_back({{u, v}, i});
        V[v].push_back({{u, v}, i});
    }
    for(int i = 1; i < MAXN; ++i){
        if(visited[i] == 0)
            dfs(i);
    }
    cout << res << endl;
    return 0;
}