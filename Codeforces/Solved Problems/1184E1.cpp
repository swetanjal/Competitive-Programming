#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;
const int MAXM = 1e6+6;
int N, M, U1, V1;
pair < long long, int >  A[MAXM];
int U[MAXM];
int V[MAXM];
int parent[MAXN];
int sz[MAXN];
// Template for Union Find
int root(int node)
{
    if(parent[node] == node)return node;
    return parent[node] = root(parent[node]);
}
    
void _union(int a, int b)
{
    if(a==b)return;
    a = root(a);
    b = root(b);
    if(sz[a]<sz[b]){
        sz[b]+=sz[a];
        parent[a] = parent[b];
    }
    else
    {
        sz[a]+=sz[b];
        parent[b] = parent[a];
    }
}
// End of template for Union Find
    
bool chk(long long ncost)
{
    bool flag = false;
    for(int i = 0; i < M; ++i)
    {
        if(A[i].second == 0)
        {
            A[i].first = ncost;
            break;
        }
    }
    sort(A, A + M);
    for(int i=1; i<=N; i++)sz[i] = 1, parent[i] = i;
    for(int i = 0; i < M; ++i){
        U1 = U[A[i].second];
        V1 = V[A[i].second];
        if(root(U1)==root(V1))continue;
            _union(U1,V1);
        if(A[i].second == 0)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
    
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin>>U[i]>>V[i]>>A[i].first;
        A[i].second = i;
    }
    long long int low = 0; long long int high = 1000000000;
    long long int pos = -1;
    while(high >= low)
    {
        long long int mid = (high + low) / 2;
        if(chk(mid))
        {
            low = mid + 1;
            pos = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << pos << endl;
    return 0;
}