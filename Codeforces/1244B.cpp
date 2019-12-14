#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int a = INT_MAX;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1')
                a = min(min(i, n - 1 - i), a);
            
        }
        if(a == INT_MAX)
            cout << n << endl;
        else
            cout << 2 * (n - a) << endl;
        
    }
    return 0;
}