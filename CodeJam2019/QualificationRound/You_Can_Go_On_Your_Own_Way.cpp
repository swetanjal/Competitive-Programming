#include "bits/stdc++.h"
using namespace std;
int T, N;
string S;
int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> N;
        N = 2 * N - 2;
        cin >> S;
        int pos = -1;
        cout << "Case #" << cases << ": ";
        for(int i = 1; i < N; ++i){
            if(pos >= 0)
                break;
            if(S[i] != S[0] && S[i + 1] != S[N - 1]){
                pos = i;
                break;
            }
        }
        int e = 0;
        int s = 0;
        for(int i = 0; i <= pos; ++i){
            if(S[i] == 'E')
                e++;
            if(S[i] == 'S')
                s++;
        }
        if(S[0] == 'S'){
            for(int i = 1; i <= e; ++i)
                cout << "E";
            for(int i = 1; i <= s; ++i)
                cout << "S";
        }
        else{
            for(int i = 1; i <= s; ++i)
                cout << "S";
            for(int i = 1; i <= e; ++i)
                cout << "E";
        }
        e = 0;
        s = 0;
        for(int i = pos + 1; i < N; ++i){
            if(S[i] == 'E')
                e++;
            if(S[i] == 'S')
                s++;
        }
        if(S[N - 1] == 'E'){
            for(int i = 1; i <= e; ++i)
                cout << "E";
            for(int i = 1; i <= s; ++i)
                cout << "S";
        }
        else{
            for(int i = 1; i <= s; ++i)
                cout << "S";
            for(int i = 1; i <= e; ++i)
                cout << "E";
        }
        cout << endl;
    }
    return 0;
}