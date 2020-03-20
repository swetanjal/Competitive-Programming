#include "bits/stdc++.h"
using namespace std;
int T;
int main()
{
    cin >> T;
    while(T--)
    {
        string p;
        cin >> p;
        string hash;
        cin >> hash;
        int lp = p.size();
        int lh = hash.size();
        int F[26];
        for(int i = 0; i < 26; ++i)
            F[i] = 0;
        for(int i = 0; i < lp; ++i)
            F[p[i] - 'a']++;
        int yes = 0;
        
        for(int i = 0; i <= lh - lp; ++i)
        {
            int freq[26];
            int cnt = 0;
            for(int j = 0; j < 26; ++j)
                freq[j] = 0;
            for(int j = i; j < i + lp; ++j){
                freq[hash[j] - 'a']++;
            }
            for(int j = 0; j < 26; ++j){
                if(F[j] != freq[j])
                    cnt++;
            }
            if(cnt == 0)
            {
                yes = 1;
            }
        }
        if(yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}