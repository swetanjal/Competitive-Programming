#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
long long int A[MAXN];
vector <int> edges[MAXN];
long long int DP[MAXN];
long long int total;
long long total_sum;
void dfs(int node, int parent)
{
    int L = edges[node].size();
    DP[node] = A[node];
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
        {
            dfs(edges[node][i], node);
            DP[node] = DP[node] + DP[edges[node][i]];
        }
    }
}

long long int compute(int node, int parent, int level)
{
    long long tmp = level * A[node];
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
        {
            tmp = tmp + compute(edges[node][i], node, level + 1);
        }
    }
    return tmp;
}

void dfs2(int node, int parent, long long int prev_answer)
{
    long long ans = prev_answer + (total_sum - DP[node]) - DP[node];
    
    total = max(total, ans);
    //cout << "Node " << node << " " << parent << endl;
    int L = edges[node].size();
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
        {
            dfs2(edges[node][i], node, ans);
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }   
    dfs(1, -1);
    total = compute(1, -1, 0);
    //cout << total << endl;
    //long long tot = compute(2, -1, 0);
    //cout << tot << endl;
    int L = edges[1].size();
    total_sum = DP[1];
    //cout << "Start\n";
    long long copy = total;
    for(int i = 0; i < L; ++i)
    {
        dfs2(edges[1][i], 1, copy);
    }
    cout << total << endl;
    return 0;
}