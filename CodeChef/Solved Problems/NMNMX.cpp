#include "bits/stdc++.h"
using namespace std;

long long C[5005][5005];
const long long M = 1e9 + 7;

void BinCoef(int n, int k)
{
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<= min(i,k); j++)
        {
            if (j==0 || j==i) C[i][j] = 1;
            else 
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%(M-1);
        }
    }
    return;
}

long long exp(long long b, long long e)
{
    long long p = 1;
	while(e > 0)
	{
		if (e%2 == 1)
			p = (p * b)%M;
		b = (b * b)%M;
		e = e/2;
    }
    return (p % M);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);
        BinCoef((n-1), (k-1));
        long long ind[n];
        for (int i=0; i<n; i++)
        {
            ind[i] = C[n-1][k-1] - C[n-1-i][k-1] - C[i][k-1] + 2*(M-1);
        }
        long long ans = 1;
        for (int i=0; i<n; i++)
        {
            long long tmp = exp(arr[i], ind[i]);
            ans = (ans*tmp)%M;
        }
        cout << (ans % M) << endl;
    }
    return 0;
}