#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int N;
char A[MAXN][MAXN];

bool valid(int i, int j){
    if(i < 0 || j < 0 || i >= N || j >= N)
        return false;
    if(A[i][j] == '.')
        return true;
    return false;
}

void fill(int i, int j){
    A[i][j] = 'X';
    A[i + 1][j] = 'X';
    A[i - 1][j] = 'X';
    A[i][j + 1] = 'X';
    A[i][j - 1] = 'X';
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> A[i][j];
    int flag = 1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(valid(i - 1, j) && valid(i + 1, j) && valid(i, j + 1) && valid(i, j - 1) && valid(i, j)){
                fill(i, j);
            }
        }
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j){
            if(A[i][j] == '.'){
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}