#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
vector <int> edges[MAXN];
int dp[MAXN];

void dfs(int node, int parent)
{
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent){
            dfs(edges[node][i], node);
            dp[node] = dp[node] + dp[edges[node][i]]; 
        }
    }
    if(L == 1 && node != 1)
        dp[node] = 1;
}

int main()
{
    cin >> N;
    if(N == 1){
        cout << "1\n";
        return 0;
    }
    for(int i = 2; i <= N; ++i){
        int u, v;
        u = i;
        cin >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    long long DP[N];
    for(int i = 0; i < N; ++i)
        DP[i] = dp[i + 1];
    sort(DP, DP + N);
    for(int i = 0; i < N; ++i)
        cout << DP[i] << " ";
    cout << endl;
    return 0;
}