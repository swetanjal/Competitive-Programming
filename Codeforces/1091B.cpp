#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e3 + 5;
int N;
map <pair < int, int>, int >  H;
long long int X[MAXN];
long long int Y[MAXN];
long long cx[MAXN];
long long cy[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        cx[i] = x;
        cy[i] = y;
        H[make_pair(x, y)] = 1;
    }
    for(int i = 0; i < N; ++i){
        cin >> X[i] >> Y[i];
    }
    for(int i = 0; i < N; ++i){
        long long Tx = X[0] + cx[i];
        long long Ty = Y[0] + cy[i];
        int fl = 1;
        for(int j = 0; j < N; ++j){
            if(H.find(make_pair(Tx - X[j], Ty - Y[j])) == H.end()){
                fl = 0;
                break;
            }
        }
        if(fl){
            cout << Tx << " " << Ty << endl;
            return 0;
        }
    }
    return 0;
}