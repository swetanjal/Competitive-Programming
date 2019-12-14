#include "bits/stdc++.h"
using namespace std;
int T, N, R, C, SR, SC;
map < pair <int, int> , pair <int, int> > e;
map < pair <int, int> , pair <int, int> > w;
map < pair <int, int> , pair <int, int> > n;
map < pair <int, int> , pair <int, int> > s;

void fill(int row, int col)
{
    // East
    pair <int, int> p = {row, col + 1};
    if(e.find(p) != e.end())
        e[{row, col}] = e[p];
    else
        e[{row, col}] = p;
    // West
    p = {row, col - 1};
    if(w.find(p) != w.end())
        w[{row, col}] = w[p];
    else
        w[{row, col}] = p;
    // North
    p = {row - 1, col};
    if(n.find(p) != n.end())
        n[{row, col}] = n[p];
    else
        n[{row, col}] = p;
    // South
    p = {row + 1, col};
    if(s.find(p) != s.end())
        s[{row, col}] = s[p];
    else
        s[{row, col}] = p;
}


int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> N >> R >> C >> SR >> SC;
        e.clear(); w.clear(); n.clear(); s.clear();
        e[{SR, SC}] = {SR,SC + 1}; w[{SR, SC}] = {SR,SC - 1};
        s[{SR, SC}] = {SR + 1, SC}; n[{SR, SC}] = {SR - 1, SC};
        for(int i = 1; i <= N; ++i){
            char ch;
            cin >> ch;
            if(ch == 'N'){
                SR -= 1;
                if(e.find({SR, SC}) == e.end()){
                    // Do the required filling
                    fill(SR, SC);
                }
                else{
                    int tmp_SR = n[{SR, SC}].first;
                    int tmp_SC = n[{SR, SC}].second;
                    SR = tmp_SR;
                    SC = tmp_SC;
                    // Do the required filling
                    fill(SR, SC);
                }
            }
            else if(ch == 'S'){
                SR += 1;
                if(e.find({SR, SC}) == e.end()){
                    // Do the required filling
                    fill(SR, SC);
                }
                else{
                    int tmp_SR = s[{SR, SC}].first;
                    int tmp_SC = s[{SR, SC}].second;
                    SR = tmp_SR;
                    SC = tmp_SC;
                    // Do the required filling
                    fill(SR, SC);
                }
            }
            else if(ch == 'E'){
                SC += 1;
                if(e.find({SR, SC}) == e.end()){
                    // Do the required filling
                    fill(SR, SC);
                }
                else{
                    int tmp_SR = e[{SR, SC}].first;
                    int tmp_SC = e[{SR, SC}].second;
                    SR = tmp_SR;
                    SC = tmp_SC;
                    // Do the required filling
                    fill(SR, SC);
                }
            }
            else if(ch == 'W'){
                SC -= 1;
                if(e.find({SR, SC}) == e.end()){
                    // Do the required filling
                    fill(SR, SC);
                }
                else{
                    int tmp_SR = w[{SR, SC}].first;
                    int tmp_SC = w[{SR, SC}].second;
                    SR = tmp_SR;
                    SC = tmp_SC;
                    // Do the required filling
                    fill(SR, SC);
                }
            }
            cout << SR << " " << SC << endl;
        }
        cout << SR << " " << SC << endl;
    }
    return 0;
}