#include "bits/stdc++.h"
using namespace std;
const int MAX=100005;
int T,N;
string S[MAX];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>S[i];
		int a=0; int b=0; int ab=0; int ba=0;
		for(int i=0; i<N; i++)
		{
			if(S[i]=="a" || S[i]=="aa")a++;
			else if(S[i]=="b" || S[i]=="bb")b++;
			else if (S[i]=="ab")ab++;
			else ba++;
		}
		if(ab==0 && ba==0 && a==0)cout<<"1\n";
		else if(ab==0 && ba==0 && b==0)cout<<"1\n";
		else if(ab==0 && ba==0)cout<<"2\n";
		else{
			int cnt=1;
			int ANS1=2;
			int copyab=ab; int copyba=ba;
			ba--;
			while((ba>0 && (cnt%2)==0) || (ab>0 && (cnt%2)!=0))
			{
				ANS1++;
				if((cnt%2)==0)ba--;
				else ab--;
				cnt++;
			}
			while(ba>0){
				ba--;
				ANS1+=2;
			}
			while(ab>0){
				ab--;
				ANS1+=2;
			}
			ab=copyab; ba=copyba;
			int ANS2=2;
			cnt=1;
			ab--;
			while((ba>0 && (cnt%2)!=0) || (ab>0 && (cnt%2)==0))
			{
				ANS2++;
				if((cnt%2)!=0)ba--;
				else ab--;
				cnt++;
			}
			
			while(ba>0){
				ba--;
				ANS2+=2;
			}
			while(ab>0){
				ab--;
				ANS2+=2;
			}
			int ANS=min(ANS1,ANS2);
			cout<<ANS<<endl;
		}
	}
	return 0;
}