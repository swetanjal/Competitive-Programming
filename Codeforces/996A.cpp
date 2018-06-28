#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long N;
	cin>>N;
	long long den = N/100;
	N = N % 100;
	den += (N/20);
	N = N % 20;
	den += (N/10);
	N = N % 10;
	den += (N/5);
	N = N % 5;
	den += N;
	N = 0;
	cout<<den<<endl;
	return 0;
}