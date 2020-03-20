#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    char S[N];
    long long res = 0;
    for(int i = 0; i < N; ++i)
    {
        cin >> S[i];
        int num = S[i] - '0';
        if((num % 2) == 0){
            //cout << i << endl;
            res = (res + (i + 1));
        }
    }
    cout << res << endl;
    return 0;
}