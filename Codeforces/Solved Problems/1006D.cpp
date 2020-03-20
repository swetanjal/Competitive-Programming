#include "bits/stdc++.h"
using namespace std;

int N;
string A,B;

int main()
{
	cin>>N;
	cin>>A;
	cin>>B;
	int ret = 0;
	for(int i = 0; i < N; i++)
	{
		if(i == (N/2) && (N % 2)==0)break;
		if(i == (N/2)){
			ret = ret + 1 - (A[i] == B[i]);
			break;
		}
		int idx = N - 1 - i;
		if(A[idx] == A[i] && B[idx] == B[i])continue;
		if(((A[idx] == B[i]) && (A[i] == B[idx])) || ((A[idx] == B[idx]) && (A[i] == B[i])))continue;
		//A[idx] matches with B[idx] && A[i] mathes with B[i]
		int add = INT_MAX;
		if((A[idx] != A[i]) && (B[idx] == B[i])){
			add = min(add, 1);
			//continue;
		}
		/*if((A[idx] == A[i]) && (B[idx] != B[i])){

			continue;
		}*/
		add = min(add, 1 - (A[idx] == B[idx]) + 1 - (A[i] == B[i]));
		add = min(add, 1 - (A[idx] == B[i]) + 1 - (A[i] == B[idx]));
		ret += add;
	}
	cout<<ret<<endl;
	return 0;
}