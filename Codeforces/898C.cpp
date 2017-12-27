#include <bits/stdc++.h>
using namespace std;
int T,N;
string M;
map <string , set <string> > H;
string S;
vector <string> names;
vector <string> phone[1000005];

int chk(string a, string b)
{
	int La=a.size(); 
	int Lb=b.size();
	if(La>Lb)return 0;
	int c=La-1;
	for(int i=Lb-1; ; i--)
	{
		if(c<0)return 1;
		if(a[c]!=b[i])return 0;
		c--;
	}
	return 0;
}
bool cmp(string a, string b)
{
	return a.size()<b.size();
}
int main()
{
	cin>>T;

	while(T--)
	{
		cin>>S;
		cin>>N;
		for(int i=1; i<=N; i++)
		{
			cin>>M;
			H[S].insert(M);
		}
	}
	map <string , set <string> > :: iterator it;
	int cnt=0;
	for(it=H.begin(); it!=H.end(); ++it)
	{
		names.push_back(it->first);
		vector <string> tmp;
		set <string> :: iterator IT;
		for(IT=it->second.begin(); IT!=it->second.end(); ++IT)
		{
			tmp.push_back(*(IT));
		} 
		int L=tmp.size();
		sort(tmp.begin(), tmp.end(), cmp);
		for(int i=0; i<L; i++)
		{
			int flag=1;
			for(int j=i+1; j<L; j++)
			{
				if(chk(tmp[i],tmp[j]))
				{
					flag=0;
					break;
				}
			}
			if(flag==1)phone[cnt].push_back(tmp[i]);
		}
		//cout<<endl;
		cnt++;
	}
	int X=names.size();
	cout<<X<<endl;
	for(int i=0; i<X; i++)
	{
		int Y=phone[i].size();
		cout<<names[i]<<" "<<Y<<" ";
		for(int j=0; j<Y; j++)cout<<phone[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}