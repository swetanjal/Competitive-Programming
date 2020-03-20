#include "bits/stdc++.h"
using namespace std;
const int MAX=2e5+5;
struct element{
	long long a;
	long long t;
	int idx;
};

int N;
long long T;
element A[MAX];
bool comp(element X, element Y){
	return X.t<Y.t;
}
bool chk(int S)
{
	long long time=0;
	int cnt=0;
	for(int i=0; i<N; i++)
	{
		if(S<=A[i].a && (time+A[i].t)<=T)
		{
			time+=A[i].t;
			cnt++;
		}
	}
	if(cnt>=S)return true;
	return false;
}
void print(int S)
{
	long long time=0;
	int cnt=0;
	vector <int> ANS;
	for(int i=0; i<N; i++)
	{
		if(cnt==S)break;
		if(S<=A[i].a && (time+A[i].t)<=T)
		{
			time+=A[i].t;
			cnt++;
			ANS.push_back(A[i].idx);

		}
	}
	cout<<cnt<<endl;
	for(int i=0; i<cnt; i++)cout<<ANS[i]<<" ";
	cout<<endl;
	return;
}
int main()
{
	cin>>N>>T;
	for(int i=0; i<N; i++)
	{
		cin>>A[i].a>>A[i].t;
		A[i].idx=i+1;
	}
	sort(A,A+N,comp);
	int lo=0; int hi=N;
	int pos=-1;
	while(hi>=lo){
		int mid=(hi+lo)/2;
		if(chk(mid)){
			lo=mid+1;
			pos=mid;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<pos<<endl;
	print(pos);
	return 0;
}