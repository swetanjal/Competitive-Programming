#include "bits/stdc++.h"
using namespace std;

int N,Q;

int freq[35];

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i=1; i<=N; i++)
	{
		int T;
		scanf("%d", &T);
		int log_= 0;
		while(T > 0)
		{
			T /= 2;
			log_++;
		}
		log_--;
		freq[log_]++;
	}
	int pow[35];
	pow[0] = 1;
	for(int i=1; i<=30; i++)
		pow[i] = pow[i - 1] * 2;
	while(Q--)
	{
		int ans = 0;
		int T;
		scanf("%d", &T);
		int k = log2(T);
		for(int i = k; i >= 0 ; i--)
		{
			//int cnt = 0;
			//cout<<i<<" "<<freq[i]<<endl;
			int sub = T/pow[i];
			if(sub <= freq[i])
			{
				ans += sub;
				T = T - (sub * pow[i]);
			}
			else
			{
				ans += freq[i];
				T = T - (freq[i] * pow[i]);
			}
			/*while(T >= pow[i] && cnt < freq[i])
			{
				cnt++;
				ans++;
				T -= pow[i];
			}*/
			if(T == 0)break;
		}
		//cout<<T<<endl;
		if(T == 0)printf("%d\n", ans);
		else
			printf("%d\n", -1);
	}
	return 0;
}