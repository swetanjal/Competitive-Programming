#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
set <pair <int, int> > S;
int freq[MAXN];
int main()
{
    cin >> N;
    int res = 0;
    //for(int i = 1; i <= 10; ++i)
    //    S.insert({i, 0});
    for(int i = 1; i <= N; ++i){
        int tmp;
        cin >> tmp;
        freq[tmp]++;
        if(freq[tmp] > 1)
            S.erase(S.find({freq[tmp] - 1, tmp}));
        S.insert({freq[tmp], tmp});
        if(S.size() == 1)
            res = i;
        else{
            //if((lol[0] == 1 && (lol[1] == lol[lol.size() - 1])) || (lol[lol.size() - 1] == (lol[lol.size() - 2] + 1) && (lol[0] == lol[lol.size() - 2])))
            //    res = i;
            pair <int, int> lol0 = *(S.begin());
            set < pair <int, int> > :: iterator it;
            it = S.begin();
            ++it;
            pair <int, int> lol1 = *(it);
            it = S.end();
            --it;
            pair <int, int> lolend = *(it); 
            --it;
            pair <int, int> lolbend = *(it);
            if((lol0.first == 1 && (lol1.first == lolend.first)) || (lolend.first == (lolbend.first + 1) && lol0.first == lolbend.first))
                res = i;
            //for(it = S.begin(); it!=S.end(); ++it){
            //    cout << (*it).first << " ";
            //}
            //cout << endl;
        }
    }
    cout << res << endl;
    return 0;
}