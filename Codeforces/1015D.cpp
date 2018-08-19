#include "bits/stdc++.h"
using namespace std;

long long N, K, S;

int main()
{
	cin>>N>>K>>S;
	long long tmp = S / K;
	long long rem = S % K;
	int chk = (rem == 0)? 0 : 1;
	if((tmp + chk) > (N - 1) || (tmp <= 0))
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	long long curr = 1;
	for(long long i = 1; i <= rem; i++){
		if((i % 2) == 0){
			curr = curr - (tmp + 1);
		}
		else
		{
			curr = curr + (tmp + 1);
		}
		cout<<curr<<" ";
		//done++;
	}
	for(long long i = rem + 1; i <= K; i++){
		//cout<<"LO\n";
		if((i % 2) == 0){
			curr = curr - (tmp);
		}
		else
		{
			curr = curr + (tmp);
		}
		cout<<curr<<" ";
	}
	cout<<endl;
	return 0;
}