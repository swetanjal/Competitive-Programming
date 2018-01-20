#include "bits/stdc++.h"
using namespace std;
int main()
{
	int T,N; long long K;
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		if(N==1)
		{
			if(K==0)cout<<"1\n";
			else cout<<"-1\n";
			continue;
		}
		if(N==2){
			if(K==2)cout<<"1 2\n";
			else cout<<"-1\n";
			continue;
		}
		long long A[N-1];
		long long sum=0;
		for(int i=0; i<(N-1); i++)
		{
			A[i]=(i+2);
			sum=sum+(i+2);
		}
		if(K<sum){
			cout<<"-1\n";
			continue;
		}
		//cout<<sum<<endl;
		K-=sum;
		stack <int> S;
		int cnt;
		for(int i=2; i<=N; i++)
		{
			S.push(i);
			S.push(i);
		}
		long long M[N-1];
		
		for(int i=(N-2); i>=0; i--)
		{
			//int top=S.top();
			//S.pop();
			//cout<<A[i]<<" "<<top<<endl;
			while((S.top()-A[i])>K)S.pop();
			if((S.top()-A[i])<=K){
				//cout<<(top-A[i])<<endl;
				K=K-(S.top()-A[i]);
				//top=A[i];
				M[i]=S.top();
				S.pop();
				//cout<<K<<endl;
			}
			else
				M[i]=A[i];
		}
		if(K>0){
			cout<<"-1\n";
			continue;
		}
		int perm[N-1];
		for(int i=0; i<(N-1); i++)perm[i]=-1;
		bool visited[N+1];
		for(int i=1; i<=N; i++)visited[i]=false;
		for(int i=0; i<(N-2); i++)
		{
			if(M[i]==M[i+1])
			{
				perm[i]=M[i];
				visited[M[i]]=true;
				i++;
			}
			else
			{
				perm[i]=M[i];
				visited[M[i]]=true;
			}
		}
		int ptr=N;
		for(int i=(N-2); i>=0; i--)
		{
			if(perm[i]!=-1)continue;
			while(visited[ptr])
			{
				ptr--;
			}
			perm[i]=ptr;
			visited[ptr]=true;
		}
		while(visited[ptr])
			ptr--;
		cout<<ptr<<" ";
		for(int i=0; i<(N-1); i++)cout<<perm[i]<<" ";
			cout<<endl;
	}
	return 0;
}