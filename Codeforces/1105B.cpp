#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N, K;
char S[MAXN];

bool chk(int V, char ch)
{
    int res = 0;
    for(int i = 0; i < N; ++i){
        int matched_till = -1;
        for(int j = i; j < min(N, i + K); ++j)
        {
            if(ch == S[j]){
                matched_till = j;
                continue;
            }
            else
                break;
        }
        if((matched_till - i + 1) == K)
            res++;
        if(matched_till == -1)
            i = i;
        else
            i = matched_till;
    }
    if(res >= V)
        return true;
    return false;
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> S[i];
    int low = 0; int high = 2e5 + 5;
    int mid;
    int pos = -1;
    while(high >= low)
    {
        mid = (high + low) / 2;
        int flag = 0;
        for(int i = 0; i < 26; ++i)
            flag |= chk(mid, (char)(97 + i));
        if(flag){
            pos = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << pos << endl;
    return 0;
}