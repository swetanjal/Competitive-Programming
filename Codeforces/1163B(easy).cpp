#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
int freq[15];
int main()
{
    cin >> N;
    int res = 0;
    for(int i = 1; i <= N; ++i){
        int tmp;
        cin >> tmp;
        freq[tmp]++;
        vector <int> lol;
        for(int j = 1; j <= 10; ++j)
        {
            if(freq[j] > 0)
                lol.push_back(freq[j]);
        }
        sort(lol.begin(), lol.end());
        if(lol.size() == 1)
            res = i;
        else{
            if((lol[0] == 1 && (lol[1] == lol[lol.size() - 1])) || (lol[lol.size() - 1] == (lol[lol.size() - 2] + 1) && (lol[0] == lol[lol.size() - 2])))
                res = i; 
        }
    }
    cout << res << endl;
    return 0;
}