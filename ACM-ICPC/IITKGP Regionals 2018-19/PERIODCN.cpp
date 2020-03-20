#include "bits/stdc++.h"
using namespace std;
long long int L, R, T;
set <long long int> A;
vector <long long> S;
int start_idx()
{
    int low = 0; int high = S.size() - 1;
    int mid; int pos = -1;
    while(high >= low)
    {
        mid = (high + low) / 2;
        if(S[mid] >= L)
        {
            pos = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return pos;
}

int end_idx()
{
    int low = 0; int high = S.size() - 1;
    int mid; int pos = -1;
    while(high >= low)
    {
        mid = (high + low) / 2;
        if(S[mid] <= R)
        {
            pos = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return pos;
}

int main()
{
    for(int i = 1; i <= 30; ++i){
        for(int j = 30; j - i + 1 >= 0; j--)
        {
            if(((j + 1) % i) != 0)
                continue;
            int curr = 1;
            int cnt = 0;
            long long ans = 0;
            for(int k = j; k >= 0; k--){
                if(cnt == i){
                    curr = 1 - curr;
                    cnt = 0;
                }
                cnt++;
                if(curr == 1)
                    ans = ans + (1LL << k);
            }
            A.insert(ans);
        }
    }
    set <long long> :: iterator it;
    for(it = A.begin(); it != A.end(); ++it)
        S.push_back(*it);
    cin >> T;
    while(T--)
    {
        cin >> L >> R;
        int st = start_idx();
        int en = end_idx();
        if(st > en)
            cout << "0\n";
        else
            cout << (en - st + 1) << endl;
    }
    return 0;
}