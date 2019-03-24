#include "bits/stdc++.h"
using namespace std;

int main()
{
    string S;
    cin >> S;
    int L = S.size();
    stack <char> stk;
    stk.push(S[0]);
    int res = 0;
    for(int i = 1; i < L; ++i){
        if(stk.empty() == false && stk.top() == S[i])
        {
            stk.pop();
            res++;
        }
        else{
            stk.push(S[i]);
        }
    }
    if((res % 2))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}