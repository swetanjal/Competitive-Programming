#include "bits/stdc++.h"
using namespace std;
const int MAX=1005;
int T,N,M;
long long A[MAX][MAX];
bool visited[MAX][MAX];
bool valid(int row, int col)
{
	if(row==N || col==M || row<0 || col<0)return false;
	return true;
}
void dfs(int row, int col)
{
	if(visited[row][col])return;
	visited[row][col]=true;
	if(valid(row+1,col) && A[row+1][col]<=A[row][col])	
	dfs(row+1,col);
	if(valid(row-1,col) && A[row-1][col]<=A[row][col])
	dfs(row-1,col);
	if(valid(row,col+1) && A[row][col+1]<=A[row][col])
	dfs(row,col+1);
	if(valid(row,col-1) && A[row][col-1]<=A[row][col])
	dfs(row,col-1);
}
set <long long> S;
vector <long long> highest;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				cin>>A[i][j];
				S.insert(A[i][j]);
			}
		}
		set <long long> :: iterator it;
		for(it=S.begin(); it!=S.end(); ++it)
			highest.push_back(*it);
		sort(highest.begin(), highest.end());
		reverse(highest.begin(), highest.end());
		int L=highest.size();
		int c=0; int ANS=0;
		for(int i=0; i<N; i++)for(int j=0; j<M; j++)visited[i][j]=false;
		while(c<L){
			int flag=0;
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<M; j++)
				{
					if(A[i][j]==highest[c] && visited[i][j]==false){
						dfs(i,j);
						flag=1;
						ANS++;
						break;
					}
				}
				if(flag)break;
			}
			if(flag==0)
			c++;
		}
		cout<<ANS<<endl;
	}
	return 0;
}