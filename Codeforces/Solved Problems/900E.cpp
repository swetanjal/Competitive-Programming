#include <bits/stdc++.h>
using namespace std;
int N,M;
string S;
int DP[100005][2];
int MAX[100005];
int ANS[100005];
int cum[100005];
int main()
{
	cin>>N;
	cin>>S;
	cin>>M;
	if(S[0]=='?')cum[0]=1;
	for(int i=1; i<N; i++)
	{
		if(S[i]=='?')
			cum[i]=cum[i-1]+1;
		else
			cum[i]=cum[i-1];
	}
	/*Some base cases*/
	if(S[0]=='a')
		DP[0][0]=1;
	else if(S[0]=='b')
		DP[0][1]=0;
	else
	{
		DP[0][0]=1;
		DP[0][1]=0;
	}
	/****************/
	for(int i=1; i<N; i++)
	{
		if(S[i]=='a')
		{
			DP[i][0]=1+DP[i-1][1];
		}
		else if(S[i]=='b')
		{
			if(DP[i-1][0]>0)
				DP[i][1]=1+DP[i-1][0];
		}
		else
		{
			DP[i][0]=1+DP[i-1][1];
			if(DP[i-1][0]>0)
				DP[i][1]=1+DP[i-1][0];		
		}
	}
	if(M==1 && (S[0]=='a' || S[0]=='?'))
		MAX[0]=1;
	if(M==1 && S[0]=='?')
		ANS[0]=1;
	for(int i=1; i<N; i++)
	{
		if(S[i]=='a')
		{
			if((M%2)==1 && DP[i][0]>=M)
			{
				int idx=i-M;
				if(idx==-1)
					MAX[i]=max(MAX[i-1],1);
				else
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
			}
			else
				MAX[i]=MAX[i-1];
		}
		else if(S[i]=='b')
		{
			if((M%2)==0 && DP[i][1]>=M)
			{
				int idx=i-M;
				if(idx==-1)
					MAX[i]=max(MAX[i-1],1);
				else
					MAX[i]=max(MAX[i-1],1+MAX[idx]);	
			}
			else
				MAX[i]=MAX[i-1];
		}
		else
		{
			if((M%2)==1 && DP[i][0]>=M)
			{
				int idx=i-M;
				if(idx==-1)
					MAX[i]=max(MAX[i-1],1);
				else
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
			}
			else if((M%2)==0 && DP[i][1]>=M)
			{
				int idx=i-M;
				if(idx==-1)
					MAX[i]=max(MAX[i-1],1);
				else
					MAX[i]=max(MAX[i-1],1+MAX[idx]);	
			}
			else
				MAX[i]=MAX[i-1];
		}
	}
	//cout<<MAX[N-1]<<endl;
	/***************************************************************************/
	for(int i=1; i<N; i++)
	{
		if(S[i]=='a')
		{
			if((M%2)==1 && DP[i][0]>=M)
			{
				int idx=i-M;
				if(idx==-1)
				{
					MAX[i]=max(MAX[i-1],1);
					if(MAX[i-1]==1)
						ANS[i]=min(ANS[i-1],cum[i]);
					else if(MAX[i-1]>1)
						ANS[i]=ANS[i-1];
					else
						ANS[i]=cum[i];
				}	
				else
				{
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
					if(MAX[i-1]==1+MAX[idx])
						ANS[i]=min(ANS[i-1],ANS[idx]+cum[i]-cum[idx]);
					else if(MAX[i-1]>(1+MAX[idx]))
						ANS[i]=ANS[i-1];
					else
						ANS[i]=ANS[idx]+cum[i]-cum[idx];
				}
			}
			else
			{
				MAX[i]=MAX[i-1];
				ANS[i]=ANS[i-1];
			}
		}
		else if(S[i]=='b')
		{
			if((M%2)==0 && DP[i][1]>=M)
			{
				int idx=i-M;
				if(idx==-1)
				{
					MAX[i]=max(MAX[i-1],1);
					if(MAX[i-1]==1)
						ANS[i]=min(ANS[i-1],cum[i]);
					else if(MAX[i-1]>1)
						ANS[i]=ANS[i-1];
					else
						ANS[i]=cum[i];
				}	
				else
				{
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
					if(MAX[i-1]==1+MAX[idx])
						ANS[i]=min(ANS[i-1],ANS[idx]+cum[i]-cum[idx]);
					else if(MAX[i-1]>(1+MAX[idx]))
						ANS[i]=ANS[i-1];
					else
						ANS[i]=ANS[idx]+cum[i]-cum[idx];
				}
			}
			else
			{
				MAX[i]=MAX[i-1];
				ANS[i]=ANS[i-1];
			}
		}
		else
		{
			if((M%2)==1 && DP[i][0]>=M)
			{
				int idx=i-M;
				if(idx==-1)
				{
					MAX[i]=max(MAX[i-1],1);
					if(MAX[i-1]==1)
						ANS[i]=min(ANS[i-1],cum[i]);
					else if(MAX[i-1]>1)
						ANS[i]=ANS[i-1];
					else
						ANS[i]=cum[i];
				}	
				else
				{
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
					if(MAX[i-1]==1+MAX[idx])
						ANS[i]=min(ANS[i-1],ANS[idx]+cum[i]-cum[idx]);
					else if(MAX[i-1]>(1+MAX[idx]))
						ANS[i]=ANS[i-1];
					else
						ANS[i]=ANS[idx]+cum[i]-cum[idx];
				}
			}
			else if((M%2)==0 && DP[i][1]>=M)
			{
				int idx=i-M;
				if(idx==-1)
				{
					MAX[i]=max(MAX[i-1],1);
					if(MAX[i-1]==1)
						ANS[i]=min(ANS[i-1],cum[i]);
					else if(MAX[i-1]>1)
						ANS[i]=ANS[i-1];
					else
						ANS[i]=cum[i];
				}	
				else
				{
					MAX[i]=max(MAX[i-1],1+MAX[idx]);
					if(MAX[i-1]==1+MAX[idx])
						ANS[i]=min(ANS[i-1],ANS[idx]+cum[i]-cum[idx]);
					else if(MAX[i-1]>(1+MAX[idx]))
						ANS[i]=ANS[i-1];
					else
						ANS[i]=ANS[idx]+cum[i]-cum[idx];
				}	
			}
			else
			{
				MAX[i]=MAX[i-1];
				ANS[i]=ANS[i-1];
			}
		}
	}
	cout<<ANS[N-1]<<endl;
	/*
	for(int i=0; i<N; i++)
	{
		if(S[i]=='a')cout<<DP[i][0]<<endl;
		else if(S[i]=='b')cout<<DP[i][1]<<endl;
		else cout<<DP[i][0]<<" "<<DP[i][1]<<endl;
	}
	*/
	return 0;
}