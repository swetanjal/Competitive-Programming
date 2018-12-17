#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    long long int A[105];
    for(int i = 0; i < 105; ++i)
        A[i] = 0;
    for(int i = 0; i <= 100; ++i){
        if(((i * 2)) > 100)break;
        for(int j = 0; j <= 100; ++j){
            if(((i * 2) + (j * 3)) > 100)break;
            for(int k = 0; k <= 100; ++k){
                if(((i * 2) + (j * 3) + (k * 4))> 100)break;
                for(int l = 0; l <= 100; ++l){
                    if(((i * 2) + (j * 3) + (k * 4) + (l * 5))> 100)break;
                    for(int m = 0; m <= 100; ++m){
                        if(((i * 2) + (j * 3) + (k * 4) + (l * 5) + (m * 6))> 100)break;
                        for(int n = 0; n <= 100; ++n){
                            if(((i * 2) + (j * 3) + (k * 4) + (l * 5) + (m * 6) + (n * 7))> 100)break;
                            A[(i * 2) + (j * 3) + (k * 4) + (l * 5) + (m * 6) + (n * 7)] = i + j + k + l + m + n;
                        }
                    }
                }
            }
        }
    }    
    while(T--)
    {
        int X;
        cin >> X;
        cout << A[X] << endl;
    }
    return 0;
}