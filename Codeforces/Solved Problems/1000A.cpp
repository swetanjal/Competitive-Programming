#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e2 + 5;
int cntA[6][3];
int cntB[6][3];
int main()
{
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		string S;
		cin>>S;
		int L = S.size();
		int p = -1;
		for(int j=0; j<L; j++)
		{
			if(S[j]!='X')
			{
				if(S[j]=='M')
					p = 0;
				else if(S[j] == 'L')
					p = 1;
				else
					p = 2;
			}
		}
		cntA[L][p]++;
	}
	for(int i=0; i<N; i++){
		string S;
		cin>>S;
		int L = S.size();
		int p = -1;
		for(int j=0; j<L; j++)
		{
			if(S[j]!='X')
			{
				if(S[j]=='M')
					p = 0;
				else if(S[j] == 'L')
					p = 1;
				else
					p = 2;
			}
		}
		cntB[L][p]++;
	}
	int ret = 0;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<3; j++)
		{
			ret += abs(cntA[i][j] - cntB[i][j]);
		}
	}
	cout<<ret/2<<endl;
	return 0;
}