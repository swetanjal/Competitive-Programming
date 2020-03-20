#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;
int A[MAX][26];
int N;
string s;
char c[MAX];
int ANS[26];
int correct=-1;
void anding(int idx)
{
	for(int i=0; i<26; i++)
		ANS[i]=ANS[i] & A[idx][i];
}
int chk()
{
	for(int i=0; i<26; i++){
		if(i==correct && ANS[i]==1)continue;
		else if(i!=correct && ANS[i]==0)continue;
		return 0;
	}
	return 1;
}
int main()
{
	cin>>N;
	
	for(int i=1; i<=N; i++)
	{
		cin>>c[i];
		cin>>s;
		if(i==N){
			correct=s[0]-97;
			break;
		}
		if(c[i]=='!')
		{
			for(int j=0; j<26; j++)A[i][j]=0;
			int L=s.size();
			for(int j=0; j<L; j++)
				A[i][s[j]-97]=1;
		}
		else if(c[i]=='.' || c[i]=='?'){
			for(int j=0; j<26; j++)A[i][j]=1;
			int L=s.size();
			for(int j=0; j<L; j++)
				A[i][s[j]-97]=0;
		}
	}
	for(int i=0; i<26; i++)ANS[i]=1;
	/*Find the pos*/
	int pos=N;
	for(int i=1; i<=N; i++)
	{
		anding(i);
		//for(int j=0; j<26; j++)cout<<A[i][j]<<" ";
		//	cout<<endl;
		if(chk()){
			pos=i;
			break;
		}
	}
	int ret=0;
	for(int i=pos+1; i<N; i++){
		if(c[i]=='?' || c[i]=='!')ret++;
	}
	cout<<ret<<endl;
	return 0;
}