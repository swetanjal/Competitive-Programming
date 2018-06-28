#include "bits/stdc++.h"
using namespace std;
long long N;

bool chk(long long X)
{
	long long n = N;
	long long vasya = 0; long long petya = 0;
	for(int i=0; ; i++)
	{
		if((i%2) == 0)
		{
			
			if((n - X) < 0)
			{
				vasya += n;
				n = 0;
			}
			else
			{
				vasya += X;	
				n -= X;
			}
		}
		else
		{
			long long ccc = n/10;
			if((n - ccc) < 0)
			{
				petya += n;
				n = 0;
			}
			else
			{
				petya += ccc;
				n -= ccc;
			}
		}
		if((2*vasya) >= N)break;
		if(n == 0)break;
	}
	if((2*vasya) >= N)
		return true;
	return false;
}


int main()
{
	cin>>N;
	long long pos = -1;
	long long low = 1; long long high = 1000000000000000000; long long mid;
	while(low<=high)
	{
		mid = (high + low)/2;
		if(chk(mid))
		{
			pos = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout<<pos<<endl;
	return 0;
}