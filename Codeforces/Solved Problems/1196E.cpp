#include "bits/stdc++.h"
using namespace std;
int Q, B, W;
map < pair <int, int> , int > vis;
vector <int> x;
vector <int> y;
int w, b;

bool is_valid(int X, int Y){
    if(X >= 1 && Y >= 1 && X <= 1e9 && Y <= 1e9)
        return true;
    return false;
}

void dfs(int row, int col)
{
    //cout << row << " " << col << endl;
    vis[{row, col}] = 1;
    x.push_back(row);
    y.push_back(col);
    if(((row + col) % 2) == 0){
        w++;
        for(int i = -1; i <= 1; ++i){
            for(int j = -1; j <= 1; ++j)
            {
                if(abs(i - j) > 1 || abs(i + j) > 1)
                    continue;
                if(b < B && is_valid(row + i, col + j) && vis.find({row + i, col + j}) == vis.end())
                    dfs(row + i, col + j);
            }
        }
    }
    else{
        b++;
        for(int i = -1; i <= 1; ++i){
            for(int j = -1; j <= 1; ++j)
            {
                if(abs(i - j) > 1 || abs(i + j) > 1)
                    continue;
                if(w < W && is_valid(row + i, col + j) && vis.find({row + i, col + j}) == vis.end())
                    dfs(row + i, col + j);
            }
        }
    }
}

int main()
{
    cin >> Q;
    while(Q--){
        w = 0; b = 0;
        vis.clear(); x.clear(); y.clear();
        cin >> B >> W;
        if(W <= B)
            dfs(50000001, 50000000);
        else
            dfs(50000000, 50000000);
        if(x.size() == (W + B)){
            cout << "YES\n";
            for(int i = 0; i < x.size(); ++i)
                cout << x[i] << " " << y[i] << endl;
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}