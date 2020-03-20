#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 10;
int N;
long long A[MAXN];

int main()
{
	cin>>N;
	for(int i = 0; i < 2 * N; i++)
		cin>>A[i];
	sort(A, A + 2 * N);
	long long area = abs(A[0] - A[N - 1]) * abs(A[N] - A[2 * N - 1]);
	for(int i = N; i < 2 * N - 1; i++){
		area = min(area, abs(A[0] - A[ 2 * N - 1]) * abs(A[i] - A[i - (N - 1)]));
	}
	cout<<area<<endl;
	return 0;
}