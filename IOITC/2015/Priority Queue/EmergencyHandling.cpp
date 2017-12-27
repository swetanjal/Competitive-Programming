#include <bits/stdc++.h>
using namespace std;
int T,N,r;
long long t0,s;
priority_queue <long long> P[105];
char c;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<=100; i++)
		{
			while(P[i].empty()==false)
			P[i].pop();
		}
		while(N--)
		{
			cin>>c;
			if(c=='P')
			{
				cin>>t0>>s>>r;
				P[r].push(s-(t0*r));
			}	
			else
			{
				long long U;
				cin>>U;
				int pos=-1; long long val=0;
				for(int i=0; i<=100; i++)
				{
					if(P[i].empty()==false)
					{
						
						long long x=P[i].top()+(U*i);
						if(x>=val)
						{
							val=x;
							pos=i;
						}
					}
				}
				P[pos].pop();
				cout<<val<<" "<<pos<<"\n";
			}		
		}	
	}
	return 0;
}
