#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int l = s.size();
        int zeros = 0;
        int sum = 0;
        int mod2 = 0;
        for(int i = 0; i < l; ++i){
            sum = sum + (s[i] - '0');
            if(s[i] == '0')
                zeros++;
            if(((s[i] - '0') % 2) == 0)
                mod2++;
        }
        if(zeros > 0 && (sum % 3) == 0 && mod2 >= 2)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
    return 0;
}