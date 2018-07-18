#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e3 + 5;
int N, K;

struct element{
	int idx;
	long long val;
};

element A[MAXN];

bool cmp1(element a, element b)
{
	return a.val < b.val;
}

bool cmp2(element a, element b)
{
	return a.idx < b.idx;
}

int main()
{
	cin>>N>>K;
	for(int i = 0; i < N; i++){
		cin>>A[i].val;
		A[i].idx = i;
	}
	sort(A, A + N, cmp1);
	element B[K];
	int cnt = 0;
	for(int i = N - 1; i >= N - K; i--)
	{
		B[cnt].val = A[i].val;
		B[cnt].idx = A[i].idx;
		cnt++;
	}
	sort(B, B + K, cmp2);
	long long ret = 0;
	for(int i = 0; i < K; i++)
		ret += B[i].val;
	cout<<ret<<endl;
	if(K == 1){
		cout<<N<<endl;
		return 0;
	}
	for(int i = 0; i < K; i++){
		if(i == 0){
			cout<<(B[i].idx + 1)<<" ";
		}
		else if(i == (K - 1)){
			int tmp = B[i].idx - B[i - 1].idx;
			tmp = tmp + (N - 1) - B[i].idx;
			cout<<tmp<<endl;
		}
		else
			cout<<(B[i].idx - B[i - 1].idx)<<" ";
	}
	//cout<<endl;
	return 0;
}