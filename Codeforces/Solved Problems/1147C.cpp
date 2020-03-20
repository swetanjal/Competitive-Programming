/*
Intuition:
If a player is forced to move from the pile containing minimum number of stones, he loses.
The intuition comes from the fact that what if some piles have 0 stones? That is the minimum number of stones.
If he is forced to move that, he cannot and hence loses.
*/
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int N;
int A[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int idx = N / 2;
    sort(A, A + N);
    if(A[0] == A[idx])
        cout << "Bob\n";
    else
        cout << "Alice\n";
    return 0;
}