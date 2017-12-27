#include <bits/stdc++.h>
using namespace std;
int N;
long long A[100005];
vector <long long> X;
int C[45];
long long P[45];
void power()
{
	P[0]=1;
	for(int i=1; i<=40; i++)
		P[i]=P[i-1]*2;
}
int chk(int S)
{
	vector <long long> tmp;
	vector <long long> T;
	int L=X.size();
	for(int i=0; i<L; i++)tmp.push_back(X[i]);
	int c[45];
	for(int i=0; i<45; i++)c[i]=C[i];
	int curr=0;
	for(int i=40; i>=0; i--)
	{
		int minimum=INT_MAX;
		for(int j=0; j<=i; j++)
		{
			if(c[j]<minimum)minimum=c[j];
		}
		minimum=min(minimum,(S-curr));
		//cout<<minimum<<endl;
		//cout<<minimum<<endl;
		for(int j=0; j<=i; j++)
			c[j]-=minimum;
		for(int j=1; j<=minimum; j++)
			T.push_back(P[i]);
		curr+=minimum;
	}
	for(int i=0; i<=40; i++)
	{
		//cout<<c[i]<<endl;
		for(int j=1; j<=c[i]; j++)
			tmp.push_back(P[i]);
	}
	sort(tmp.begin(), tmp.end());
	sort(T.begin(), T.end());
	int L1=T.size(); int L2=tmp.size();
	if(L2>L1)return 0;
	//for(int i=0; i<L1; i++)cout<<T[i]<<" ";
	//cout<<endl;
	//cout<<"Remaining : "<<endl;
	//for(int i=0; i<L2; i++)cout<<tmp[i]<<" ";
	//cout<<endl;
	int ccc=L1-1; 
	for(int i=L2-1; i>=0; i--)
	{
		if((2*T[ccc])<tmp[i])return 0;
		ccc--;
	}
	return 1;
}

void find(long long S)
{
	long long prod=1; int cnt=0;
	while(prod<=S)
	{
		if(prod==S)
		{
			C[cnt]++;
			return;
		}
		prod*=2;
		cnt++;
	}
	X.push_back(S);
	return;
}
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<N; i++)find(A[i]);
	power();
	int low=0; int high=C[0]; int mid; int pos=-1;
	//for(int i=0; i<=40; i++)cout<<C[i]<<endl;
	//chk(2);
	//chk(19);
	while(high>=low)
	{
		mid=(high+low)/2;
		if(chk(mid)){
			pos=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	if(pos==-1)cout<<"-1";
	else
		for(int i=pos; i<=C[0]; i++)cout<<i<<" ";
	cout<<endl;
	return 0;
}