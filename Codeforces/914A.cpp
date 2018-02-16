#include "bits/stdc++.h"
using namespace std;
const int MAXN=1005;
int N;
long long A[MAXN];
int main()
{
	cin>>N;
	long long ANS=LONG_LONG_MIN;
	for(int i=0; i<N; i++)
	{
		long long TMP;
		cin>>TMP;
		double sqrT=sqrt(TMP);
		long long ch=(long long)sqrT;
		if((ch*ch)==TMP){
			continue;
		}
		else{
			ANS=max(ANS,TMP);
		}
	}
	cout<<ANS<<endl;
	return 0;
}