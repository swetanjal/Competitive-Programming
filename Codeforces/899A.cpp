#include <bits/stdc++.h>
using namespace std;
int A[3];
int main()
{
	int N;
	cin>>N;
	int tmp;
	for(int i=1; i<=N; i++)
	{
		cin>>tmp;
		A[tmp]++;
	}
	int ANS=min(A[1],A[2]);
	A[1]-=ANS;
	A[2]-=ANS;
	ANS=ANS+(A[1]/3);
	cout<<ANS<<endl;
	return 0;
}