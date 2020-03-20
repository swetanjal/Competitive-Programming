#include "bits/stdc++.h"
using namespace std;
const int MAXNM = 1005;
int N, M;
char A[MAXNM][MAXNM];
int chk[MAXNM][MAXNM];
int L[MAXNM][MAXNM];
int R[MAXNM][MAXNM];
int U[MAXNM][MAXNM];
int D[MAXNM][MAXNM];
int X[1000000];
int Y[1000000];
int sz[1000000];
int get(int x, int y)
{
	if(A[x][y] == '.')return -1;
	int ret = L[x][y];
	ret = min(ret, R[x][y]);
	ret = min(ret, U[x][y]);
	ret = min(ret, D[x][y]);
	return ret;
}

void compute()
{
	for(int i = 0; i < N; i++){
		for(int j = M - 2; j >= 0; j--){
			if(A[i][j + 1] == '*')
				R[i][j] = 1 + R[i][j + 1];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 1; j < M; j++){
			if(A[i][j - 1] == '*')
				L[i][j] = 1 + L[i][j - 1];
		}
	}
	for(int j = 0; j < M; j++){
		for(int i = 1; i < N; i++){
			if(A[i - 1][j] == '*')
			U[i][j] = 1 + U[i - 1][j];
		}
	}
	for(int j = 0; j < M; j++){
		for(int i = N - 2; i >= 0; i--){
			if(A[i + 1][j] == '*')
				D[i][j] = 1 + D[i + 1][j];
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N>>M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin>>A[i][j];
	compute();
	
	int l = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int len = get(i , j);
			if(len <= 0)continue;
			for(int k = 0; k <= len; k++)
			{
				chk[i - k][j] = 1;
				chk[i + k][j] = 1;
				chk[i][j + k] = 1;
				chk[i][j - k] = 1;
			}
			if(len > 0){
				X[l] = i;
				Y[l] = j;
				sz[l] = len;
				l++;
			}
		}
	}
	int flag = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if((A[i][j] == '*' && chk[i][j] != 1))
			{
				flag = 0;
				break;
			}
		}
	}
	if(flag == 0){
		cout<<"-1\n";
		return 0;
	}
	cout<<l<<"\n";
	for(int i = 0; i < l; i++){
		cout<<(X[i]+1)<<" "<<(Y[i]+1)<<" "<<sz[i]<<"\n";
	}
	return 0;

}