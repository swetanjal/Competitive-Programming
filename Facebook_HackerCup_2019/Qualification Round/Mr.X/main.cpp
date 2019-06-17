#include "bits/stdc++.h"
using namespace std;

int eval(int a, int b, char o){
    if(o == '|')
        return (a | b);
    else if(o == '&')
        return (a & b);
    else if(o == '^')
        return (a ^ b);
    assert(false);
}

int main()
{
    ifstream cin("mr_x.txt");
    ofstream cout("1.out");
    int T;
    int cases = 1;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        int N = S.size();
        stack <int> V1;
        stack <int> V2;
        stack <char> op;
        for(int i = 0; i < N; ++i){
            if(S[i] == '(' || S[i] == ')' || S[i] == '|' || S[i] == '&' || S[i] == '^'){
                if(S[i] == ')')
                    op.pop();
                else
                    op.push(S[i]);
            }
            else{
                if(S[i] == 'x'){
                    V1.push(1);
                    V2.push(0);
                }
                else if(S[i] == 'X'){
                    V1.push(0);
                    V2.push(1);
                }
                else{
                    V1.push(S[i] - '0');
                    V2.push(S[i] - '0');
                }

            }
            if(op.empty() == false && op.top() != '(' && V1.size() >= 2 && S[i] != '&' && S[i] != '|' && S[i] != '^'){
                int a = V1.top(); V1.pop();
                int b = V1.top(); V1.pop();
                V1.push(eval(a, b, op.top()));
                a = V2.top(); V2.pop();
                b = V2.top(); V2.pop();
                V2.push(eval(a, b, op.top()));
                op.pop();
            }
        }
        assert(V1.size() == 1 && V2.size() == 1);
        if(V1.top() == V2.top())
            cout << "Case #" << cases << ": 0\n";
        else
            cout << "Case #" << cases << ": 1\n";
        cases++;
    }
    return 0;
}