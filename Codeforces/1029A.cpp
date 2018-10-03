#include "bits/stdc++.h"
using namespace std;

int main()
{
	int N, K;
	string S;
	cin >> N >> K;
	cin >> S;
	int prefix = 0;
	for(int i = 1; i < N; i++){
		int pt1 = 0;
		int pt2 = i;
		while(pt2 < N && S[pt1] == S[pt2])
		{
			pt1++;
			pt2++;
		}
		if(pt2 == N)
			prefix = max(prefix, pt1);
	}
	//cout << prefix << endl;
	string ret = S;
	for(int i = 1; i < K; i++){
		for(int j = prefix; j < N; j++)
			ret = ret + S[j];
	}
	cout << ret << endl;
	return 0;
}