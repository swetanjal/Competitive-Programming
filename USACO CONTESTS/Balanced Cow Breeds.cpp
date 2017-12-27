#include <bits/stdc++.h>
using namespace std;
const long long MOD=2012;
string S; int N;
map < pair <int , pair <int, int> > , long long > hash;
long long rec(int ind, int op1, int op2)
{
	if(ind==N){
		if(op1==0 && op2==0)return 1;
		return 0;
	}
	pair <int,int> p1=make_pair(ind,op1);
	pair < int , pair <int , int> > p2=make_pair(op2,p1);
	if(hash.find(p2)!=hash.end())return hash[p2];
	if(S[ind]=='(')return hash[p2]=(rec(ind+1,op1+1,op2)+rec(ind+1,op1,op2+1))%MOD;
	else
	{
		hash[p2]=0;
		if(op1>=1)hash[p2]+=rec(ind+1,op1-1,op2)%MOD;
		if(op2>=1)hash[p2]+=rec(ind+1,op1,op2-1)%MOD;
	}
	return hash[p2];
}
int main()
{
	ifstream cin("bbreeds.in");
	ofstream cout("bbreeds.out");
	cin>>S;
	N=S.size();
	cout<<rec(0,0,0)<<endl;
	return 0;
}
