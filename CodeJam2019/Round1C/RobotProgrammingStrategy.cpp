#include "bits/stdc++.h"
using namespace std;
const int MAXN = 500;
int T;
int N;
int g[3];
string A[MAXN];
int exists[MAXN];
char beat(char a, char b){
    if(b == 'R' && a == 'S')
        return true;
    if(b == 'S' && a == 'P'){
        return true;
    }
    if(b == 'P' && a == 'R')
        return true;
    return false;
}

int main()
{
    cin >> T;
    int cases = 1;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; ++i)
            exists[i] = 1;
        for(int i = 0; i < N; ++i){
            cin >> A[i];
        }
        string res = "";
        int impossible = 0;
        for(int i = 0; i < 500; ++i){
            for(int kkk = 0; kkk < 3; ++kkk)
                g[kkk] = 0;
            for(int j = 0; j < N; ++j){
                if(exists[j] && A[j][i % A[j].size()] == 'R')
                    g[0] = 1;
                else if(exists[j] && A[j][i % A[j].size()] == 'S')
                    g[1] = 1;
                else if(exists[j] && A[j][i % A[j].size()] == 'P')
                    g[2] = 1;
            }
            if(g[0] > 0 && g[1] > 0 && g[2] > 0)
            {
                impossible = 1;
                break;
            }
            if(g[0] > 0 && g[1] > 0){
                // R and S
                res = res + 'R';
            }
            else if(g[0] > 0 && g[2] > 0){
                // R and P
                res = res + 'P';
            }
            else if(g[1] > 0 && g[2] > 0){
                // S and P
                res = res + 'S';
            }
            else if(g[0] > 0){
                res = res + 'P';
            }
            else if(g[1] > 0){
                res = res + 'R';
            }
            else if(g[2] > 0){
                res = res + 'S';
            }
            char taken = res[res.size() - 1];
            for(int j = 0; j < N; ++j){
                if(exists[j] && beat(A[j][i % A[j].size()], taken)){
                    exists[j] = 0;
                }
            }
        }
        if(impossible)
            cout << "Case #" << cases << ": " << "IMPOSSIBLE" << endl;
        else
            cout << "Case #" << cases << ": " << res << endl;
        cases++;
    }
    return 0;
}