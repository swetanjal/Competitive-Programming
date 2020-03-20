#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int N;
long long S1, S2;
pair < long long, int > A[MAXN];

int main()
{
	cin >> N >> S1 >> S2;
	for(int i = 0; i < N; i++){
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A, A + N);
	for(int i = 1; i < N; i++){
		int K = i;
		long double X1 = S1 * 1.0 / K;
		long double X2 = S2 * 1.0 / (N - K);
		int low = 0; int high = N - 1; int mid;
		int pos = -1;
		while(high >= low)
		{
			mid = (high + low) / 2;
			if(A[mid].first >= X1)
			{
				pos = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		if(pos == -1)
			continue;
		int st1 = pos;
		int en1 = pos + K - 1;
		if(en1 >= N)
			continue;
		pos = -1;
		low = 0; high = N - 1;
		while(high >= low)
		{
			mid = (high + low) / 2;
			if(A[mid].first >= X2)
			{
				pos = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;	
		}
		if(pos < st1 && pos != -1)
		{
			int sz = (st1 - pos) + (N - 1 - en1);
			if(sz < (N - K) )
				continue;
			cout << "Yes\n";
			cout << K <<" "<< sz << endl;
			for(int j = st1; j <= en1; j++)
				cout << A[j].second<<" ";
			cout<<endl;
			for(int j = pos; j < st1; j++)
				cout<<A[j].second<<" ";
			for(int j = en1 + 1; j < N; j++)
				cout<<A[j].second<<" ";
			cout<<endl;
			return 0;
		}
		else if(pos != -1){
			int sz = (N - 1 - max(en1,pos-1));
			if(sz < (N - K))
				continue;
			cout << "Yes\n";
			cout << K <<" "<< sz << endl;	
			for(int j = st1; j <= en1; j++)
				cout << A[j].second<<" ";
			cout<<endl;
			for(int j = max(en1, pos-1) + 1; j < N; j++)
				cout<<A[j].second<<" ";
			cout<<endl;
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}