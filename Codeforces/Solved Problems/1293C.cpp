#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    int A[2][N + 2];
    for(int i = 0; i <= (N+1); ++i)
        A[0][i] = A[1][i] = 0;
    set < pair < pair <int, int>, pair <int, int> > > S;
    while(Q--)
    {
        int r, c;
        cin >> r >> c;
        --r;
        A[r][c] = 1 - A[r][c];
        if(A[r][c] == 1){
            if(A[1 - r][c + 1] == 1)
                S.insert({{r, c}, {1 - r, c + 1}});
            if(A[1 - r][c - 1] == 1)
                S.insert({{1 - r, c - 1}, {r, c}});
            if(A[1 - r][c] == 1)
                S.insert({{0, c}, {1, c}});
        }
        else{
            S.erase({{r, c}, {1 - r, c + 1}});
            S.erase({{1 - r, c - 1}, {r, c}});
            S.erase({{0, c}, {1, c}});
        }
        if(S.empty() && A[0][1] == 0 && A[1][N] == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}