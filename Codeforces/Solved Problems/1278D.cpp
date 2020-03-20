#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5 + 5;
int N;
pair < int, int > A[MAXN];
vector <int> edges[MAXN];
int M;
bool visited[MAXN];
    
void dfs(int node)
{
    int l = edges[node].size();
    visited[node] = true;
    for(int i = 0; i < l; ++i){
        if(visited[edges[node][i]] == false)
            dfs(edges[node][i]);
    }
}
    
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i].first >> A[i].second;
    sort(A, A + N);
    set < pair <int, int> > S;
    S.insert({A[0].second, 1});
    for(int i = 1; i < N; ++i)
    {
        set < pair <int, int> > :: iterator it = S.lower_bound({A[i].first, -1});
        while(it != S.end() && A[i].second > (*it).first)
        {
            int node = (*it).second;
            //cout << node << " " << (i + 1) << endl;
            edges[node].push_back(i + 1);
            edges[i + 1].push_back(node);
            it++;
            M++;
            if(M == N)
                break;
        }
        if(M == N)
            break;
        S.insert({A[i].second, i + 1});
    }
    if(M == N)
    {
        cout << "NO\n";
        return 0;
    }
    int components = 0;
    for(int i = 1; i <= N; ++i)
        visited[i] = false;
    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false){
            dfs(i);
            components++;
        }
    }
    if(components == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}