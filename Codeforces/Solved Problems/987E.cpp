#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N+1];
	int idx[N+1];
	for(int i=1; i<=N; i++)
	{
		cin>>A[i];
		idx[A[i]] = i;
	}
	int cnt = 0;
	for(int i=1; i<=N; i++)
	{
		if(A[i] == i)continue;
		//Get i here
		int tmp_idx = idx[i];
		int tmp_val = A[i];
		swap(A[i], A[idx[i]]);
		idx[i] = i;
		idx[tmp_val] = tmp_idx;
		cnt++;
	}
	if((cnt%2) == (3*N)%2)
		cout<<"Petr\n";
	else
		cout<<"Um_nik\n";
	return 0;
}