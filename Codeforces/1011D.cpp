#include "bits/stdc++.h"
using namespace std;
const int MAXN = 30;

int N;
long long M;
bool A[MAXN];


int main()
{
	cin>>M>>N;
	int queries = 0;
	for(int i = 0; i < N; i++){
		cout<<M<<endl;
		fflush(stdout);
		int response = 0;
		cin>>response;
		if(response == 1){
			A[i] = false;
		}
		else
			A[i] = true;
		if(response == 0){
			cout<<M<<endl;
			exit(0);
		}
		queries++;
	}
	int low = 1; int high = M;
	int mid; int cnt = 0;
	for(int i = 1; i <= 30; i++){
		mid = (high + low) / 2;
		cout<<mid<<endl;
		fflush(stdout);
		int response = 0;
		cin>>response;
		if(response == 0)
		{
			cout<<mid<<endl;
			exit(0);
		}
		if((response == -1 && A[cnt] == true) || (response == 1 && A[cnt] == false))
			high = mid - 1;
		else
			low = mid + 1;
		cnt++;
		if(cnt == N)
			cnt = 0;
		queries++;
	}
	//cout<<mid<<endl;
	//while(true);
	return 0;
}