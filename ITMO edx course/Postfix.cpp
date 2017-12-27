#include <bits/stdc++.h>
using namespace std;
long long eval(long long A, long long B, char x)
{
	if(x=='+')return (A+B);
	else if(x=='-')return (A-B);
	return (A*B);
}
int main()
{
	ifstream cin("postfix.in");
	ofstream cout("postfix.out");
	stack <long long> S;
	string s;
	getline(cin,s);
	s=s+" ";
	int l=s.size(); long long curr=0;
	for(int i=0; i<l; i++)
	{
		char x=s[i];
		if(x>='0' && x<='9')curr=(curr*10)+(x-'0');
		else if(x==' '){
			//if(curr!=0)
			S.push(curr);
			curr=0;
		}
		else
		{
			long long X=S.top(); S.pop(); long long Y=S.top();
			long long lol=eval(Y,X,x);
			S.pop();
			curr=lol;
			//S.push(lol);
		}
	}
	cout<<S.top()<<"\n";
	return 0;
}
