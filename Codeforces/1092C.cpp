#include "bits/stdc++.h"
using namespace std;

bool pref(string A, string B)
{
    int L = B.size();
    for(int i = 0; i < L; ++i)
    {
        if(A[i] != B[i])
            return false;
    }
    return true;
}

bool suf(string A, string B)
{
    int L = B.size();
    int cnt = A.size() - 1;
    for(int i = L - 1; i >= 0; i--)
    {
        if(B[i] != A[cnt--])
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    string A[(2 * N) - 2];
    vector <int> lol[N];
    string x = ""; string y = "";
    int pref_ind = -1; int suf_ind = -1;
    for(int i = 0; i < (2 * N) - 2; ++i)
    {
        cin >> A[i];
        if(x.size() == 0 && A[i].size() == N - 1){
            x = A[i];
            pref_ind = i;
        }
        else if(A[i].size() == N - 1)
        {    
            y = A[i];
            suf_ind = i;
        }
        lol[A[i].size()].push_back(i);
    }
    string s = x + y[N - 2];
    char res[(2 * N) - 2];
    int flag = 0;
    for(int i = 1; i < N; ++i){
        if(pref(s, A[lol[i][0]]) && suf(s, A[lol[i][1]]))
            res[lol[i][0]] = 'P', res[lol[i][1]] = 'S';
        else if(pref(s, A[lol[i][1]]) && suf(s, A[lol[i][0]]))
            res[lol[i][0]] = 'S', res[lol[i][1]] = 'P';
        else
        {
            flag = 1;
        }
    }
    if(flag)
    {
        s = y + x[N - 2];
        flag = 0;
        for(int i = 1; i < N; ++i){
            if(pref(s, A[lol[i][0]]) && suf(s, A[lol[i][1]]))
                res[lol[i][0]] = 'P', res[lol[i][1]] = 'S';
            else if(pref(s, A[lol[i][1]]) && suf(s, A[lol[i][0]]))
                res[lol[i][0]] = 'S', res[lol[i][1]] = 'P';
            else
            {
                flag = 1;
            }
        }    
    }
    assert(flag == 0);
    for(int i = 0; i < (2 * N) - 2; ++i)
    cout << res[i];
    cout << endl;
    return 0;
}