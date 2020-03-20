#include "bits/stdc++.h"
using namespace std;
int T, F;
int main()
{
    cin >> T >> F;
    while(T--){
        vector <int> S;
        string res = "";
        for(int i = 1; i <= 119; ++i)
            S.push_back(i);
        int taken[5];
        taken[0] = taken[1] = taken[2] = taken[3] = taken[4] = 0;
        for(int i = 1; i < 5; ++i){
            vector <int> A[5];
            for(int j = 0; j < S.size(); ++j){
                int idx = (S[j] - 1) * 5 + i;
                cout << idx << endl;
                char inp;
                cin >> inp;
                A[inp - 'A'].push_back(S[j]);
            }
            int prod = 1;
            for(int j = 2; j <= (5 - i); ++j)
                prod *= j;
            for(int j = 0; j < 5; ++j){
                if(A[j].size() < prod && taken[j] == 0){
                    S.clear();
                    for(int k = 0; k < A[j].size(); ++k)
                        S.push_back(A[j][k]);
                    res = res + (char)(65 + j);
                    taken[j] += 1;
                }
            }
        }
        int freq[5];
        freq[0] = freq[1] = freq[2] = freq[3] = freq[4] = 0;
        for(int i = 0; i < 4; ++i)
            freq[res[i] - 'A']++;
        for(int i = 0; i < 5; ++i){
            if(freq[i] == 0){
                res = res + (char)(65 + i);
                break;
            }
        }
        cout << res << endl;
        char response;
        cin >> response;
        if(response == 'Y'){
            continue;
        }
        else{
            break;
        }
    }    
    return 0;
}