#include <bits/stdc++.h>
using namespace std;
int main()
{
	int h1,a1,c;
	cin>>h1>>a1>>c;
	int h2,a2;
	cin>>h2>>a2;
	vector <string> ans;
	while(h2>0)
	{
		if((h2-a1)<=0)
		{
			ans.push_back("STRIKE");
			h2-=a1;
			break;	
		}
		if((h1-a2)>0)
		{
			ans.push_back("STRIKE");
			h2-=a1;
			h1-=a2;
		}
		else
		{
			ans.push_back("HEAL");
			h1+=c;
			h1-=a2;
		}
	}
	cout<<ans.size()<<endl;
	int L=ans.size();
	for(int i=0; i<L;i++)
		cout<<ans[i]<<endl;
	return 0;
}

