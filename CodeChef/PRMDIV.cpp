#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;

struct element{
	int a;
	long long S;
	int freq;
};

int T, N;
element A[MAXN];
long long DP[MAXN];
int prime[MAXN];
map <long long, int> H;
int idx[MAXN];
vector <int> good[MAXN];

void init()
{
	H.clear();
	for(int i = 0; i < MAXN; i++)
		good[i].clear();
}

void sieve()
{
	for(int i = 0; i < MAXN; i++)
		prime[i] = 1;
	for(int i = 2; i < MAXN; i++)
	{
		if(prime[i] == 0)continue;
		DP[i] += i;
		for(int j = i + i; j < MAXN; j+=i){
			prime[j] = 0;
			DP[j] += i;
		}
	}
}

bool comp(element X, element Y)
{
	return X.a < Y.a;
}

int main()
{
	cin >> T;
	sieve();
	while(T--)
	{
		init();
		cin>>N;
		H.clear();
		for(int i = 0; i < N; i++){
			int tmp;
			cin>>tmp;
			if(H.find(tmp) == H.end())
				H[tmp] = 1;
			else
				H[tmp]++;
		}
		N = 0;
		map <long long, int> :: iterator it;
		for(it = H.begin(); it != H.end(); ++it)
		{
			A[N].a = it -> first;
			A[N].freq = it -> second;
			A[N].S = DP[A[N].a];
			N++; 
		}
		
		for(int i = 0; i < MAXN; i++){
			idx[i] = -1;
		}
		for(int i = 0; i < N; i++){
			idx[A[i].a] = i;
		}
		for(int i = 0; i < N; i++){
			for(int j = 1; j * A[i].a < MAXN; j++)
			{
				if(idx[j * A[i].a] != -1){
					good[idx[j * A[i].a]].push_back(i);
				}
			}
		}
		long long int ret = 0;
		for(int i = 0; i < N; i++){
			int ind = idx[A[i].a];
			int L = good[ind].size();
			for(int j = 0; j < L; j++){
				if((A[i].S % A[good[ind][j]].S) == 0){
					long long tmp = (A[i].freq * 1LL * A[good[ind][j]].freq);
					if(good[ind][j] == i)
						tmp = (A[i].freq * 1LL * (A[good[ind][j]].freq - 1));
					ret = ret + tmp;
				}
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}