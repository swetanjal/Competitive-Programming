#include "bits/stdc++.h"
using namespace std;
long long A,N;
int SOD[85];
map <long long, int> XXX;

int sod(long long S)
{
	int ret=0;
	while(S>0){
		ret+=(S%10);
		S/=10;
	}
	return ret;
}
int SSS(long long S)
{
	while(S>9)
		S=sod(S);
	return S;	
}
long long mod_pow(long long a, long long b)
{
	if(b==0)return 1;
	if(b==1)return XXX[a];
	long long T=mod_pow(a,b/2);
	long long res=T*T;
	res=SOD[res];
	if((b%2)!=0)res*=XXX[a];
	return SOD[res];
}
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=82; i++)SOD[i]=SSS(i);
	while(T--)
	{
		cin>>A>>N;
		XXX[A]=SSS(A);
		//cout<<XXX[A]<<endl;
		cout<<mod_pow(A,N)<<endl;
	}
	return 0;
}