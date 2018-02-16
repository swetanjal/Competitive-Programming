#include "bits/stdc++.h"
using namespace std;
const int MAXN=2e3+5;
int N;
int A[MAXN];
long long DP1[MAXN][MAXN];
long long DP2[MAXN][MAXN];
long long cum1[MAXN][MAXN];
long long cum2[MAXN][MAXN];
int one[MAXN];
int two[MAXN];
int freq[MAXN];
//returns the longest subsequence between l and r starting with 1 and ending with 2
long long ones(int l, int r){
	
	if(l<=r && l!=0)return one[r]-one[l-1];
	else if(l<=r)return one[r];
	else return 0;
}
long long twos(int l, int r){
	if(l<=r && l!=0)return two[r]-two[l-1];
	else if(l<=r)return two[r];
	else return 0;
}

int main()
{	
	cin>>N;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<N; i++)freq[i]=1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
		{
			cum1[i][j]=DP1[i][j]=0;
			cum2[i][j]=DP2[i][j]=0;
		}
	}
	if(A[0]==1){
		one[0]=freq[0];
		two[0]=0;
	}
	else
	{
		one[0]=0;
		two[0]=freq[0];
	}
	for(int i=1; i<N; i++){
		if(A[i]==1){
			two[i]=two[i-1];
			one[i]=freq[i]+one[i-1];
		}
		else{
			two[i]=freq[i]+two[i-1];
			one[i]=one[i-1];	
		}
	}
	for(int i=N-1; i>=0; i--){
		for(int j=i; j<(N); j++){
			if(i==j && A[j]==2){

				DP1[i][j]=freq[j];
				cum1[i][i]=DP1[i][i];
			}
			else if(i==j){
				DP1[i][j]=0;
				cum1[i][i]=DP1[i][i];
			}
			else if(A[j]==1){
				DP1[i][j]=freq[j]+cum1[i][j-1];
				cum1[i][j] = max(DP1[i][j], cum1[i][j-1]);
			}
			else if(A[j]==2){
				DP1[i][j]=freq[j]+twos(i,j-1);
				cum1[i][j] = max(DP1[i][j], cum1[i][j-1]);
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=i; j>=0; j--){
			if(i==j && A[j]==2){

				DP2[j][i]=freq[j];
				cum2[i][i]=DP2[i][i];
			}
			else if(i==j){

				DP2[j][i]=0;
				cum2[i][i]=DP2[i][i];
			}
			else if(A[j]==1){
				DP2[j][i]=freq[j]+cum2[j+1][i];
				cum2[j][i] = max(DP2[j][i], cum2[j+1][i]);
			}
			else if(A[j]==2){
				DP2[j][i]=freq[j]+twos(j+1,i);
				cum2[j][i] = max(DP2[j][i], cum2[j+1][i]);
			}
		}
	}
	long long ret=0;
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			int st1=0; 
			int en1=i-1;
			long long tmp=0;
			tmp=cum2[st1][en1]+twos(i,j)+twos(j+1,N-1);
			tmp=max(tmp, ones(st1,en1)+cum1[i][j]+twos(j+1,N-1));
			tmp=max(tmp, ones(st1, en1) + ones(i,j) + ones(j+1,N-1));
			tmp=max(tmp, ones(st1, en1) + ones(i,j) + twos(j+1,N-1));
			tmp=max(tmp, ones(st1, en1) + twos(i,j) + twos(j+1,N-1));
			tmp=max(tmp, twos(st1, en1) + twos(i,j) + twos(j+1,N-1));	
			tmp=max(tmp, ones(st1, en1) + ones(i,j) + cum2[j+1][N-1]);
			tmp=max(tmp, ones(st1, en1) + cum1[i][j] + cum2[j+1][N-1]);
			tmp=max(tmp, cum2[st1][en1] + cum1[i][j] + cum2[j+1][N-1]);
			ret=max(ret,tmp);
		}
	}
	cout<<ret<<endl;
	return 0;
}