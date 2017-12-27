/*
ID: swetanj2
LANG: C++
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;
long long T;
int size;
bool round(long long s)
{
	//return true;
	map <int, int> hash;
	int A[size+1];
	for(int i=1; i<=size; i++)
	{
		A[i]=(s%(long long)pow(10,size-i+1))/(long long)pow(10,size-i);
		hash[A[i]]=0;
	}
	int N=A[1];
	int ind=1;
	int st=N;
	while(true)
	{
		hash[N]++;
		for(int i=1; i<=N; i++)
		{
			++ind;
			if(ind>size)ind=1;
		}
		int flag=0;
		for(int i=1; i<=size; i++)
		{
			if(hash[A[i]]!=1){
				flag=1;
				break;
			}
		}
		if((flag==0)&&(st==A[ind]))return true;
		if(flag==0)return false;
		for(int i=1; i<=size; i++)
		if(hash[A[i]]>1)return false;
		N=A[ind];
	}
	//return true;
}
bool unique(long long s)
{
	int a[10];
	for(int i=0; i<=9; i++)a[i]=0;
	for(int i=1; i<=size; i++)
	{
		int dig=(s%(long long)pow(10,size-i+1))/(long long)pow(10,size-i);
		a[dig]++;
	}
	for(int i=0; i<=9; i++){
		if(a[0]>=1)return false;
		if(a[i]>1)return false;
	}
	return true;
}
int main()
{
	ifstream cin("runround.in");
	ofstream cout("runround.out");
	cin>>T;
	int flag=0;
	for(long long i=T+1;; i++)
	{
		size=0;
	    long long copy=i;
		while(copy>0)
	    {  
	    	copy=copy/10;
		    size++;
	    }
		if(unique(i))
		{
			if(round(i)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
