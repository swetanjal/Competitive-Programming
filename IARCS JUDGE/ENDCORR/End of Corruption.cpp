#include <bits/stdc++.h>
using namespace std;
int A,B,N,tmp;
int main()
{
	priority_queue <int , vector <int> > P;
	cin>>A>>B;
	N=A+B;
	while(N--)
	{
		cin>>tmp;
		if(tmp==-1){
			cout<<P.top()<<endl;
			P.pop();
			continue;
		}
		P.push(tmp);
	}
	return 0;
}
