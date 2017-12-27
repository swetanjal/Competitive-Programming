#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	long long tmp;
	map <long long, int> H;
	map <long long, int> :: iterator it;
	for(int i=1; i<=N; i++)
	{
		cin>>tmp;
		if(H.find(tmp)==H.end())H[tmp]=1;
		else H[tmp]++;
	}
	int MAX=0;
	for(it=H.begin(); it!=H.end(); ++it)
	{
		MAX=max(MAX,it->second);
	}
	cout<<MAX<<endl;
	return 0;
}