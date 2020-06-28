#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        if(N == 2){
            cout << "-1\n";
        }
        else if(N == 3){
            cout << "-1\n";
        }
        else if((N % 2) == 0){
            for(int i = 2; i <= N; i += 2)
                cout << i << " ";
            cout << (N - 3) << " " << (N - 1) << " ";
            for(int i = (N - 5); i >= 1; i -= 2)
                cout << i << " ";
            cout << endl;
        }
        else{
            for(int i = 1; i <= N; i += 2)
                cout << i << " ";
            cout << (N - 3) << " " << (N - 1) << " ";
            for(int i = (N - 5); i >= 1; i -= 2)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}