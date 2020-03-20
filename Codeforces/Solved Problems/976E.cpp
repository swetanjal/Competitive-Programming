#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;

struct element{
	long long health;
	long long damage;
	long long diff;
};

bool comp(element X, element Y)
{
	return X.diff > Y.diff;
}

int N, a, b;
//a is the number of doubling possible.
//b is the number of swaps possible
long long power[25];
element A[MAXN];
long long cum[MAXN];
long long ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	power[0] = 1;
	for(int i = 1; i <=20; i++)
		power[i] = 2 * power[i - 1];
	cin>>N>>a>>b;
	long long ans = 0;
	for(int i = 0; i < N; i++)
	{
		cin>>A[i].health>>A[i].damage;
		A[i].diff = A[i].health - A[i].damage;
		ans += A[i].damage;
	}
	sort(A, A + N, comp);
	cum[0] = max(0LL, A[0].diff);
	for(int i = 1; i < N; i++)
	{
		cum[i] = max(cum[i - 1], A[i].diff + cum[i - 1]);
	}
	ret = ans;
	for(int i = 0; i < N; i++)
	{
		//Doubling the health as much as possible
		if(b == 0)continue;
		long long new_health = power[a] * A[i].health;
		if(b >= 1){
			long long new_ans = ans - A[i].damage + new_health;
			int new_b = b - 1;
			if(new_b >= 1){
				if(new_b <= i)
					new_ans += cum[new_b - 1];
				else{
					int rem = new_b - i;
					new_ans = new_ans + cum[i - 1] + (cum[min(i + rem, N - 1)] - cum[i]);
				}
			}
			ret = max(ret, new_ans);
		}
	}
	cout<<ret<<endl;
	return 0;
}