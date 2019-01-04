#include "bits/stdc++.h"
using namespace std;
const int MAXN = 20;
int N;
long long int A[MAXN];
int flag;
void rec(int ind, long long int sum)
{
    if(ind == N)
    {
        if(sum % 360 == 0)
        {
            flag = 1;
            return;
        }
        return;
    }
    rec(ind + 1, sum + A[ind]);
    rec(ind + 1, sum - A[ind]);
}


int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    rec(0, 0);
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}