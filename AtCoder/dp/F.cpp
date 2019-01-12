#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e3 + 5;
int l1, l2;
string A, B;
int DP[MAXN][MAXN];


int rec(int s1, int s2)
{
    if(s1 == l1 || s2 == l2)
        return 0;
    if(DP[s1][s2] != -1)
        return DP[s1][s2];
    if(A[s1] == B[s2])
    {
        return DP[s1][s2] = max(1 + rec(s1 + 1, s2 + 1), max(rec(s1 + 1, s2), rec(s1, s2 + 1)));
    }
    else{
        return DP[s1][s2] = max(rec(s1 + 1, s2), rec(s1, s2 + 1));
    }
    return DP[s1][s2];
}

void print(int s1, int s2)
{
    if(s1 == l1 || s2 == l2)
        return;
    if(A[s1] == B[s2])
    {
        if((1 + DP[s1 + 1][s2 + 1]) >= DP[s1 + 1][s2] && (1 + DP[s1 + 1][s2 + 1]) >= DP[s1][s2 + 1])
        {
            cout << A[s1];
            print(s1 + 1, s2 + 1);
        }
        else if(DP[s1 + 1][s2] >= (1 + DP[s1 + 1][s2 + 1]) && DP[s1 + 1][s2] > DP[s1][s2 + 1])
        {
            print(s1 + 1, s2);
        }
        else{
            print(s1, s2 + 1);
        }
    }
    else{
        if(DP[s1 + 1][s2] > DP[s1][s2 + 1])
            print(s1 + 1, s2);
        else
            print(s1, s2 + 1);
    }
}

int main()
{
    cin >> A >> B;
    l1 = A.size();
    l2 = B.size();
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            DP[i][j] = -1;
    rec(0, 0);
    print(0, 0);
    cout << endl;
    return 0;
}