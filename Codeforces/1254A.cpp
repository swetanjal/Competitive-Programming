#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e2 + 5;
int N, M, K;
char A[MAXN][MAXN];

char get(int s)
{
    if(s >= 0 && s <= 9)
        return (char)(48 + s);
    if(s >= 10 && s <= (10 + 26 - 1))
        return (char)(65 + s - 10);
    return (char)(97 + s - 36);
}

void solve()
{
    cin >> N >> M >> K;
    int R = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
            if(A[i][j] == 'R')
                R++;
        }
    }
    int setA = R / K;
    int cntA = K;
    int setB = setA + 1;
    int cntB = 0;
    cntB += (R % K);
    cntA -= (R % K);
    int k = 0;
    int running = 0;
    for(int i = 0; i < N; ++i){

        if((i % 2) == 0)
        {
            for(int j = 0; j < M; ++j){
                if(running == setB && cntB > 0)
                {
                    running = 0;
                    cntB--;
                    k++;
                    if(k == K)
                        k--;
                }
                else if(running == setA && cntA > 0 && cntB == 0)
                {
                    running = 0;
                    cntA--;
                    k++;
                    if(k == K)
                        k--;
                }
                if(A[i][j] == 'R')
                    running++;
                A[i][j] = get(k);
            }
        }
        else{
            for(int j = (M - 1); j >= 0; --j)
            {
                if(running == setB && cntB > 0)
                {
                    running = 0;
                    cntB--;
                    k++;
                    if(k == K)
                        k--;
                }
                else if(running == setA && cntA > 0 && cntB == 0)
                {
                    running = 0;
                    cntA--;
                    k++;
                    if(k == K)
                        k--;
                }
                if(A[i][j] == 'R')
                    running++;
                A[i][j] = get(k);
            }
        }
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
            cout << A[i][j];
        cout << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();    
    }
    return 0;
}