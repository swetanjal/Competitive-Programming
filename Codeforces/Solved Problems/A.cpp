#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
vector <int> edges[MAXN];
int visited[MAXN];
int comp[MAXN];
int N, M, u, v;
int components;
int heights[MAXN];
int diameter[MAXN];
int ROOT;
int max_ht;
priority_queue <pair<int, int> > P;
    
void dfs(int node, int ht, int parent)
{
    int L = edges[node].size();
    visited[node] = components;
    if(max_ht < ht){
        ROOT = node;
        max_ht = ht;
    }
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
            dfs(edges[node][i], 1 + ht, node);
    }
}
    
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    components = 1;
    for(int i = 0; i < N; ++i){
        if(visited[i] == 0){
            max_ht = 0;
            ROOT = i;
            dfs(i, 0, -1);
            dfs(ROOT, 0, -1);
            heights[components] = ceil(max_ht * 1.0 / 2);
            diameter[components] = max_ht;
            components++;
        }
    }
    components--;
    for(int i = 1; i <= components; ++i)
    {
        //cout << heights[i] << " " << diameter[i] << endl;
        P.push({heights[i], diameter[i]});
    }
        
    
    while(P.size() != 1){
        
        int d1 = P.top().second;
        int h1 = P.top().first;
        P.pop();
        int h2 = P.top().first;
        int d2 = P.top().second;
        P.pop();
        int newd, newh;
        //cout << d2 << " " << d1 << endl;
        if(h1 == h2){
            newh = h1 + 1;
            newd = 2 * h1 + 1;
        }
        else{
            newh = h1;
            newd = max(h1 + h2 + 1, max(d1, d2));
        }
        //cout << newd << endl;
        P.push({newh, newd});
    }  
    cout << P.top().second << endl;
    return 0;
}