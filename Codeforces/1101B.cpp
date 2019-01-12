#include "bits/stdc++.h"
using namespace std;

int main()
{
    string S;
    cin >> S;
    int L = S.size();
    int open_brac = -1;
    int close_brac = -1;
    int open_col = -1;
    int close_col = -1;
    for(int i = 0; i < L; ++i){
        if(S[i] == '['){
            open_brac = i;
            break;
        }
    }
    for(int i = 0; i < L; ++i){
        if(S[i] == ':' && i > open_brac){
            open_col = i;
            break;
        }
    }
    for(int i = L - 1; i >= 0; i--){
        if(S[i] == ']'){
            close_brac = i;
            break;
        }
    }
    for(int i = L - 1; i >= 0; i--){
        if(S[i] == ':' && i < close_brac){
            close_col = i;
            break;
        }
    }
    if(open_brac == -1 || close_brac == -1 || open_col == -1 || close_col == -1 || open_col == close_col || close_col < open_col){
        cout << "-1\n";
        return 0;
    }
    int cnt = 4;
    for(int i = open_col; i <= close_col; ++i){
        if(S[i] == '|')
            cnt++;
    }    
    cout << cnt << endl;
    return 0;
}