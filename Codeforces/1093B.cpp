#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string S;
        cin >> S;
        int L = S.size();
        char A[L];
        int fine = 0;
        for(int i = 1; i < L; ++i)
        {
            if(S[i] != S[i - 1])
                fine = 1;
        }
        if(fine == 0){
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < L; ++i)
            A[i] = S[i];
        sort(A, A + L);
        for(int i = 0; i < L; ++i)
            cout << A[i];
        cout << endl;
    }
    return 0;
}