#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N,A,B;
	cin>>N>>A>>B;
	int cycle1=-1;
	int cycle2=-1;
	for(int i=0; i<=(N/A); i++){
		if((N-(A*i))%B == 0){
			cycle1=i;
			cycle2=(N-(A*i))/B;
			break;
		}
	}
	//cout<<(N%A)%B << " "<<(N%B)%A <<endl;
	int cnt=1;
	int ret[N+1];
	//if((N%B)%A == 0)swap(A,B);
	if(!(cycle1 == -1 && cycle2==-1)){
		int cycles = cycle1 ; // This many cycles of length A
		for(int i=1; i<=cycles; i++){
			int st = cnt;
			int en = cnt+A-1;
			for(int j=st; j<en; j++)ret[j]=j+1;
			ret[en] = st;
			cnt = en+1;
		}
		cycles = cycle2;
		for(int i=1; i<=cycles; i++){
			int st = cnt;
			int en = cnt+B-1;
			for(int j=st; j<en; j++)ret[j]=j+1;
			ret[en] = st;
			cnt = en+1;
		}
		for(int i=1; i<=N; i++)cout<<ret[i]<<" ";
			cout<<endl;
	}
	else
		cout<<"-1\n";

	return 0;
}