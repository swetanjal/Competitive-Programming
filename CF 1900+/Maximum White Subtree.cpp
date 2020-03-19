// 1324 F
// Codeforces Round #627 (Div. 3)
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
vector <int> edges[MAXN];
int A[MAXN];
int DP[MAXN];
int F[MAXN];

void dfs(int node, int parent){
    int l = edges[node].size();
    for(int i = 0; i < l; ++i){
        if(edges[node][i] != parent){
            dfs(edges[node][i], node);
            DP[node] = max(DP[node], DP[node] + DP[edges[node][i]]);
        }
    }
    if(A[node] == 1)DP[node] += 1;
    else DP[node] -= 1;
}   

void compute(int node, int parent){
    int l = edges[node].size();
    if(parent != -1){
        if(DP[node] > 0){
            F[node] = max(F[parent], DP[node]);
        }
        else{
            F[node] = max(DP[node], F[parent] + DP[node]);
        }
    }
    for(int i = 0; i < l; ++i){
        if(edges[node][i] != parent){
            compute(edges[node][i], node);
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i < N; ++i){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    F[1] = DP[1];
    compute(1, -1);
    for(int i = 1; i <= N; ++i)
        cout << F[i] << " ";
    cout << endl;
    return 0;
}