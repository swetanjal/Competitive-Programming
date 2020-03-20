#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int T, N, K;
long long V;
string A[MAXN];
int print[MAXN];
int main()
{
	ifstream cin("tourist.txt");
	ofstream cout("tourist.out");
	cin>>T;
	int test = 1;
	while(T--){
		cout<<"Case #"<<test<<": ";
		cin>>N>>K>>V;
		for(int i = 0; i < N; i++){
			cin>>A[i];
			print[i] = 0;
		}
		long long idx = (V - 1) * 1LL * K;
		idx = (idx - 1)%N;
		idx++;
		if(idx == N)
			idx = 0;
		for(int i = 1; i <= K; i++)
		{
			print[idx++] = 1;
			if(idx >= N)
				idx = 0;
		}
		for(int i = 0 ; i < N; i++)
			if(print[i])cout<<A[i]<<" ";
		cout<<endl;
		test++;
	}
	return 0;
}