#include "bits/stdc++.h"
using namespace std;
const int MAXNM = 105;

int A[MAXNM];
int N, M;

bool chk(int k)
{
	int cnt = 0;
	for(int i = 0; i < M; i++){
		if(A[i] == A[i + k - 1]){
			i = i + k - 1;
			cnt++;
		}
	}
	if(cnt >= N)
		return true;
	return false;
}

int main()
{
	cin>>N>>M;
	for(int i = 0; i < M; i++)
		cin>>A[i];
	sort(A, A + M);
	//cout<<chk(1)<<endl;
	int low = 1; int high = 105; int ans = 0;
	while(high >= low)
	{
		int mid = (high + low)/2;
		if(chk(mid)){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout<<ans<<endl;
	return 0;
}