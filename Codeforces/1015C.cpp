#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
struct element{
	long long a;
	long long b;
	long long diff;
};

int N;
long long M;
element A[MAXN];

bool cmp(element X, element Y)
{
	return X.diff > Y.diff;
}

int main()
{
	cin>>N>>M;
	long long mini = 0;
	long long curr = 0;
	for(int i = 0; i < N; i++){
		cin>>A[i].a>>A[i].b;
		mini = mini + A[i].b;
		curr += A[i].a;
		A[i].diff = A[i].a - A[i].b;
	}
	sort(A, A + N, cmp);
	if(mini > M)
	{
		cout<<"-1\n";
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(curr > M){
			ans++;
			curr -= A[i].diff;
		}
	}
	cout<<ans<<endl;
	return 0;
}