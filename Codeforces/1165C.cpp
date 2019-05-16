#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <char> S;
    for(int i = 0; i < N; ++i){
        char ch;
        cin >> ch;
        S.push_back(ch);
    }
    for(int i = 0; i < S.size(); i += 2){
        if(i == (S.size() - 1)){
            S.erase(S.begin() + i);
            continue;
        }
        if(S[i] != S[i + 1])
            continue;
        while(S[i] == S[i + 1]){
            S.erase(S.begin() + i);
            if(i == (S.size() - 1)){
                S.erase(S.begin() + i);
                break;
            }
        }
    }   
    cout << (N - S.size()) << endl;
    for(int i = 0; i < S.size(); ++i)
        cout << S[i];
    cout << endl;
    return 0;
}