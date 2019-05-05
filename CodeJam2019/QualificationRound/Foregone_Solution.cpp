#include "bits/stdc++.h"
using namespace std;
int T, L;
string S;
int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> S;
        int L = S.size();
        string num1 = "";
        string num2 = "";
        for(int i = 0; i < L; ++i){
            if(S[i] == '8'){
                num1 += "5";
                num2 += "3";
            }
            else if(S[i] == '7'){
                num1 += "5";
                num2 += "2";
            }
            else if(S[i] == '9'){
                num1 += "7";
                num2 += "2";
            }
            else if((S[i] - '0') % 2 == 0){
                int k = (S[i] - '0') / 2;
                num1 = num1 + (char)(48 + k);
                num2 = num2 + (char)(48 + k);
            }
            else{
                int k = (S[i] - '0');
                num1 = num1 + (char)(48 + (int)ceil(k * 1.0 / 2));
                num2 = num2 + (char)(48 + (int)floor(k * 1.0 / 2));
            }
        }
        cout << "Case #" << cases << ": " << num1 << " " << num2 << endl;
    }
    return 0;
}