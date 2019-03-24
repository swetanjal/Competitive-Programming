#include "bits/stdc++.h"
using namespace std;
string S;
int L;
int A[4][4];
void chk()
{
    for(int i = 0; i < 4; ++i)
    if(A[i][0] == 1 && A[i][1] == 1 && A[i][2] == 1 && A[i][3] == 1)
        A[i][0] = A[i][1] = A[i][2] = A[i][3] = 0;
}

int main()
{
    cin >> S;
    L = S.size();
    for(int i = 0; i < L; ++i){
        chk();
        if(S[i] == '0'){
            if(A[0][0] == 0){
                A[0][0] = 1;
                A[1][0] = 1;
                cout << "1 1\n";
            }
            else if(A[0][1] == 0){
                A[0][1] = 1;
                A[1][1] = 1;
                cout << "1 2\n";
            }
            else if(A[0][2] == 0){
                A[0][2] = 1;
                A[1][2] = 1;
                cout << "1 3\n";
            }
            else{
                A[0][3] = 1;
                A[1][3] = 1;
                cout << "1 4\n";
            }
        }
        else{
            if(A[2][0] == 0){
                A[2][0] = A[2][1] = 1;
                cout << "3 1\n";
            }
            else{
                A[2][2] = A[2][3] = 1;
                cout << "3 3\n";
            }
        }
    }
    return 0;
}