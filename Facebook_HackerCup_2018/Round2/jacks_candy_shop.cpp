#include "bits/stdc++.h"
using namespace std;
const int MAXM = 1000000;
const int MAXN = 200000;
int T, N, M, A, B;
long long C[MAXM];
vector <int> edges[MAXN];
int timer = 0;
int st[MAXN];
int en[MAXN];
vector <int> flatten;
long long tree[4 * MAXN];
int idx[4 * MAXN];
int level[MAXN];
int pos[MAXN];

void build(int node, int L, int R)
{
    if(L == R)
    {
        // Leaf node will have a single element
        tree[node] = flatten[L];
    	idx[node] = L;
    }
    else
    {
        int mid = (L + R) / 2;
        // Recurse on the left child
        build(2*node, L, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, R);
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node], tree[2*node+1]);
        idx[node] = idx[2 * node];
        if(tree[2 * node] > tree[(2 * node) + 1])
        {
        	idx[node] = idx[(2 * node) + 1];
        }
    }
}

long long int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return -1;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        //pos = idx[node];
        ///cout<<l<<" "<<r<<" "<<tree[node]<<endl;
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    long long p1 = query(2*node, start, mid, l, r);
    long long p2 = query(2*node+1, mid+1, end, l, r);
    //pos = idx[2 * node];
    //if(p2 > p1)
    //	pos = idx[(2 * node) + 1];
    return max(p1, p2);
}

void update(int node, int start, int end, int query)
{
	if(query < start or end < query)
    {
        // range represented by a node is completely outside the given range
        return;
    }
    if(start == query and end == query)
    {
        // range represented by a node is completely inside the given range
        flatten[start] = -1;
        tree[node] 	= -1;
        idx[node] = -1;
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, query);
   	update(2*node+1, mid+1, end,query);
    idx[node] = idx[2 * node];
    tree[node] = tree[2 * node];
    if(tree[2 * node] < tree[ 2 * node + 1]){
    	idx[node] = idx[2 * node + 1];
    	tree[node] = tree[2 * node + 1];
    }
    return;
}

void dfs(int node, int LEV)
{
	int L = edges[node].size();
	st[node] = timer;
	level[node] = LEV;
	flatten.push_back(node);
	for(int i = 0; i < L; i++)
	{
		++timer;
		dfs(edges[node][i], LEV + 1);
	}
	en[node] = timer;
}

void init()
{
	for(int i = 0; i <= N; i++)
		edges[i].clear();
	timer = 0;
	flatten.clear();
}

bool cmp(int X, int Y)
{
	return level[X] > level[Y];
}

int main()
{
	ifstream cin("jacks_candy_shop.txt");
	ofstream cout("2.out");
	cin>>T;
	for(int test = 1; test <= T; test++)
	{
		cin>>N>>M>>A>>B;
		init();
		for(int i = 0; i < M; i++)
			C[i] = (A * 1LL *i + B) % N;
		for(int i = 0; i < N - 1; i++){
			int p;
			cin>>p;
			edges[p].push_back(i + 1);
		}
		dfs(0, 0);
		int L = flatten.size();
		build(1, 0, L - 1);
		long long res = 0;
		for(int i = 0; i < L; i++){
			pos[flatten[i]] = i;
		}
		long long ret = 0;
		sort(C, C + M, cmp);
		for(int i = 0; i < M; i++){
			//cout<<st[C[i]]<<" "<<en[C[i]]<<endl;
			int tmp = query(1, 0, L - 1, st[C[i]], en[C[i]]);
			if(tmp == -1)
				continue;
			update(1, 0, L - 1, pos[tmp]);
			ret = ret + tmp;
		}
		cout<<"Case #"<<test<<": "<<ret<<endl;
	}
	return 0;
}