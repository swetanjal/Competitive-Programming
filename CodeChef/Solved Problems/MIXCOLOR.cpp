#include "bits/stdc++.h"
using namespace std;

int T,N;
map <long long , int> H;
map <long long , int> :: iterator it;
int main()
{
	cin>>T;
	while(T--)
	{
		int N,tmp;
		cin>>N;
		H.clear();
		for(int i=1; i<=N; i++)
		{
			cin>>tmp;
			if(H.find(tmp)!=H.end())
				H[tmp]++;
			else
				H[tmp] = 1;
		}
		long long ret = 0;
		for(it = H.begin(); it!=H.end(); ++it)
		{
			ret = ret + (it->second);
			ret -= 1;
		}
		cout<<ret<<endl;
	}
	return 0;
}