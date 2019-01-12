#include "bits/stdc++.h"
using namespace std;

int main()
{
    string S;
    cin >> S;
    int L = S.size();
    int K;
    cin >> K;
    int cnt = 0;
    for(int i = 0; i < L; ++i){
        if(S[i] == '*' || S[i] == '?')
            continue;
        else
            cnt++;
    }
    vector <char> ans;
    if(cnt == K){
        for(int i = 0; i < L; ++i){
            if(S[i] == '*' || S[i] == '?')
                continue;
            ans.push_back(S[i]);
        }
    }
    else if(cnt < K){
        for(int i = 0; i < L; ++i){
            if(S[i] == '*'){
                while(cnt < K){
                    ans.push_back(S[i - 1]);
                    cnt++;
                }
            }
            if(S[i] != '?' && S[i] != '*')
                ans.push_back(S[i]);
        }
    }
    else{
        for(int i = 0; i < L - 1; ++i){
            if(S[i] == '?' || S[i] == '*')
                continue;
            if(S[i + 1] == '?' || S[i + 1] == '*')
            {
                if(cnt > K)
                    cnt--;
                else
                    ans.push_back(S[i]);
            }
            else
                ans.push_back(S[i]);
        }
        if(S[L - 1] != '?' && S[L - 1] != '*')
            ans.push_back(S[L - 1]);
    }
    if(ans.size() == K)
    {
        for(int i = 0; i < K; ++i)
            cout << ans[i];
        cout << endl;
    }
    else
        cout << "Impossible" << endl;
    return 0;
}