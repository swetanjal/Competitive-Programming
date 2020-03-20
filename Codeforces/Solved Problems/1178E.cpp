#include "bits/stdc++.h"
using namespace std;
string S;
int L;
vector <char> st, en;
void rec(int l, int r)
{
    if(r == l){
        st.push_back(S[l]);
        return;
    }
    if(r < l)
        return;
    if((r - l + 1) == 2){
        st.push_back(S[l]);
        return;
    }
    if((r - l + 1) == 3){
        st.push_back(S[l]);
        return;
    }
    if(S[l] == S[r])
    {
        st.push_back(S[l]);
        en.push_back(S[r]);
    }
    else if(S[l] == S[r - 1]){
        st.push_back(S[l]);
        en.push_back(S[r - 1]);
    }
    else if(S[l + 1] == S[r]){
        st.push_back(S[l + 1]);
        en.push_back(S[r]);
    }
    else if(S[l + 1] == S[r - 1]){
        st.push_back(S[l + 1]);
        en.push_back(S[r - 1]);
    } 
    rec(l + 2, r - 2);
}

int main()
{
    cin >> S;
    L = S.size();
    rec(0, L - 1);
    for(int i = 0; i < st.size(); ++i)
        cout << st[i];
    for(int i = en.size() - 1; i >= 0; --i)
        cout << en[i];
    cout << endl;
    return 0;
}