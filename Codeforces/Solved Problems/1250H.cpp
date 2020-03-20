#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A[10] = {0};
        for(int i = 0; i <= 9; ++i)
            cin >> A[i];
        int pos = -1; int mi = 100000000;
        for(int i = 0; i <= 9; ++i){
            if(A[i] < mi){
                mi = A[i];
                pos = i;
            }
        }
        if(pos != 0){
            for(int i = 0; i <= mi; ++i)
                cout << pos;
            cout << endl;
        }
        else{
            int n = -1;
            for(int i = 1; i <= 9; ++i){
                if(mi == A[i]){
                    n = i;
                    break;
                }
            }
            //cout << n << endl;
            if(n != -1){
                for(int i = 0; i <= mi; ++i)
                    cout << n;
                cout << endl;
            }
            else{
                for(int i = 1; i <= 9; ++i){
                    if(A[i] > 0){
                        n = i;
                        break;
                    }
                }
                cout << n;
                for(int i = 0; i <= mi; ++i)
                    cout << "0";
                cout << endl;
            }
        }
    }
    return 0;
}