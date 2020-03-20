#include "bits/stdc++.h"
#define MIN -1000000000000000000
using namespace std;
const int MAXN = 3e5 + 5;
int N, u, v;
long long A[MAXN];
vector <int> edges[MAXN];
long long DP[MAXN];

inline void dfs(int node, int parent)
{
    DP[node] = A[node];
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
            dfs(edges[node][i], node);
    }
    for(int i = 0; i < L; ++i)
    {
        if(edges[node][i] != parent)
        {
            if(DP[edges[node][i]] > 0)
                DP[node] += DP[edges[node][i]];
        }
    }
}
long long int res = MIN;
int dirty[MAXN];

inline void dfs2(int node, int parent)
{
    int L = edges[node].size();
    for(int i = 0; i < L; i++){
        if(edges[node][i] != parent){
            dfs2(edges[node][i], node);
            if(DP[edges[node][i]] > 0 && DP[edges[node][i]] == res)
                dirty[node] = 1;
            else if(DP[edges[node][i]] > 0)
                dirty[node] |= dirty[edges[node][i]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i < N; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    
    for(int i = 1; i <= N; ++i)
        res = max(res, DP[i]);
    long long int cnt = 0;
    dfs2(1, -1);
    for(int i = 1; i <= N; ++i)
        if(DP[i] == res && dirty[i] == 0)
            cnt++;
    long long ANS = res * cnt; 
    cout << ANS << " " << cnt << endl;
    return 0;
}