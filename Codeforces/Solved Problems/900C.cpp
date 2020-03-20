#include <bits/stdc++.h>
using namespace std;
int N;
int A[100005];
int valid[100005];
int main()
{
	cin>>N;
	priority_queue <int> P;
	for(int i=0; i<N; i++)
	{
		int tmp;
		cin>>tmp;
		if(P.size()==0){
			valid[tmp]=1;
			P.push(tmp);
			continue;
		}
		//cout<<"LOL"<<endl;
		if(P.size()==1)
		{
			//cout<<P.top()<<endl;
			if(P.top()>tmp)
			{
				A[P.top()]++;
				//cout<<P.top()<<endl;
			}
			else
				valid[tmp]=1;
		}
		else
		{
			int top=P.top();
			if(top<tmp)valid[tmp]=1;
			P.pop();
			if(P.top()<tmp && tmp<top)
				A[top]++;
			P.push(top);
		}
		P.push(tmp);
	}
	int records=0;
	for(int i=1; i<=N; i++)records+=valid[i];
	//cout<<A[5]<<endl;

	int MAX=0;
	for(int i=1; i<=N; i++)
	{
		MAX=max(MAX,records+A[i]-valid[i]);
	}
	//cout<<MAX<<endl;
	for(int i=1; i<=N; i++)
	{
		if((records+A[i]-valid[i])==MAX)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}