#include "bits/stdc++.h"
using namespace std;
int N;
string A[105];
bool chk(string col)
{
	for(int i=0; i<N; i++)
	{
		if(A[i] == col)
		return true;	
	}
	return false;
}

int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>A[i];
	int cnt = 0;
	vector <string> ret;
	if(chk("purple") == false)
	{
		cnt++;
		ret.push_back("Power");
	}
	if(chk("green") == false)
	{
		cnt++;
		ret.push_back("Time");
	}
	if(chk("blue") == false)
	{
		cnt++;
		ret.push_back("Space");
	}
	if(chk("orange") == false)
	{
		cnt++;
		ret.push_back("Soul");
	}
	if(chk("red") == false)
	{
		cnt++;
		ret.push_back("Reality");
	}
	if(chk("yellow") == false)
	{
		cnt++;
		ret.push_back("Mind");
	}
	cout<<cnt<<endl;
	for(int i=0; i<cnt; i++)
		cout<<ret[i]<<"\n";
	return 0;
}