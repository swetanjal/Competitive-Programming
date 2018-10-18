#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,x1,x2;
    long long int x = min(x1,x2);
    if(x<=m)
    {
        cout << max(x1,x2) - x << '\n';
    }
    if(x<=m)
    {
        long long int sum=0;
        long long int i=1;
        while(m*(m+1)/2 <= x)
        {
            m--;
        }
    }
}