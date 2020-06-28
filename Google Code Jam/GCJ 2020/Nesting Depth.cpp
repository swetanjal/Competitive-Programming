#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        string s;
        cin >> s;
        int l = s.size();
        int curr_depth = 0;
        cout << "Case #" << cases << ": ";
        for(int i = 0; i < l; ++i){
            int c = s[i] - '0';
            while(c > curr_depth){
                cout << "(";
                curr_depth++;
            }
            while(curr_depth > c){
                cout << ")";
                curr_depth--;
            }
            cout << s[i];
        }
        while(curr_depth > 0)
        {
            cout << ")";
            curr_depth--;
        }
        cout << endl;
    }
}