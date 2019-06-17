#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e4 + 5;
int T, N, R, C, SR, SC;
map < pair <int, int>, int > H;
int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        H.clear();
        cin >> N >> R >> C >> SR >> SC;
        H[{SR, SC}] = 1;
        for(int i = 1; i <= N; ++i){
            char ch;
            cin >> ch;
            if(ch == 'N'){
                SR -= 1;
                while(H.find({SR, SC}) != H.end()){
                    SR -= 1;
                }
            }
            else if(ch == 'S'){
                SR += 1;
                while(H.find({SR, SC}) != H.end()){
                    SR += 1;
                }
            }
            else if(ch == 'W'){
                SC -= 1;
                while(H.find({SR, SC}) != H.end()){
                    SC -= 1;
                }
            }
            else if(ch == 'E'){
                SC += 1;
                while(H.find({SR, SC}) != H.end()){
                    SC += 1;
                }
            }
            H[{SR, SC}] = 1;
        }
        cout << "Case #" << cases << ": " << SR << " " << SC << endl;
    }
}