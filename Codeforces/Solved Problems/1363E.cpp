#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
vector <int> edges[MAXN];
int N;
long long int A[MAXN];
long long int B[MAXN];
long long int C[MAXN];
long long int DP0[MAXN];
long long int DP1[MAXN];
long long res;
void dfs(int node, int parent, long long int m)
{
    int l = edges[node].size();
    for(int i = 0; i < l; ++i){
        if(edges[node][i] == parent)
            continue;
        dfs(edges[node][i], node, min(m, A[node]));
        DP1[node] += DP1[edges[node][i]];
        DP0[node] += DP0[edges[node][i]];
    }
    
    if(B[node] == 0 && C[node] == 1)
        DP0[node] += 1;
    else if(B[node] == 1 && C[node] == 0){
        DP1[node] += 1;
    }
    //if(node == 1)
    //    cout << DP1[node] << " " << DP0[node] << endl;
    if(A[node] < m){
        int o = min(DP1[node], DP0[node]);
        DP1[node] -= o;
        DP0[node] -= o;
        res = res + (A[node] * 2 *o);
    }
}   

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i] >> B[i] >> C[i];
    for(int i = 1; i < N; ++i){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1, 10000000005);
    if(DP1[1] > 0 || DP0[1] > 0)
        cout << "-1\n";
    else
        cout << res << endl;
    return 0;
}