#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long A,B,C,N;
	cin>>A>>B>>C>>N;
	long long pass = A + B - C;
	long long fail = N - pass;
	if( (A < C) || (B < C) || fail <= 0 || pass < 0 || (A == 0 && C!=0) || (B == 0 && C!=0) )
		cout<<"-1\n";
	else
		cout<<fail<<endl;
	return 0;
}