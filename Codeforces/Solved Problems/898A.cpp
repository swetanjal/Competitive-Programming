#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long N;
	cin>>N;
	int iiith=(N%10);
	if(iiith<=5)cout<<N-iiith<<endl;
	else cout<<N+10-iiith<<endl;
	return 0;
}