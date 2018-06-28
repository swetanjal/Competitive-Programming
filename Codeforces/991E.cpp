#include "bits/stdc++.h"
using namespace std;
long long N;
int freq[10];
int A[20];
long long ans;
int L;

long long fact[20];
map < string, int > H;
void rec(int ind, string S)
{
	if(ind == L)
	{
		if(H.find(S) != H.end())return;
		H[S] = 1;
		int curr_freq[10];
		for(int i=0; i<10; i++)
			curr_freq[i] = 0;
		int N = S.size();
		for(int i=0; i<N; i++)
			curr_freq[S[i] - 48]++;
		long long prod = 1;
		for(int i=0; i<10; i++){
			if(freq[i] > 0 && curr_freq[i] == 0)
			{
				return;
			}
			prod = prod * fact[curr_freq[i]];
		}
		long long p2 = 1;
		for(int i=1; i<10; i++)
			p2 = p2 * fact[curr_freq[i]];
		long long total = (fact[N]/prod);
		if(curr_freq[0] > 0)
		{
			p2 = p2 * fact[curr_freq[0] - 1];
			total -= (fact[N - 1] / p2);
		}	

		ans += total;
		return;
	}
	rec(ind + 1, S + char(48+A[ind]));
	rec(ind + 1, S);
}

int main()
{
	fact[0] = 1;
	for(int i = 1; i < 20; i++)
		fact[i] = i * fact[i - 1];
	cin>>N;
	long long copy = N;
	while(N > 0)
	{
		freq[N%10]++;
		N = N / 10;
		L++;
	}
	int l = L;
	while(copy > 0)
	{
		A[--l] = copy % 10;
		copy /= 10;
	}
	sort(A, A+L);
	rec(0, "");
	cout<<ans<<endl;
	return 0;
}