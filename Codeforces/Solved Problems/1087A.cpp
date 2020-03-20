#include "bits/stdc++.h"
using namespace std;

int main()
{
    string S;
    cin >> S;
    int L = S.size();
    string ans = "";
    int left_ptr = 0; int right_ptr = L - 1;
    int cnt = 0;
    int mod = 0;
    if((L % 2) != 0)
        mod = 1;
    while(cnt != L)
    {
        if((cnt % 2) == mod){
            ans = S[right_ptr--] + ans;
        }
        else
        {
            ans = S[left_ptr++] + ans;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}