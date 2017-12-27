#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	long long a,b;
	cin>>a>>b>>c;
	int i;
	long long carry=(a%b);
	for(i=1; i<=10000000; i++)
	{
		carry*=10;
		int dig=(carry/b)%10;
		if(dig==c)
		{
			cout<<i<<endl;
			return 0;
		}
		carry=(carry%b);
	}
	cout<<"-1\n";
	return 0;
}