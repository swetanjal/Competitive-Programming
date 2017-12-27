#include <bits/stdc++.h>
using namespace std;
int N,L,MAX;
string S[5005];
int DIFF[5005][5005];
int Swap[26][26];
int TMP;
char A[5005];
int freq[5005][26];
void calc()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<L; j++)
			freq[i][S[i][j]-97]++;
	}
}
int diff(int x, int y)
{
	int ret=0;
	for(int i=0; i<L; i++)
	{
		if(S[x][i]!=S[y][i])
			ret++;
	}
	return ret;
}
int check()
{
	for(int i=0; i<N; i++)
	{
		int cnt=0;
		for(int j=0; j<L; j++)
		{
			if(S[i][j]!=A[j])cnt++;
		}
		if(cnt==0)
		{
			int yyyy=0;
			for(int j=0; j<26; j++)
				if(freq[i][j]>1)yyyy=1;
			if(yyyy)continue;
			return 0;
		}
		if(cnt==1 || cnt>2)return 0;
		char lol='\0'; char bol='\0';
		for(int j=0; j<L; j++)
		{
			if(S[i][j]!=A[j])
			{
				if(lol=='\0' && bol=='\0')
				{
					lol=S[i][j];
					bol=A[j];
				}
				else
				{
					if(bol==S[i][j] && lol==A[j]){
						//do nothing actually
					}
					else return 0;
				}
			}
		}

	}
	return 1;
}
int generate1(int x, int y, char a, char b)
{
	int flag1=0;
	int flag2=0;
	for(int i=0; i<L; i++)
	{
		if(S[x][i]==a && S[y][i]==b && flag1==0)
		{	
			A[i]=b;
			flag1=1;
		}
		else if(S[x][i]==b && S[y][i]==a && flag2==0)
		{
			A[i]=a;
			flag2=1;
		}
		else
			A[i]=S[x][i];
	}
	flag1=0; flag2=0;
	if(check())return 1;
	for(int i=0; i<L; i++)
	{
		if(S[x][i]==a && S[y][i]==b && flag1==0)
		{	
			A[i]=a;
			flag1=1;
		}
		else if(S[x][i]==b && S[y][i]==a && flag2==0)
		{
			A[i]=b;
			flag2=1;
		}
		else
			A[i]=S[y][i];
	}
	return check();
}
int chkkk(int x, int y,char a, char b, char c)
{
	for(int i=0; i<L; i++)
	{
		if(S[x][i]==a && S[y][i]==b)
			A[i]=b;
		else if(S[x][i]==b && S[y][i]==c)
			A[i]=a;
		else
			A[i]=S[x][i];
	}
	if(check())
	return 1;
	for(int i=0; i<L; i++)
	{
		if(S[x][i]==a && S[y][i]==b)
			A[i]=a;
		else if(S[x][i]==b && S[y][i]==c)
			A[i]=b;
		else
			A[i]=S[y][i];
	}
	return check();
}
int chk(int x, int y)
{
	//int k=0;
	for(int i=0; i<L; i++)
	{
		if(S[x][i]!=S[y][i])
		{
			//cout<<S[x][i]<<" "<<S[y][i]<<endl;
			Swap[S[x][i]-97][S[y][i]-97]++;	
			//k++;
			//cout<<S[x][i]-97<<" "<<S[y][i]-97<<endl;
		}
	}
	if(TMP==2)
	{
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<26; j++)
			{
				if(i==j)continue;
				if(Swap[i][j]==1)
				{
					if(Swap[j][i]==1)
						return generate1(x,y,(char)(97+i),(char)(97+j));
					else
						return 0;
				}
			}
		}
	}
	else if(TMP==3)
	{
		char a[3]; char b[3]; int cnt=0;
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<26; j++)
			{
				if(i==j)continue;
				if(Swap[i][j]==1)
				{
					a[cnt]=(char)(97+i);
					b[cnt]=(char)(97+j);
					//cout<<(char)(97+i)<<(char)(97+j)<<endl;
					cnt++;
				}
			}
		}
		//cout<<cnt<<endl;
		if(cnt!=3)return 0;
		if(a[1]!=b[0])
		{
			//swap 1 and 2
			int tmp_a=a[2], tmp_b=b[2];
			a[2]=a[1], b[2]=b[1];
			a[1]=tmp_a, b[1]=tmp_b;
		}
		//cout<<a[0]<<a[1]<<a[2]<<endl;

		/*Now check*/
		if(a[0]==b[2] && b[0]==a[1] && b[1]==a[2])
		{
			if(chkkk(x,y,a[0],a[1],a[2]) || chkkk(x,y,a[2],a[0],a[1]) || chkkk(x,y,a[1],a[2],a[0]))
				return 1;
			else return 0;
		}
		else
			return 0;
	}
	else if(TMP==4)
	{
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<26; j++)
			{
				if(i==j)continue;
				if(Swap[i][j]==Swap[j][i] && Swap[i][j]!=0)
				{
					int ttt=generate1(x,y,(char)(97+i),(char)(97+j));
					if(ttt)	
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	cin>>N>>L;
	for(int i=0; i<N; i++)
		cin>>S[i];
	calc();
	MAX=0;
	int flag=1;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			DIFF[i][j]=diff(i,j);
			MAX=max(MAX,DIFF[i][j]);
		}
	}
	int lll=1;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(DIFF[i][j]==MAX)
			{
				lll=0;
				TMP=DIFF[i][j];
				if(DIFF[i][j]==0)
				{
					flag=1;
					cout<<S[i][1]<<S[i][0];
					for(int k=2; k<L; k++)
						cout<<S[i][k];
					cout<<endl;
					break;
				}
				if(DIFF[i][j]!=3 && DIFF[i][j]!=2 && DIFF[i][j]!=4)
				{
					flag=0;
					break;
				}
				flag=chk(i,j);
				if(flag)
				{
					for(int k=0; k<L; k++)cout<<A[k];
					cout<<endl;
				}
				break;
			}
		}
		if(lll==0)break;
	}
	if(flag==0)cout<<"-1\n";
	else if(N==1)
	{
		cout<<S[0][1]<<S[0][0];
		for(int k=2; k<L; k++)
		cout<<S[0][k];
		cout<<endl;
	}	
	return 0;
}