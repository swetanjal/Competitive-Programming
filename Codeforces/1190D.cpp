#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree< pair <int, int> , null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update> 

int N;
priority_queue < pair < int, int > , vector < pair <int, int> >, greater < pair <int, int> > > P;
ordered_set S;
map <int, int> H;
long long last_x = -1;
int c;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        if(H.find(x) == H.end())
        {
            S.insert({x, y});
            H[x] = y;
            c++;
        }
        else{
            if(H[x] < y){
                S.erase(S.find({x, H[x]}));
                H[x] = y;
                S.insert({x, H[x]});
            }
        }
        P.push({y, x});
    }
    long long res = c * 1LL * (c + 1) / 2;
    while(P.empty() == false){
        vector <int> V;
        vector <int> cum;
        vector <int> flag;
        int y_coord = P.top().first;

        while(P.empty() == false && P.top().first == y_coord){
            pair <int, int> p = {P.top().second, P.top().first};
            P.pop();
            S.erase(S.find(p));
            int tam = S.order_of_key(p);
            V.push_back(tam);
            if(S.find({p.first, H[p.first]}) != S.end())
                flag.push_back(1);
            else
                flag.push_back(0);
        }
        int LA = 0;
        int L = V.size();
        for(int i = 0; i < L; ++i){
            res = res + (V[i] - LA + flag[i]) * 1LL * (S.size() - V[i]);
            LA = V[i] + flag[i];
        }
    }
    cout << res << endl;
    return 0;
}