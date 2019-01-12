#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
int N;
int main()
{
    cin >> N;
    int zero = 0;
    int one = 0;
    int two = 0;
    char A[N];
    for(int i = 0; i < N; ++i){
        char ch;
        cin >> ch;
        A[i] = ch;
        if(ch == '0')
            zero++;
        if(ch == '1')
            one++;
        if(ch == '2')
            two++;
    }
    for(int i = 0; i < N; ++i){
        if(A[i] == '0'){
            continue;
        }
        if(A[i] == '1'){
            if(zero < (N / 3) && one > (N / 3))
            {
                zero++;
                one--;
                A[i] = '0';
            }
        }
        if(A[i] == '2'){
            if(zero < (N / 3) && two > (N / 3)){
                zero++;
                two--;
                A[i] = '0';
            }
            else if(one < (N / 3) && two > (N / 3)){
                A[i] = '1';
                one++;
                two--;
            }
        }
    }
    for(int i = (N - 1); i >= 0; --i){
        if(A[i] == '0'){
            if(zero > (N / 3) && two < (N / 3)){
                A[i] = '2';
                zero--;
                two++;
            }
            else if(zero > (N / 3) && one < (N / 3)){
                A[i] = '1';
                zero--;
                one++;
            }
        }
        else if(A[i] == '1'){
            if(one > (N / 3) && two < (N / 3))
            {
                A[i] = '2';
                one--;
                two++;
            }
        }
        else if(A[i] == '2'){
            continue;
        }
    }
    for(int i = 0; i < N; ++i)
        cout << A[i];
    cout << endl;
    return 0;
}