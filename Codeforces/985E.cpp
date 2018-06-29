#include "bits/stdc++.h"
using namespace std;
const int MAXN  = 5e5 + 5;
int N, K;
long long D;
long long A[MAXN];

vector <int> possible;

int search(int low, long long element)
{
	int high = N - 1;
	int mid; int pos = -1;
	while(high >= low)
	{
		mid = (high + low)/2;
		if(A[mid] <= element)
		{
			pos = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return pos;
}

int __search__(int element)
{
	int low = 0; int high = possible.size() - 1;
	int mid; int pos = -1;
	while(high >= low)
	{
		mid = (high + low)/2;
		if(possible[mid] >= element)
		{
			pos = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	if(pos!=-1)
	return possible[pos];
	return -1;
}

int main()
{
	cin>>N>>K>>D;
	for(int i=0; i<N; i++)
		cin>>A[i];
	sort(A, A + N);
	if(K == 1)
	{
		cout<<"YES\n";
		return 0;
	}
	if(N < K)
	{
		cout<<"NO\n";
		return 0;
	}
	if((A[N - 1] - A[N - K]) <= D){
		possible.push_back(N - K);
	}
	for(int i = N - K - 1; i >= 0; i--)
	{
		int low = i + K;
		//Find the rightmost element less than equal to A[i] + D
		int high = search(i, A[i] + D) + 1;
		if(high >= N)
		{
			possible.push_back(i);
			continue;
		}
		//High and Low inclusive
		//Search for the smallest element in possible just greater than low.....
		int pos = __search__(low);
		if(pos != -1 && pos <= high)
			possible.push_back(i);
	}
	if(possible.size() > 0 && possible[possible.size() - 1] == 0)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}