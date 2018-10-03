#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
long long K;
long long A[MAXN];
map < pair <long long, int> , int > H;

long long power(long long a, long long b)
{
	long long p = 1;
	for(int i = 1; i <= b; i++)
		p = (p * a) % K;
	return p % K;
}

int main()
{
	cin >> N >> K; 
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		long long mod = A[i] % K;
		int cnt = 0;
		long long copy = A[i];
		while(copy > 0)
		{
			copy /= 10;
			cnt++;
		}
		pair <long long, int> p1 = make_pair(mod, cnt);
		if(H.find(p1) != H.end())
			H[p1]++;
		else
			H[p1] = 1;
	}
	long long ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 1; j <= 10; j++){
			long long xxx = ((A[i] % K) * power(10, j)) % K;
			pair <long long, int> pp = make_pair((K - xxx) % K , j);
			long long copy = A[i];
			int cnt = 0;
			while(copy > 0)
			{
				copy /= 10;
				cnt++;
			}
			if(H.find(pp) != H.end())
			{
				if((A[i] % K) == ((K - xxx) % K) && cnt == j)
					ans = ans + (H[pp] - 1);
				else
					ans = ans + H[pp];
			}
		}
	}
	cout << ans << endl;
	return 0;
}