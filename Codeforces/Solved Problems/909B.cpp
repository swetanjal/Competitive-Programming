#include "bits/stdc++.h"
using namespace std;
int N;
vector <int> X;
vector <int> Y;
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<=N; j++)
		{
			X.push_back(i);
			Y.push_back(j);
		}
	}
	int L=X.size();
	bool visited[L];
	for(int i=0; i<L; i++)visited[i]=false;
	int ret=0;
	for(int i=0; i<L; i++)
	{
		if(visited[i]){
			continue;
		}
		int PT=Y[i];
		//cout<<X[i]<<","<<Y[i]<<"  ";
		for(int j=i+1; j<L; j++)
		{
			if(X[j]>=PT && visited[j]==false){
				visited[j]=true;
				PT=Y[j];
				//cout<<X[j]<<","<<Y[j]<<"  ";
			}
		}

		ret++;
		//cout<<endl;
	}	
	cout<<ret<<endl;
	return 0;
}