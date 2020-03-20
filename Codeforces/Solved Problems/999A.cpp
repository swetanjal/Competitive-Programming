#include "bits/stdc++.h"
using namespace std;

long long N,K;
deque <long long> A;

int main()
{
	cin>>N>>K;
	for (int i = 1; i <=N; ++i)
	{
		long long tmp;
		cin>>tmp;
		A.push_back(tmp);
	}
	int ret = 0;
	while(A.empty() == false && (A.front() <= K || A.back() <= K))
	{
		if(A.front() <= K)
		{
			A.pop_front();
			ret++;
		}
		else
		{
			A.pop_back();
			ret++;
		}
	}
	cout<<ret<<endl;
	return 0;
}