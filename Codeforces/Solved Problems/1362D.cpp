#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5 + 5;
int indegree[MAXN];
vector <int> uedges[MAXN];
vector <int> dedges[MAXN];
long long int A[MAXN];
int N, M;
int visited[MAXN];
int invalid;
void dfs(int node)
{
    if(visited[node] == 1)
        return;
    visited[node] = 1;
    set <int> S;
    int l = uedges[node].size();
    for(int i = 0; i < l; ++i){
        if(A[uedges[node][i]] < A[node]){
            // cout << node << " " << uedges[node][i] << " " << node << endl;
            S.insert(A[uedges[node][i]]);
            dedges[uedges[node][i]].push_back(node);
            indegree[node]++;
        }
        else if(A[uedges[node][i]] == A[node]){
            invalid = 1;
        }
    }
    if(S.size() != (A[node] - 1)){
        invalid = 1;
    }
    if(invalid)
        return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u, v;
        cin >> u >> v;
        uedges[u].push_back(v);
        uedges[v].push_back(u);
    }
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i <= N; ++i){
        if(visited[i] == 0)
            dfs(i);
    }
    if(invalid){
        cout << "-1\n";
        return 0;
    }
    set < pair <int, int> > S;
    priority_queue < pair <int, int> , vector<pair <int, int> > , greater<pair <int, int> > > P;
    for(int i = 1; i <= N; ++i){
        S.insert({indegree[i], i});
    }   
    while(S.empty() == false)
    {
        pair <int, int> p = *(S.begin());
        S.erase(p);
        int node = p.second;
        int in = p.first;
        int l = dedges[node].size();
        for(int i = 0; i < l; ++i){
            S.erase({indegree[dedges[node][i]], dedges[node][i]});
            indegree[dedges[node][i]]--;
            S.insert({indegree[dedges[node][i]], dedges[node][i]});
        }
        cout << node << " ";
    }
    cout << endl;
    return 0;
}