#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N, M, s, u, v;
vector <int> edges[MAXN];
long long A[MAXN];
int parent[MAXN];
int visited[MAXN];
int done[MAXN];
int leaf[MAXN];
int indegree[MAXN];
queue <int> Q;
long long DP[MAXN];
void dfs(int node, int p){
    if(visited[node] == true)
        return;
    visited[node] = 1;
    parent[node] = p;
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        dfs(edges[node][i], node);
    }
    indegree[node] = L;
    if(L == 1 && node != s){
        leaf[node] = 1;
        done[node] = 1;
        Q.push(node);
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i <= M; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> s;
    dfs(s, -1);
    while(Q.empty() == false){
        int t = Q.front();
        Q.pop();
        if(t != s)
        done[t] = 1;
        if(parent[t] != -1)
        {   
            indegree[parent[t]]--;
            DP[parent[t]] = max(DP[parent[t]], A[t] + DP[t]);
            if(indegree[parent[t]] == 1)
                Q.push(parent[t]);
        }
    }
    long long ans = 0;
    for(int i = 1; i <= N; ++i)
        if(!done[i])
            ans += A[i];
    long long MX = 0;
    for(int i = 1; i <= N; ++i){
        MX = max(MX, DP[i]);
    }
    cout << (ans + MX)<< endl;
    return 0;
}