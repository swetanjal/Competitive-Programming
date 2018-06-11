#include "bits/stdc++.h"

using namespace std;

int main()
{
	int N;
	cin>>N;
	long long A[N];
	set <long long> S;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<N; i++){
		set <long long> :: iterator it=S.lower_bound(A[i]);
		if(S.empty() || *(S.begin())>=A[i]){
			cout<<"-1\n";
		}
		else
		{
			--it;
			cout<<*it<<endl;
		}
		S.insert(A[i]);
	}
	return 0;
}