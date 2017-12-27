/*
ID: swetanj2
LANG: C++
TASK: zerosum
*/
#include <bits/stdc++.h>
using namespace std;
int N;
vector <string> pro;
bool eval(string joke)
{
	joke=joke+'+';
	int curr=1;
	char last='+';
	int L=joke.size();
	int sum=0;
	for(int i=1; i<L; i++)
	{
		
		if(joke[i]==' '){
			continue;
		}
		else if(joke[i]=='+'){
			if(last=='+')
			{
				sum+=curr;
			}
			else if(last=='-')
			{
				sum-=curr;
				last='+';
			}
			curr=0;
		}
		else if(joke[i]=='-'){
			if(last=='+')
			{
				last='-';
				sum+=curr;
			}
			else if(last=='-')
			{
				sum-=curr;
			}
			curr=0;
		}
		else
		{
			curr=(curr*10)+(joke[i]-48);
		}
	}
	if(sum==0)return true;
	return false;
}
void rec(int cnt, char A[])
{
	if(cnt==N-1){
		string fool="";
		for(int i=1; i<N; i++)
		{
			fool=fool+char(48+i)+A[i-1];
		}
		fool=fool+char(48+N);
		if(eval(fool))pro.push_back(fool);
		return;
	}
	char lol[cnt+1];
	for(int i=0; i<cnt; i++)lol[i]=A[i];
	lol[cnt]='+';
	rec(cnt+1,lol);
	lol[cnt]='-';
	rec(cnt+1,lol);
	lol[cnt]=' ';
	rec(cnt+1,lol);
}
bool compare(string a, string b)
{
	return a.compare(b)<0;
}
int main()
{
	ifstream cin("zerosum.in");
	ofstream cout("zerosum.out");
	cin>>N;
	char bol[100];
	rec(0,bol);
	sort(pro.begin(), pro.end(), compare);
	int l=pro.size();
	for(int i=0; i<l; i++)cout<<pro[i]<<endl;
	return 0;
}
