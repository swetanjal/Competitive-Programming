#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N;
	cin>>N;
	long long A[N];
	for(int i = 0; i < N; i++)
	{
		cin>>A[i];
	}
	long long cum[N];
	cum[0] = A[0];
	for(int i = 1; i < N; i++){
		cum[i] = cum[i - 1] + A[i];
	}
	long long ans = 0;
	long long tmp = 0;
	for(int i = N - 1; i >= 0; i--){
		tmp += A[i];
		int low = 0; int high = i - 1;
		while(high >= low){
			int mid = (high + low)/2;
			if(cum[mid] == tmp){
				ans = tmp;
				break;
			}
			else if(cum[mid] >= tmp){
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}