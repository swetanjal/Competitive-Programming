#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
map <int, int> H;
int zero_front;
int zero_back;
int N;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        string S;
        cin >> S;
        int L = S.size();
        int f = 0;
        for(int j = 0; j < L; ++j)
        {
            if(S[j] == '(')
                f++;
            else
                f--;
        }
        if(f > 0){
            int ok = 1;
            int lol = 0;
            for(int j = 0; j < L; ++j){
                if(S[j] == '(')
                    lol++;
                else
                    lol--;
                if(lol < 0)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                if(H.find(f) != H.end())
                    H[f]++;
                else
                    H[f] = 1;
            }
        }
        else if(f < 0){
            int ok = 1;
            int lol = 0;
            for(int j = L - 1; j >= 0; --j){
                if(S[j] == '(')
                    lol++;
                else
                    lol--;
                if(lol > 0)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                if(H.find(f) != H.end())
                    H[f]++;
                else
                    H[f] = 1;
            }
        }
        else{
            int lol = 0;
            int front = 1;
            for(int j = 0; j < L; ++j){
                if(S[j] == '(')
                    lol++;
                else
                    lol--;
                if(lol < 0){
                    front = 0;
                    break;
                }
            }
            if(front)
                zero_front++;
            else
                zero_back++;
        }
    }    
    long long int res = 0;
    for(int i = 1; i <= 500000; ++i){
        if(H.find(i) != H.end() && H.find(-i) != H.end())
        {
            res += min(H[i], H[-i]);
        }
    }
    res = res + (zero_front / 2);
    cout << res << endl;
    return 0;
}