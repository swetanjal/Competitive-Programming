#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    char A[N];
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int DP[N];
    if(A[N - 1] == ')')
        DP[N - 1] = -1;
    else
        DP[N - 1] = 1;
    for(int i = N - 2; i >= 0; i--)
    {
        if(DP[i + 1] > 0)
            DP[i] = DP[i + 1];
        else
        {
            if(A[i] == '(')
                DP[i] = 1 + DP[i + 1];
            else
                DP[i] = DP[i + 1] - 1;
        }
    }
    int curr = 0;
    int res = 0;
    int flag = 1;
    //for(int i = 0; i < N; ++i)
    //    cout << DP[i] << " ";
    //cout << endl;
    for(int i = 0; i < N - 1; ++i){
        if(A[i] == '('){
            curr--;
            if(curr >= 0 && flag && DP[i + 1] <= 0 && -DP[i + 1] == curr)
                res++;
            curr++;
        }   
        else{
            curr++;
            if(flag && DP[i + 1] <= 0 && -DP[i + 1] == curr)
                res++;
            curr--;
        }
        if(A[i] == '(')
            curr++;
        else
            curr--;
        if(curr < 0)
            flag = 0;
    }
    if(A[N - 1] == '('){
        A[N - 1] = ')';
    int chk = 0;
    int fl = 1;
    for(int i = 0; i < N; ++i){
        if(A[i] == '(')
            chk++;
        else
            chk--;
        if(chk < 0)
            fl = 0;
    }
    if(fl && chk == 0)
        res += 1;
    }
    cout << res << endl;
    return 0;
}