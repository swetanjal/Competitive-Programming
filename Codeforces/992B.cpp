#include "bits/stdc++.h"
using namespace std;
long long l,r,x,y;

map < pair <long long, long long>, int> H; 

int main()
{
	cin>>l>>r>>x>>y;
	long long ret = 0;
	//long long lcmgcd = x*y;
	for(long long i = 1; i*i <= y; i++)
	{
		if((y%i) == 0)
		{
			long long a = i*x;
			long long b = y/i;
			if(a>b)continue;
			if(a>=l && a<=r && b>=l && b<=r){
				long long hcf = __gcd(a, b);
				long long lcm = (a*b)/hcf;
				//if(H.find(make_pair(a,b))!=H.end())continue;
				//H[make_pair(a,b)]=1;
				if(hcf == x && lcm == y)
				{
					
					if(a == b)
						ret++;
					else
						ret+=2;
				}
			}
			if(i == (y/i))continue;
			long long i_tmp = y/i;
			a = i_tmp * x;
			b = y/i_tmp;
			if(a > b)continue;
			if(a>=l && a<=r && b>=l && b<=r){
				long long hcf = __gcd(a, b);
				long long lcm = (a*b)/hcf;
				if(hcf == x && lcm == y)
				{
					//if(H.find(make_pair(a,b))!=H.end())continue;
					//H[make_pair(a,b)]=1;
					if(a == b)
						ret++;
					else
						ret+=2;
				}
			}
		}
	}
	/*	if((lcmgcd%i) == 0)
		{
			long long b = lcmgcd/i;
			long long a = i;
			if(i > r || b<l)
				break;
			if(a>=l && a<=r && b>=l && b<=r){
				long long hcf = __gcd(a, b);
				long long lcm = (a*b)/hcf;
				if(hcf == x && lcm == y)
				{
					
					if(a == b)
						ret++;
					else
						ret+=2;
				}
			}
		}

	}*/
	cout<<ret<<endl;
	return 0;
}