#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
vector <int> edges[MAXN];
bool visited[MAXN];
vector <int> res;
void dfs(int node)
{
    if(visited[node])
        return;
    visited[node] = true;
    cout << node << " ";
    if(visited[edges[node][0]])
        dfs(edges[node][1]);
    else
        dfs(edges[node][0]);
}

int E[MAXN][2];

int main()
{
    cin >> N;

    for(int i = 1; i <= N; ++i){
        cin >> E[i][0] >> E[i][1];
    }
    for(int i = 1; i <= N; ++i){
        edges[E[i][0]].push_back(E[i][1]);
        edges[E[i][1]].push_back(E[i][0]);
    }
    for(int i = 1; i <= N; ++i)
        visited[i] = false;
    cout << "1 ";
    visited[1] = true;
    if(edges[1][0] != E[1][0] && edges[1][0] != E[1][1])
        dfs(edges[1][1]);
    else
        dfs(edges[1][0]);
    //for(int i = N - 1; i >= 0; i--)
    //    cout << res[i] << " ";
    cout << endl;
    return 0;
}