#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    if(M == 0)
        cout << "1\n";
    else if(M == N)
        cout << "0\n";
    else{
        int res = min(M, N - M);
        cout << res << endl;
    }
    return 0;
}