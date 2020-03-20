#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N, Q, x, y;
	cin >> N >> Q;
	if((N % 2) == 0)
	{
		while(Q--)
		{
			cin >> x >> y;
			if(((x + y) % 2) == 0){
				long long done = (N / 2) * (x - 1);
				long long int extra = 0;
				if((x % 2) == 0)
				{
					extra = (y/2) - 1;
				}
				else
				{
					extra = (y/2);
				}
				cout << done + extra + 1 << endl;
			}
			else
			{
				long long done = (N / 2) * (x - 1);
				long long int extra = 0;
				if((x % 2) != 0)
				{
					extra = (y/2) - 1;
				}
				else
				{
					extra = (y/2);
				}
				cout << done + extra + 1 + (N * N / 2)<< endl;	
			}
		}
	}
	else
	{
		while(Q--)
		{
			cin >> x >> y;
			if(((x + y) % 2) == 0)
			{
				long long done = (x / 2) * (N / 2 + 1);
				done = done + ((x - 1)  - (x / 2)) * (N / 2);
				//cout << done << endl;
				long long int extra = 0;
				if((x % 2) == 0)
				{
					extra = (y/2) - 1;
				}
				else
				{
					extra = (y/2);
				}
				cout << done + extra + 1 << endl;
			}
			else
			{
				long long done = (x / 2) * (N / 2);
				long long int extra = 0;
				done = done + ((x - 1)  - (x / 2)) * (N / 2 + 1);
				if((x % 2) != 0)
				{
					extra = (y/2) - 1;
				}
				else
				{
					extra = (y/2);
				}
				cout << done + extra + 1 + (N * N / 2 + 1) << endl;
			}
		}
	}
	return 0;
}