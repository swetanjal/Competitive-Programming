#include "bits/stdc++.h"
using namespace std;
const int MAXN = 4 * 10 + 5;
int N;
int X[MAXN];
int Y[MAXN];

int F(int rm, int x, int y, int len)
{
    int c = 0;
    for(int i = 0; i < N; ++i){
        if(i == rm)
            continue;
        if((X[i] == x && Y[i] >= y && Y[i] <= (y + len)) ||
        (X[i] == (x + len) && Y[i] >= y && Y[i] <= (y + len)) || 
        (Y[i] == y && X[i] >= x && X[i] <= (x + len)) || 
        (Y[i] == (y + len) && X[i] >= x && X[i] <= (x + len)))
            continue;
        c++;
    }
    return c;
}

int main()
{
    cin >> N;
    for(int i = 0; i < 4 * N + 1; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    N = 4 * N + 1;
    for(int i = 0; i < N; ++i){
        for(int x = 0; x <= 50; ++x){
            for(int y = 0; y <= 50; ++y)
            {
                for(int l = 1; l <= 50; ++l){
                    if(F(i, x, y, l) == 0){
                        //cout << F(i, x, y, l) << endl;
                        cout << X[i] << " " << Y[i] << endl;
                    }
                }
            }
        }
    }
    return 0;
}