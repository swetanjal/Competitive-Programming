#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long N;
	cin>>N;
	long long sum=(N*(N+1))/2;
	if((sum%2)==0)
	{
		cout<<"0\n";
		long long T=sum/2;
		//cout<<T<<endl;
		vector <int> F;
		int r=N;
		while(T>r)
		{
			F.push_back(r);
			T-=r;
			r--;
		}
		if(T!=0)
		F.push_back(T);
		int L=F.size();
		cout<<L<<" ";
		for(int i=0; i<L; i++)cout<<F[i]<<" ";
		cout<<endl;
	}
	else
	{
		cout<<"1\n";
		long long T=sum/2;
		vector <int> F;
		int r=N;
		while(T>r)
		{
			F.push_back(r);
			T-=r;
			r--;
		}
		if(T!=0)
		F.push_back(T);
		int L=F.size();
		cout<<L<<" ";
		for(int i=0; i<L; i++)cout<<F[i]<<" ";
		cout<<endl;
	}
	return 0;
}