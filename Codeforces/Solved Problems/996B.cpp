#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin>>N;
	long long A[N];
	long long minimum = LONG_LONG_MAX;
	for(int i=0; i<N; i++){
		cin>>A[i];
		minimum = min(minimum, A[i]);
	}
	int moves = minimum;
	int start = minimum % N;
	int pos = -1;
	for(int i = start; i<N; i++)
	{
		if((A[i] - moves) <= 0)
		{
			pos = (i + 1);
			break;
		}
		moves++;
	}
	if(pos == -1){
		for(int i = 0; i < start; i++)
		{
			if((A[i] - moves) <= 0)
			{
				pos = (i + 1);
				break;
			}
			moves++;
		}
	}
	cout<<pos<<endl;
	return 0;
}
