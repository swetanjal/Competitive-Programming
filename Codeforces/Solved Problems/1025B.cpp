#include "bits/stdc++.h"
using namespace std;
const int MAXN = 150000;
int N;
long long A[MAXN];
long long B[MAXN];
set <long long> prime;

void factorize(long long S)
{
	if(S == 1)
		return;
	
	int cnt = 0;
	while((S % 2) == 0)
	{
		//cout << S << endl;
		if(cnt == 0){
			//cout << 2 << endl;
			prime.insert(2);
		}
		S /= 2;
		cnt++;
	}
	for(long long int i = 3; (i * i) <= S; i+=2)
	{
		cnt = 0;
		while((S % i) == 0)
		{
			if(cnt == 0)
				prime.insert(i);
			S/=i;
			cnt++;
		}
	}
	if(S > 2)
		prime.insert(S);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i] >> B[i];
	}
	factorize(A[0]);
	factorize(B[0]);
	set <long long> :: iterator it;
	for(it = prime.begin(); it != prime.end(); ++it)
	{
		long long chk = *it;
		//cout << chk << endl;
		int flag = 1;
		for(int j = 1; j < N ; j++)
		{
			if((A[j] % chk == 0) || (B[j] % chk ) == 0)
				continue;
			flag = 0;
			break;
		}
		if(flag)
		{
			cout << chk << endl;
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}