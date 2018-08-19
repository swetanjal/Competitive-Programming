#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2005;
int L[MAXN];
int R[MAXN];
vector <int> pre;
vector <int> post;
vector <int> check1;
vector <int> check2;
vector <int> edges[MAXN];
int N, K;
int label[MAXN];
int paint;

void init()
{
	for(int i = 0; i < MAXN; i++)
		L[i] = 0, R[i] = 0;
	pre.clear();
	post.clear();
	check1.clear();
	check2.clear();
	for(int i = 0; i < MAXN; i++)
		edges[i].clear();
	N = 0; K = 0;
	for(int i = 0; i < MAXN; i++)
		label[i] = 0;
	paint = 0;
}

void preorder(int node)
{
	pre.push_back(node);
	if(L[node] != 0)
		preorder(L[node]);
	if(R[node] != 0)
		preorder(R[node]);
}

void postorder(int node)
{
	if(L[node] != 0)
		postorder(L[node]);
	if(R[node] != 0)
		postorder(R[node]);
	post.push_back(node);	
}

void print(int node)
{
	check1.push_back(label[node]);
	if(L[node] != 0)
		print(L[node]);
	if(R[node] != 0)
		print(R[node]);
	check2.push_back(label[node]);
}

void dfs(int node){
	if(label[node] != 0)
		return;
	int L = edges[node].size();
	label[node] = paint;
	for(int i = 0; i < L; i++)
		dfs(edges[node][i]);
}

bool equals()
{
	int found[K + 1];
	for(int i = 0 ; i <= K; i++)
		found[i] = 0;
	int p = check1.size();
	for(int i = 0; i < p; i++)
		if(check1[i] != check2[i])return false;
	for(int i = 1; i <= N; i++)
		found[label[i]] = 1;
	for(int i = 1; i <= K; i++)
		if(found[i] == 0)return false;
	return true;
}

int main()
{
	ifstream cin("ethan_traverses_a_tree.txt");
	ofstream cout("Ethan_Traverses_a_Tree.out");
	int t;
	cin>>t;
	for(int T = 1; T <= t; T++){
		init();
		cin>>N>>K;
		for(int i = 1; i <= N; i++)
		{
			int A, B;
			cin>>A>>B;
			L[i] = A;
			R[i] = B;
		}
		preorder(1);
		postorder(1);
		int sz = pre.size();
		for(int i = 0; i < sz; i++){
			edges[pre[i]].push_back(post[i]);
			edges[post[i]].push_back(pre[i]);
		}
		paint = 1;
		for(int i = 1; i <= N; i++)
		{
			if(label[i] == 0){
				dfs(i);
				paint++;
			}
		}
		cout<<"Case #"<<T<<": ";
		if(paint >= (K + 1))
		{
			for(int i = 1; i <= N; i++)
			{
				if(label[i] > K)
					label[i] = K;
			}
			for(int i = 1; i <= N; i++)
			{
				cout<<label[i]<<" ";
			}
			assert(equals());
		}
		else{
			cout<<"Impossible";
			assert(equals() == false);
		}
		cout<<endl;
	}
	return 0;
}