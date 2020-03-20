#include "bits/stdc++.h"
using namespace std;
int T, N;
map <long long, pair <int, int > > H;
priority_queue < pair< int, int> > P;
priority_queue < int > Q;
map <long long, pair <int, int> > :: iterator it;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        H.clear();
        for(int i = 0; i < N; ++i){
            long long tmp;
            int f = 1;
            cin >> tmp >> f;
            if(H.find(tmp) != H.end())
                H[tmp] = {H[tmp].first + 1, H[tmp].second + f};
            else
                H[tmp] = {1, f};
        }
        for(it = H.begin(); it != H.end(); ++it){
            P.push({(it->second).first, (it->second).second});
        }
        long long res = 1000000000;
        long long ans = 0;
        long long ans2 = 0;
        while((P.empty()==false) || (Q.empty() == false)){
            long long r;
            if(P.empty() == false){
                if(Q.empty() == false)
                    r = max(0LL, max(res, P.top().first * 1LL));
                else
                    r = max(0LL, min(res, P.top().first * 1LL));
            }
            else
                r = max(0LL, res);
            while(P.empty() == false && P.top().first >= r){
                //pair <int, int> y = P.top();
                //y.first = r;
                Q.push(P.top().second);
                P.pop();
            }
            //cout << Q.size() << endl;
            long long l = Q.top();
            Q.pop();
            ans = ans + r;
            ans2 = ans2 + min(r, l);
            res = r - 1;
        }
        cout << ans << " " << ans2 << endl;
    }
    return 0;
}