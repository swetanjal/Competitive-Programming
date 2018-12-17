#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
struct el{
    int u;
    int v;
    long long int c;
};
int N, M, K;
el A[MAXN];
int sp[MAXN];
int sz[MAXN];
int parent[MAXN];
vector <int> edges[MAXN];
vector <long long int> cost[MAXN];
bool cmp(el a, el b)
{
    return a.c < b.c;
}

long long ans = 0;
int DP[MAXN];

void dfs(int node, int p)
{
    if(sp[node])
        DP[node] = 1;
    int L = edges[node].size();
    for(int i = 0; i < L; ++i)
    {
        if(edges[node][i] != p){
            dfs(edges[node][i], node);
            DP[node] += DP[edges[node][i]];
        }
    }
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != p)
        {
            if(DP[edges[node][i]] > 0 && DP[edges[node][i]] != K)
                ans = max(ans, cost[node][i]);
        }
    }
}

int root(int p)
{
    if(parent[p] == p)
        return p;
    return parent[p] = root(parent[p]);
}

void _union(int x, int y)
{
    if(x == y)
        return;
    int rootx = root(x);
    int rooty = root(y);
    if(sz[rooty] < sz[rootx]){
        parent[rooty] = parent[rootx];
        sz[rootx] += sz[rooty]; 
    }
    else{
        parent[rootx] = parent[rooty];
        sz[rooty] += sz[rootx];
    }
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 1; i <= K; ++i)
    {
        int tmp;
        cin >> tmp;
        sp[tmp] = 1;
    }
    for(int i = 0; i < M; ++i){
        cin >> A[i].u >> A[i].v >> A[i].c;
    }
    sort(A, A + M, cmp);
    for(int i = 1; i <= N; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    
    for(int i = 0; i < M; ++i){
        if(root(A[i].u) == root(A[i].v))
            continue;
        else{
            //cout << A[i].c << endl;
            _union(A[i].u, A[i].v);
            edges[A[i].u].push_back(A[i].v);
            edges[A[i].v].push_back(A[i].u);
            cost[A[i].u].push_back(A[i].c);
            cost[A[i].v].push_back(A[i].c);            
        }
    }
    dfs(1, -1);
    for(int i = 1; i <= K; ++i)
        cout << ans << " ";
    cout << endl;
    return 0;
}