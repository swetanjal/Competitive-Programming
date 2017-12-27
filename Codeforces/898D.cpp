#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int A[1000005];
int main()
{
	cin>>N>>M>>K;
	for(int i=1; i<=N; i++)
	{
		int min;
		cin>>min;
		A[min]=1;
	}
	set <int> S;
	for(int i=1; i<=M; i++)
	{
		if(A[i]==1)
			S.insert(i);
	}
	int ANS=0;
	if(S.size()>=K)
	{
		int L=S.size();
		int eee=L-K+1;
		for(int i=1; i<=eee; i++)
		{
			set <int> :: iterator xxx=S.end();
			--xxx;
			S.erase(xxx);
			ANS++;
		}	
	}
	/*set <int> :: iterator it;
	for(it=S.begin();it!=S.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;*/
	//cout<<A[100005]<<endl;
	for(int i=M+1; i<=1000000; i++)
	{
		if(A[i]==1)
		S.insert(i);
		if(S.empty())continue;
		set <int> :: iterator it=S.begin();
		int num=*it;
		//cout<<num<<endl;
		if(num==(i-M))
			S.erase(it);
		//cout<<S.size()<<endl;
		if(S.size()>=K)
		{
			int L=S.size();
			int eee=L-K+1;
			for(int i=1; i<=eee; i++)
			{
				set <int> :: iterator xxx=S.end();
				--xxx;
				S.erase(xxx);
				ANS++;
			}	
		}
	}
	cout<<ANS<<endl;
	return 0;
}