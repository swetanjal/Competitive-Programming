#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
int N;
char S[MAXN];

void rev(int l, int r)
{
	while(l<=r)
	{
		char tmp = S[l];
		S[l] = S[r];
		S[r] = tmp;
		l++;
		r--;
	}
}

int main()
{
	cin>>N;
	cin>>S;
	for(int i=1; i<=N; i++)
	{
		if((N%i) == 0)
			rev(0, i-1);
	}
	for(int i=0; i<N; i++)
		cout<<S[i];
	cout<<endl;
	return 0;
}