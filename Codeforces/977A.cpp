#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long N;
	int K;
	cin>>N>>K;
	for(int i=1; i<=K; i++){
		if((N%10)==0)N/=10;
		else N--;
	}
	cout<<N<<endl;
	return 0;
}