#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
long long X[MAXN];
long long Y[MAXN];
bool chk(long long S)
{
	for(int i = 0; i < N; i++){
		long long y = S - X[i];
		//cout << y << endl;
		if(Y[i] <= y)
			continue;
		return false;
	}
	return true;
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> X[i] >> Y[i];
	long long low = 0; long long high = 2e9;
	long long mid;
	long long ans = -1;
	while(high >= low)
	{
		mid = (high + low) / 2;
		if(chk(mid)){
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans << endl;
	return 0;
}